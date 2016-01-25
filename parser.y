/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Float 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_And T_Or 
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_Inc T_Dec T_Switch T_Case T_Default

/* Added tokens */
%token   T_LeftParen T_RightParen T_LeftBracket T_RightBracket
%token   T_Dot T_FieldSelection
%token   T_Uint
%token   T_Bvec2 T_Bvec3 T_Bvec4
%token   T_Ivec2 T_Ivec3 T_Ivec4
%token   T_Uvec2 T_Uvec3 T_Uvec4
%token   T_Vec2 T_Vec3 T_Vec4
%token   T_Mat2 T_Mat3 T_Mat4
%token   T_Struct
%token   T_In T_Out T_Inout
%token   T_Const T_Uniform
%token   T_Layout
%token   T_Continue T_Do T_Return


/* These were already here */
%token   <identifier> T_Identifier
%token   <integerConstant> T_IntConstant
%token   <floatConstant> T_FloatConstant
%token   <boolConstant> T_BoolConstant


/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>  DeclList 
%type <decl>      Decl VarIdent PrimExpr PostExpr IntExpr 
%type <decl>      FunctCall FunctCallOrMethod FunctCallGeneric

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 */
Program   :    DeclList                           { 
                                                    @1; 
                                                    /* pp2: The @1 is needed to convince 
                                                     * yacc to set up yylloc. You can remove 
                                                     * it once you have other uses of @n*/
                                                    Program *program = new Program($1);
                                                    // if no errors, advance to next phase
                                                    if (ReportError::NumErrors() == 0) 
                                                        program->Print(0);
                                                  }   
          ;

DeclList  :    DeclList Decl                      { ($$=$1)->Append($2); }
          |    Decl                               { ($$ = new List<Decl*>)->Append($1); }
          ;

Decl      :    VarIdent                           { $$=$1; }
          |    PrimExpr                           { $$=$1; }
          |    PostExpr                           { $$=$1; }
          ;
          
VarIdent  :    T_Identifier                       { $$ = new VarDecl(); 
                                                    printf("Got it!");
                                                  }
          ;

PrimExpr  :    VarIdent                           { $$=$1; }
          |    T_IntConstant                      { $$ = new VarDecl(); }
          |    T_FloatConstant                    { $$ = new VarDecl(); }
          |    T_BoolConstant                     { $$ = new VarDecl(); }
          // |    T_LeftParen Expr T_RightParen      { $$ = new VarDecl(); }
          ;

PostExpr  :    PrimExpr                           { $$=$1; }
          |    PostExpr T_LeftBracket IntExpr 
               T_RightBracket                     {
                                                    $$ = new VarDecl();       
                                                  } 
          |    FunctCall                          { $$=$1; }
          |    PostExpr T_Dot T_FieldSelection    { $$=$1; }
          |    PostExpr T_Inc                     { $$=$1; }  
          |    PostExpr T_Dec                     { $$=$1; }  
          ;

IntExpr   :    Expr                               { $$=$1; }
          ;

FunctCall :    FunctCallOrMethod                  { $$=$1; }
          ;

FunctCallOrMethod : FunctCallGeneric              { $$=$1; }
                  ;

function_call_generic:
function_call_header_with_parameters RIGHT_PAREN
function_call_header_no_parameters RIGHT_PAREN

function_call_header_no_parameters:
function_call_header VOID
function_call_header

function_call_header_with_parameters:
function_call_header assignment_expression
function_call_header_with_parameters COMMA assignment_expression

function_call_header:
function_identifier LEFT_PAREN 

function_identifier:
type_specifier
postfix_expression

unary_expression:
postfix_expression
INC_OP unary_expression
DEC_OP unary_expression
unary_operator unary_expression

unary_operator:
PLUS
DASH
BANG
TILDE

multiplicative_expression:
unary_expression
multiplicative_expression STAR unary_expression
multiplicative_expression SLASH unary_expression
multiplicative_expression PERCENT unary_expression
additive_expression:
multiplicative_expression
additive_expression PLUS multiplicative_expression
additive_expression DASH multiplicative_expression

shift_expression:
additive_expression
shift_expression LEFT_OP additive_expression
shift_expression RIGHT_OP additive_expression

relational_expression:
shift_expression
relational_expression LEFT_ANGLE shift_expression
relational_expression RIGHT_ANGLE shift_expression
relational_expression LE_OP shift_expression
relational_expression GE_OP shift_expression 

equality_expression:
relational_expression
equality_expression EQ_OP relational_expression
equality_expression NE_OP relational_expression

and_expression:
equality_expression
and_expression AMPERSAND equality_expression

exclusive_or_expression:
and_expression
exclusive_or_expression CARET and_expression

inclusive_or_expression:
exclusive_or_expression
inclusive_or_expression VERTICAL_BAR exclusive_or_expression

logical_and_expression:
inclusive_or_expression
logical_and_expression AND_OP inclusive_or_expression

logical_xor_expression:
logical_and_expression
logical_xor_expression XOR_OP logical_and_expression

logical_or_expression:
logical_xor_expression
logical_or_expression OR_OP logical_xor_expression

conditional_expression:
logical_or_expression
logical_or_expression QUESTION expression COLON assignment_expression

assignment_expression:
conditional_expression
unary_expression assignment_operator assignment_expression

assignment_operator:
EQUAL
MUL_ASSIGN
DIV_ASSIGN
MOD_ASSIGN
ADD_ASSIGN
SUB_ASSIGN
LEFT_ASSIGN
RIGHT_ASSIGN
AND_ASSIGN
XOR_ASSIGN
OR_ASSIGN

expression:
assignment_expression
expression COMMA assignment_expression

constant_expression:
conditional_expression

declaration:
function_prototype SEMICOLON
init_declarator_list SEMICOLON
PRECISION precision_qualifier type_specifier SEMICOLON
type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
type_qualifier SEMICOLON
type_qualifier IDENTIFIER SEMICOLON // e.g. to qualify an existing variable as invariant
type_qualifier IDENTIFIER identifier_list SEMICOLON

identifier_list:
COMMA IDENTIFIER
identifier_list COMMA IDENTIFIER

function_prototype:
function_declarator RIGHT_PAREN

function_declarator:
function_header
function_header_with_parameters

function_header_with_parameters:
function_header parameter_declaration
function_header_with_parameters COMMA parameter_declaration

function_header:
fully_specified_type IDENTIFIER LEFT_PAREN

parameter_declarator:
type_specifier IDENTIFIER
type_specifier IDENTIFIER array_specifier

parameter_declaration:
type_qualifier parameter_declarator
parameter_declarator
type_qualifier parameter_type_specifier
parameter_type_specifier

parameter_type_specifier:
type_specifier

init_declarator_list:
single_declaration
init_declarator_list COMMA IDENTIFIER
init_declarator_list COMMA IDENTIFIER array_specifier
init_declarator_list COMMA IDENTIFIER array_specifier EQUAL initializer
init_declarator_list COMMA IDENTIFIER EQUAL initializer

single_declaration:
fully_specified_type
fully_specified_type IDENTIFIER
fully_specified_type IDENTIFIER array_specifier
fully_specified_type IDENTIFIER array_specifier EQUAL initializer
fully_specified_type IDENTIFIER EQUAL initializer

fully_specified_type:
type_specifier
type_qualifier type_specifier

invariant_qualifier:
INVARIANT

interpolation_qualifier:
SMOOTH
FLAT

layout_qualifier:
LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN

layout_qualifier_id_list:
layout_qualifier_id
layout_qualifier_id_list COMMA layout_qualifier_id

layout_qualifier_id:
IDENTIFIER
IDENTIFIER EQUAL INTCONSTANT
IDENTIFIER EQUAL UINTCONSTANT
SHARED

precise_qualifier:
PRECISE

type_qualifier:
single_type_qualifier
type_qualifier single_type_qualifier

single_type_qualifier:
storage_qualifier
layout_qualifier
precision_qualifier
interpolation_qualifier
invariant_qualifier
precise_qualifier

storage_qualifier:
CONST
IN
OUT
INOUT
CENTROID
PATCH
SAMPLE
UNIFORM
BUFFER
SHARED
COHERENT
VOLATILE
RESTRICT
READONLY
WRITEONLY

type_specifier:
type_specifier_nonarray
type_specifier_nonarray array_specifier

array_specifier:
LEFT_BRACKET RIGHT_BRACKET
LEFT_BRACKET constant_expression RIGHT_BRACKET
array_specifier LEFT_BRACKET RIGHT_BRACKET
array_specifier LEFT_BRACKET constant_expression RIGHT_BRACKET

Type_Specifier_Nonarray : T_Void                  { $$=$1; }
                        | T_Float                 { $$=$1; }
                        | T_Int                   { $$=$1; }
                        | T_Uint                  { $$=$1; }
                        | T_Bool                  { $$=$1; }
                        | T_Vec2                  { $$=$1; }
                        | T_Vec3                  { $$=$1; }
                        | T_Vec4                  { $$=$1; }
                        | T_Bvec2                  { $$=$1; }
                        | T_Bvec3                  { $$=$1; }
                        | T_Bvec4                  { $$=$1; }
                        | T_Ivec2                  { $$=$1; }
                        | T_Ivec3                  { $$=$1; }
                        | T_Ivec4                  { $$=$1; }
                        | T_Uvec2                  { $$=$1; }
                        | T_Uvec3                  { $$=$1; }
                        | T_Uvec4                  { $$=$1; }
                        | T_Mat2                  { $$=$1; }
                        | T_Mat3                  { $$=$1; }
                        | T_Mat4                  { $$=$1; }
                        | struct_specifier        { $$=$1; }
                        ;

precision_qualifier:
HIGH_PRECISION
MEDIUM_PRECISION
LOW_PRECISION

struct_specifier:
STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE

struct_declaration_list:
struct_declaration
struct_declaration_list struct_declaration

struct_declaration:
type_specifier struct_declarator_list SEMICOLON
type_qualifier type_specifier struct_declarator_list SEMICOLON

Struct_Declarator_List : Struct_Declarator { $$=$1; }
                       | T_Identifier { $$=$1; }
                       | T_Identifier Array_Specifier { $$=$1; }
                       ;

Initializer : Assignment_Expression { $$=$1; }
            ;

Declaration_Statement: Declaration { $$=$1; }
            ;

Statement : Compund_Statement_With_Scope { $$=$1; }
          | Simple_Statement { $$=$1; }
          ;

Statement_No_New_Scope : Compound_Statement_No_New_Scope { $$=$1; }
                       | Simple_Statement { $$=$1; }
                       ;

Statement_With_Scope : Compund_Statement_With_Scope { $$=$1; }
                     | Simple_Statement { $$=$1; }
                     ;

Simple_Statement : Declaration_Statement { $$=$1; }
                | Expression_Statement { $$=$1; }
                | Selection_Statement { $$=$1; }
                | Switch_Statement { $$=$1; }
                | Case_Label { $$=$1; }
                | Iteration_Statement { $$=$1; }
                | Jump_Statement { $$=$1; }
                ;

compound_statement_with_scope : LEFT_BRACE RIGHT_BRACE
                              | LEFT_BRACE statement_list RIGHT_BRACE
                              ;

compound_statement_no_new_scope:
LEFT_BRACE RIGHT_BRACE
LEFT_BRACE statement_list RIGHT_BRACE

statement_list:
statement
statement_list statement

expression_statement:
SEMICOLON
expression SEMICOLON

selection_statement:
IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement

selection_rest_statement:
statement_with_scope ELSE statement_with_scope
statement_with_scope

condition:
expression
fully_specified_type IDENTIFIER EQUAL initializer

switch_statement:
SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list
 RIGHT_BRACE

switch_statement_list:
/* nothing */
statement_list

case_label:
CASE expression COLON
DEFAULT COLON

iteration_statement:
WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
DO statement_with_scope WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN
 statement_no_new_scope

for_init_statement:
expression_statement
declaration_statement

conditionopt:
condition
/* empty */

for_rest_statement:
conditionopt SEMICOLON
conditionopt SEMICOLON expression

jump_statement:
CONTINUE SEMICOLON
BREAK SEMICOLON
RETURN SEMICOLON
RETURN expression SEMICOLON
DISCARD SEMICOLON



Translation_Unit : External_Declaration { $$=$1; }
                 | Translation_Unit External_Declaration { $$=$1; }
                 ;

External_Declaration : Function_Definition { $$=$1; }
                     | Declaration { $$=$1; }
                     ;

Function_Definition : Function_Prototype { $$=$1; }
                    | Compound_Statement_No_New_Scope { $$=$1; }
                    ;

// Expr      :     
//           ;

%%

/*
Decl      :    T_Void               { $$ = new VarDecl(); pp2: test only. Replace with correct rules  } 
          ;
*/

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
