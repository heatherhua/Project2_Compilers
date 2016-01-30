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
    double floatConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    Type *type;
    AssignExpr *assignExpr;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Float 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_AndOp T_OrOp 
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_Inc T_Dec T_Switch T_Case T_Default

/* Added tokens */
/* %token  T_LeftBracket T_RightBracket */
%token   T_LeftParen T_RightParen
%token   T_Dot T_FieldSelection
%token   T_Vec2 T_Vec3 T_Vec4
%token   T_Mat2 T_Mat3 T_Mat4
%token   T_Continue
%token   T_Semicolon T_Colon T_Comma
%token   T_AddAssign T_MulAssign T_DivAssign T_SubAssign
%token   T_LeftBrace T_RightBrace
%token   T_Plus T_Dash T_Star T_Slash
%token   T_EqualOp T_LeftAngle T_RightAngle


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
%type <decl>      Decl VarDecl
%type <type>      TypeSpecifier
                  
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

// DeclList = "translation_unit"
// Decl = " external_declaration"
DeclList  :    DeclList Decl                      { ($$=$1)->Append($2); }
          |    Decl                               { ($$ = new List<Decl*>)->Append($1); }
          ;

// Decl = "external_declaration"
Decl      :     FnDef                            { }  
                // Remember VarDecl = "declaration"
          |     VarDecl                           { } 
          ;

/************* BEGIN FOLLOWING FNDEF **********************/
FnDef    : FnPrototype CompoundStmtNoNewScope {}
         ;

CompoundStmtNoNewScope : T_LeftBrace T_RightBrace { }
                       | T_LeftBrace StmtList T_RightBrace {}
                       ;

CompoundStmtWithScope : T_LeftBrace T_RightBrace { }
                      | T_LeftBrace StmtList T_RightBrace {}
                      ;

StmtList : Stmt {}
         | StmtList Stmt {}
         ;

Stmt : CompoundStmtWithScope {}
     | SimpleStmt {}
     ;

// Simplifying: DeclarationStmt -> declaration
// VarDecl = declaration
SimpleStmt  : VarDecl {}
            | ExprStmt {}
            | SelectionStmt {}
            | SwitchStmt {}
            | CaseLabel {}
            | IterStmt {}
            ;
/******* 1 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN VARDECL *********************/
// VarDecl = "declaration"
VarDecl   : FnPrototype T_Semicolon {}
           // Simplifying: initi_decl_list -> singledecl -> fullyspecifiedtype-> TypeSpecifier
          | TypeSpecifier T_Identifier T_Semicolon {$$ = new VarDecl(new Identifier(yylloc, $2), $1); }
          ;

// Simplifying TypeSpecifier -> TypeSpecifierNonarray -> Terminals
// TypeSpecifier = "type_specifier_nonarray"
TypeSpecifier : T_Void  { $$ = Type::voidType;}
              | T_Float {$$ = Type::floatType;}
              | T_Int   { $$ = Type::intType; }
              | T_Vec2  {$$ = Type::vec2Type;}
              | T_Vec3  {$$ = Type::vec3Type;}
              | T_Vec4  {$$ = Type::vec4Type;}
              | T_Mat2  {$$ = Type::mat2Type;}
              | T_Mat3  {$$ = Type::mat3Type;}
              | T_Mat4  {$$ = Type::mat4Type;}
              ;

FnPrototype : FnDeclarator T_RightParen {}
            ;

FnDeclarator :  FnHeader                        {}
             |  FnHeaderWithParameters          {}
             ;


// TODO: Comma isn't highlighted, do we still need to deal with second path           
FnHeaderWithParameters : FnHeader ParameterDecl {}
                       | FnHeaderWithParameters T_Comma ParameterDecl {}
                       ;
                      
FnHeader    : TypeSpecifier T_Identifier T_LeftParen {}
            ;

// ParameterDecl = "paramater_declaration"
// Simplifying parameterdeclarator -> typespecifier t_identifier
ParameterDecl : TypeSpecifier T_Identifier {}
               // Simplifying: ParameterTypeSpecifier -> TypeSpecifier
               | TypeSpecifier {}
               ;

/***** END FOLLOWING VARDECL ************/

/******* 2 ************/
/**********************/
/**********************/
/*********************/
/********** BEGIN EXPRSTMT *******************/

ExprStmt : T_Semicolon {}
         | Expr T_Semicolon {}
         ;

Expr : AssignExpr {}
     ;

// Simplifying: ConditionalExpr
AssignExpr : ConditionalExpr {}
           | UnaryExpr AssignOp AssignExpr {}
           ;

AssignOp : T_Equal {}
         | T_MulAssign {}
         | T_DivAssign {}
         | T_AddAssign {}
         | T_SubAssign {}
         ;

/******* BEGIN ConditionalExpr ********/
ConditionalExpr : LogicalOrExpr {}
                ;

// Simplifying LogicalXorExpr -> LogicalAndExpr
LogicalOrExpr : LogicalAndExpr {}
              | LogicalOrExpr T_OrOp LogicalAndExpr
              ;

// Simplify: InclusiveOrExpr -> ExclusiveOrExpr -> AndExpr -> EqualExpr
LogicalAndExpr : EqualExpr {}
               | LogicalAndExpr T_AndOp EqualExpr {}
               ;

EqualExpr : RelationalExpr {}
          | EqualExpr T_EqualOp RelationalExpr {}
          | EqualExpr T_NotEqual RelationalExpr {}
          ;

// Simplifying ShiftExpr -> AddExpr
RelationalExpr : AddExpr {}
               | RelationalExpr T_LeftAngle AddExpr {}
               | RelationalExpr T_RightAngle AddExpr {}
               | RelationalExpr T_LessEqual AddExpr {}
               | RelationalExpr T_GreaterEqual AddExpr {}

AddExpr : MultExpr {}
        | AddExpr T_Plus MultExpr {}
        | AddExpr T_Dash MultExpr {}
        ;

MultExpr : UnaryExpr {}
        | MultExpr T_Star UnaryExpr {}
        | MultExpr T_Slash UnaryExpr {}
        ;

/********* BEGIN UnaryExpr *********/
UnaryExpr : PostfixExpr {}
          | T_Inc UnaryExpr {}
          | T_Dec UnaryExpr {}
          | UnaryOp UnaryExpr {}
          ;

UnaryOp : T_Plus {printf("T_Plus");}
        | T_Dash {printf("T_Dash");}
        ;

PostfixExpr : PrimExpr {}
            | PostfixExpr T_Dot T_FieldSelection {}
            | PostfixExpr T_Inc {}
            | PostfixExpr T_Dec {}
            ;
// Simplifying: VarIdentifier -> T_Identifier
PrimExpr : T_Identifier {}
         | T_IntConstant {}
         | T_FloatConstant {}
         | T_BoolConstant {}
         | T_LeftParen Expr T_RightParen {}
         ;
/********* END UnaryExpr *************/
/********* END ConditionalExpr ***********/
/*********** END ExprStmt ****************/

/******* 3 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN SelectionStmt *********************/
SelectionStmt : T_If T_LeftParen Expr T_RightParen SelectionRestStmt {}
              ;

SelectionRestStmt : StmtWithScope T_Else StmtWithScope {}
                  | StmtWithScope {}
                  ;

StmtWithScope : CompoundStmtNoNewScope {}
              | SimpleStmt {}
              ;

/************** End SelectionStmt *********************/

/******* 4 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN SwitchStmt *********************/
// Expr defined earlier
SwitchStmt : T_Switch T_LeftParen Expr T_RightParen T_LeftBrace 
                      SwitchStmtList T_RightBrace {}
            ;

// StmtList defined earlier
SwitchStmtList : StmtList {}
               /* ";" means empty */
               | ";" {printf("EMPTY");}
               ;

/************** End SwitchStmt *********************/

/******* 5 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN CaseLabel *********************/
// Expr defined earlier
CaseLabel : T_Case Expr T_Colon {}
          | T_Default T_Colon {}
          ;

/************** END CaseLabel *********************/

/******* 6 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN IterStmt *********************/
IterStmt : T_While T_LeftParen Condition T_RightParen
                   StmtNoNewScope {}
         | T_For T_LeftParen ForInitStmt ForRestStmt
                   T_RightParen StmtNoNewScope {}
         ;

StmtNoNewScope : CompoundStmtNoNewScope {}
               | SimpleStmt {}
               ;

Condition : Expr {}
          | TypeSpecifier T_Identifier T_Equal Initializer
          ;

// AssignExpr defined earlier
Initializer : AssignExpr {}
            ;

// Simplifying DeclarationStmt -> "declaration"
// VarDecl = "declaration"
ForInitStmt : ExprStmt {}
            | VarDecl {}
            ;

ForRestStmt : Conditionopt T_Semicolon {}
            | Conditionopt T_Semicolon Expr {}
            ;

Conditionopt : Condition {}
             /* ";" means empty */
             | ";" {}
             ;

/************** END IterStmt *********************/

/**** CHOSEN TO OMIT THESE RULES ***************
 * function_identifier b/c only called by function_call_header
 * integer_expression b/c don't have to implement any caller
 * constant_expr b/c don't have to implement any caller
 *
 * We can simplify compoundstmt to one thing and stmt's with scope
 *     can be simplified to one thing too, but i didn't know if
 *     actions would be different


/**** Stuff I Took Out - Lea ***** /
// VarDecl = "declaration"
/* taking out old VarDecl becuause TypeQualifier because he got rid of those tokens *
VarDecl   :     TypeQualifier T_Identifier T_Semicolon  { $$ = new VarDecl(new Identifier(yylloc, $2), $1);}
                // SingleDecl simplifies from init_declarator_list -> single_declaration
          |     SingleDecl T_Semicolon          {  }
          ;*/
          
/* Spec update: don't have to do left or right brackets
don't have to do array specifier *
TypeSpecifier     : TypeSpecifierNonarray                       { }
                  | TypeSpecifierNonarray ArraySpecifier    {}
                  ;

TypeSpecifierNonarray : T_Void {printf("T_Void");}
                      | T_Float {printf("T_Float");}
                      | T_Int {printf("T_Int");}
                      | T_Vec2 {printf("T_Vec2");}
                      | T_Vec3 {printf("T_Vec3");}
                      | T_Vec4 {printf("T_Vec4");}
                      | T_Mat2 {printf("T_Mat2");
                      | T_Mat3 {printf("T_Mat3");}
                      | T_Mat4 {printf("T_Mat4");}
                      ; */
                      

/* He took type qualifiers out of the specs 

TypeQualifier   :  SingleTypeQualifier                { }
                |  TypeQualifier SingleTypeQualifier  { }
                ;

SingleTypeQualifier : StorageQualifier                { }
                    | LayoutQualifier                 { }
                    ;

StorageQualifier : T_In                        { }
                 | T_Out                       { }
                 ;

LayoutQualifier : T_Layout '(' LayoutQualifierId ')'  { }
                ;

LayoutQualifierId : T_Identifier T_Equal T_IntConstant { 

                    Operator *op = new Operator(yylloc, (const char*)T_Equal);
                    //$$ = new AssignExpr(
                           // new IdentifierConstant(yylloc, new Identifier(yylloc, $1)), 
                            //op, new IntConstant(yylloc, $3));
                                                   }
                  ;*/
                    
            
%%


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
