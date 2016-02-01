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
#include "ast_expr.h"
#include "ast_stmt.h"
#include "ast_decl.h"

void yyerror(const char *msg); // standard error-handling routine

//MyBlock *myblock = new MyBlock();

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
    VarDecl *vardecl;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    Type *type;
    AssignExpr *assignExpr;
    FnDecl *fndecl;
    StmtBlock *stmtblock;
    Operator *op;
    Expr *expr;
    MyBlock *myBlock;
    SwitchBlock *switchBlock;
    List<Expr*> *exprList;
    Case *mycase;
    Default *mydefault;
    List<Case *> *mycaseList;
    SwitchLabel *switchLabel;
    List<SwitchLabel *> *switchLabelList;
    IntConstant *intConstant;
    VarExpr *varExpr;
    const char * id;
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
%token   NO_ELSE

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
%type <decl>      Decl FnDef 
%type <vardecl>   VarDecl ParameterDecl
%type <type>      TypeSpecifier
%type <fndecl>    FnHeader FnHeaderWithParameters FnPrototype FnDeclarator
%type <stmtblock> CompoundStmtNoNewScope CompoundStmtWithScope 
%type <stmtList>  SelectionRestStmt
%type <exprList>  ForRestStmt VecArgList
%type <stmt>      SelectionStmt Stmt StmtWithScope ExprStmt IterStmt
                  StmtNoNewScope SwitchStmt
%type <mycase>    CaseLabel
%type <mydefault> DefaultLabel
%type <op>        UnaryOp AssignOp 
%type <myBlock>   StmtList SimpleStmt 
%type <switchBlock> SwitchStmtList SwitchBlock
%type <expr>      PrimExpr AssignExpr UnaryExpr RelationalExpr AddExpr MultExpr Condition
                  PostfixExpr Expr LogicalOrExpr LogicalAndExpr EqualExpr ConditionalExpr
                  Conditionopt ForInitStmt VecArg VecConstructor //SwitchStmt
%type <intConstant> Expr2
%type <id> VecQualifier

 /* Precedence */
%nonassoc NO_ELSE
%nonassoc T_Else
%left T_Comma
%right T_MulAssign T_DivAssign
%right T_AddAssign T_SubAssign
%right T_Equal
%left T_OrOp
%left T_AndOp
%left T_EqualOp T_NotEqual
%left T_LeftAngle T_RightAngle T_LessEqual T_GreaterEqual
%left T_Plus T_Dash
%left T_Star T_Slash
 // technically unary ops should be here
%left T_Inc T_Dec
%left T_Dot
%nonassoc T_LeftParen T_RightParen              
%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 * 
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
          // LEAD READ THIS: So I just compressed each line after the previous
          // line was working and drilling into our PrimExpr. I'm trying to get 
          // it to eventually be our original line. 
          
FnDef    : FnPrototype CompoundStmtNoNewScope {
                            $1->SetFunctionBody($2);
                            $$=$1;}
;

CompoundStmtNoNewScope : T_LeftBrace T_RightBrace { 
                            
                            $$ = new StmtBlock(new List<VarDecl*>, new List<Stmt*>);}
                        | T_LeftBrace StmtList T_RightBrace { 
                                            $$ = new StmtBlock($2->vars, $2->stmts);
                             }
                       ;

CompoundStmtWithScope : T_LeftBrace T_RightBrace { 
                           
                            $$ = new StmtBlock(new List<VarDecl*>, new List<Stmt*>); }
                      | T_LeftBrace StmtList T_RightBrace { 
                        
                            $$ = new StmtBlock($2->vars, $2->stmts); }
                      ;

                     
// Type MyBlock is stmtlist
StmtList :  Stmt { $$ = new MyBlock(); ($$->stmts)->Append($1);}
//         |  CaseLabel {     $$ = new MyBlock(); 
//                            ($$->switchblock->cases)->Append($1); } 
//         |  DefaultLabel { $$->def = $1; }
         |  VarDecl { $$ = new MyBlock(); ($$->vars)->Append($1); }
         |  StmtList Stmt { $1->stmts->Append($2); $$ = $1; }
//         |  StmtList CaseLabel { $1->switchblock->cases->Append($2); $$ = $1; }
         |  StmtList VarDecl { $1->vars->Append($2); $$ = $1; }
//         |  StmtList DefaultLabel { $1->switchblock->def = $2; } 
//         | StmtList SwitchBlock { $1->stmts->Append($2); $$ = $1;}
         ;

SwitchBlock : CaseLabel {           $$ = new SwitchBlock(); 
//                                    $1->label = new IntConstant(yylloc, ($1->label->value));
                                    ($$->cases)->Append(new Case($1->label, $1->stmts)); } 
            | SwitchBlock CaseLabel { 
//                                $2->label = new IntConstant(yylloc, ($2->label->value));
                                ($1->cases)->Append(new Case($2->label, $2->stmts)); }
            | SwitchBlock DefaultLabel { $1->def = $2; }

Stmt : CompoundStmtWithScope { }
     | SimpleStmt { } // 
     ;
     
// Simplifying: DeclarationStmt -> declaration
// VarDecl = declaration
SimpleStmt  : //VarDecl { }
             ExprStmt { }
            | SelectionStmt {}
            | SwitchStmt {}
//            | CaseLabel {}
//            | DefaultLabel {}
            | IterStmt {}
            ;
            
            /******* 1 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN VARDECL *********************/

// VarDecl = "declaration"
VarDecl   : FnPrototype T_Semicolon { }
           // Simplifying: initi_decl_list -> singledecl -> fullyspecifiedtype-> TypeSpecifier
          | TypeSpecifier T_Identifier T_Semicolon {
                            $$ = new VarDecl(new Identifier(yylloc, $2), $1); }
          ;

                     
// Simplifying TypeSpecifier -> TypeSpecifierNonarray -> Terminals
// TypeSpecifier = "type_specifier_nonarray"
TypeSpecifier : T_Void  { $$ = Type::voidType;}
              | T_Bool  { $$ = Type::boolType;}
              | T_Float { $$ = Type::floatType;}
              | T_Int   { $$ = Type::intType; }
              | T_Vec2  { $$ = Type::vec2Type;}
              | T_Vec3  { $$ = Type::vec3Type;}
              | T_Vec4  { $$ = Type::vec4Type;}
              | T_Mat2  { $$ = Type::mat2Type;}
              | T_Mat3  { $$ = Type::mat3Type;}
              | T_Mat4  { $$ = Type::mat4Type;}
              ;

FnPrototype : FnDeclarator T_RightParen { }
            ;

FnDeclarator :  FnHeader                        { }
             |  FnHeaderWithParameters          { }
             ;


// TODO: Comma isn't highlighted, do we still need to deal with second path           
FnHeaderWithParameters : FnHeader ParameterDecl { $1->AddFormal($2);}
                       | FnHeaderWithParameters T_Comma ParameterDecl { $1->AddFormal($3); }
                       ;
                      
FnHeader    : TypeSpecifier T_Identifier T_LeftParen { $$ = new FnDecl(new Identifier(yylloc, $2), $1, new List<VarDecl*>);}
            ;

            
// ParameterDecl = "paramater_declaration"
// Simplifying parameterdeclarator -> typespecifier t_identifier
ParameterDecl : TypeSpecifier T_Identifier { $$ = new VarDecl( new Identifier(yylloc, $2), $1); }
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
         | Expr T_Semicolon { }
         ;

Expr : AssignExpr {  }
     ;

// Simplifying: ConditionalExpr
AssignExpr : ConditionalExpr {}
           | TypeSpecifier T_Identifier AssignOp AssignExpr { 
                                            VarExpr *var = new VarExpr(yylloc, new Identifier(yylloc,$2));
                                            $$ = new AssignExpr(var, $3, $4);
                                                }
           | UnaryExpr AssignOp AssignExpr { 
                                $$ = new AssignExpr($1, $2, $3);
                                }
           | TypeSpecifier T_Identifier AssignOp VecConstructor { 
                                            VarExpr *var = new VarExpr(yylloc, new Identifier(yylloc,$2));
                                            $$ = new AssignExpr(var, $3, $4);
                                          }
           | UnaryExpr AssignOp VecConstructor {
                                            $$ = new AssignExpr($1, $2, $3);
                                          }
           ;
 // Call(yyltype loc, Expr *base, Identifier *field, List<Expr*> *args);
 // Call -> Expr *base; // will be NULL if no explicit base
  //  Identifier *field;
  //  List<Expr*> *actuals;
// type expr
VecConstructor : VecQualifier T_LeftParen VecArgList T_RightParen {
                          Identifier *c = new Identifier(yylloc,$1);
                        $$ = new Call(yylloc, NULL, c , $3); 
                    }
                | T_Identifier T_LeftParen VecArgList T_RightParen {
                          Identifier *c = new Identifier(yylloc,$1);
                        $$ = new Call(yylloc, NULL, c, $3);
                }
               ;

// type list<expr*>
VecArgList : VecArgList T_Comma VecArg {($$ = $1)->Append($3);}
           | VecArg {($$ = new List<Expr*>)->Append($1);}
           ;

// type expr
VecArg : T_FloatConstant { $$ = new FloatConstant(yylloc, $1); }
       ;

 VecQualifier : T_Vec2 { const char *v = "vec2";
                            $$=v;
                  }
              | T_Vec3 { const char *v = "vec3";
                            $$=v;
                  }
              | T_Vec4 { const char *v = "vec4";
                            $$=v;
                  }
            ;

AssignOp : T_Equal     { const char *tok = "="; $$ = new Operator(yylloc, tok); }
         | T_MulAssign { const char *tok = "*="; $$ = new Operator(yylloc, tok);}
         | T_DivAssign { const char *tok = "/="; $$ = new Operator(yylloc, tok);}
         | T_AddAssign { const char *tok = "+="; $$ = new Operator(yylloc, tok);}
         | T_SubAssign { const char *tok = "-="; $$ = new Operator(yylloc, tok);}
         ;

/******* BEGIN ConditionalExpr ********/
ConditionalExpr : LogicalOrExpr {}
                ;

// Simplifying LogicalXorExpr -> LogicalAndExpr
LogicalOrExpr : LogicalAndExpr {}
              | LogicalOrExpr T_OrOp LogicalAndExpr {
                                const char *tok = "||";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new LogicalExpr($1, op, $3);}
              ;

// Simplify: InclusiveOrExpr -> ExclusiveOrExpr -> AndExpr -> EqualExpr
LogicalAndExpr : EqualExpr {}
               | LogicalAndExpr T_AndOp EqualExpr {
                                const char *tok = "&&";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new LogicalExpr($1, op, $3); }
               ;

EqualExpr : RelationalExpr {}
          | EqualExpr T_EqualOp RelationalExpr { 
                                const char *tok = "==";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new EqualityExpr($1, op, $3);}
          | EqualExpr T_NotEqual RelationalExpr {
                                const char *tok = "!=";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new EqualityExpr($1, op, $3);}
          ;

// Simplifying ShiftExpr -> AddExpr
RelationalExpr : AddExpr {}
               | RelationalExpr T_LeftAngle AddExpr { 
                                const char *tok = ">";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new RelationalExpr($1, op, $3);
                            }
               | RelationalExpr T_RightAngle AddExpr {
                                const char *tok = "<";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new RelationalExpr($1, op, $3);}
               
               | RelationalExpr T_LessEqual AddExpr {
                                const char *tok = "<=";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new RelationalExpr($1, op, $3);}
               
               | RelationalExpr T_GreaterEqual AddExpr {
                                const char *tok = ">=";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new RelationalExpr($1, op, $3);}

AddExpr : MultExpr {}
        | AddExpr T_Plus MultExpr {  const char *tok = "+";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new ArithmeticExpr($1, op, $3);}
        | AddExpr T_Dash MultExpr { const char *tok = "-";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new ArithmeticExpr($1, op, $3);}
        ;

MultExpr : UnaryExpr {}
        | MultExpr T_Star UnaryExpr { const char *tok = "*";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new ArithmeticExpr($1, op, $3);}
        | MultExpr T_Slash UnaryExpr { const char *tok = "/";
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new ArithmeticExpr($1, op, $3);}
        ;

/********* BEGIN UnaryExpr *********/
UnaryExpr : PostfixExpr {}
          | T_Inc UnaryExpr {   const char *tok = "++"; 
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new LogicalExpr(op, $2);
                            }
          | T_Dec UnaryExpr {   const char *tok = "--"; 
                                Operator *op = new Operator(yylloc, tok);
                                $$ = new LogicalExpr(op, $2);
                            }
          | UnaryOp UnaryExpr { $$ = new LogicalExpr($1, $2);}
          ;

UnaryOp : T_Plus { const char *tok = "+"; $$ = new Operator(yylloc, tok);}
        | T_Dash { const char *tok = "-"; $$ = new Operator(yylloc, tok);}
        ;

PostfixExpr : PrimExpr {}
            | PostfixExpr T_Dot T_FieldSelection { 
                                    //const char *text = &yytext[2];
                                    
                                    $$ = new FieldAccess($1, new Identifier(yylloc, yytext));}
            | PostfixExpr T_Inc {   const char *tok = "++";
                                    Operator *op = new Operator(yylloc, tok);
                                    $$ = new PostfixExpr($1, op);}
            | PostfixExpr T_Dec {   const char *tok = "--";
                                    Operator *op = new Operator(yylloc, tok);
                                    $$ = new PostfixExpr($1, op);}
            ;
// Simplifying: VarIdentifier -> T_Identifier
PrimExpr : T_Identifier  { $$ = new VarExpr(yylloc, new Identifier(yylloc,$1));}
         | T_IntConstant { $$ = new IntConstant(yylloc, $1);}
         | T_FloatConstant { $$ = new FloatConstant(yylloc, $1); }
         | T_BoolConstant { $$ = new BoolConstant(yylloc, $1); }
         | T_LeftParen Expr T_RightParen { $$ = $2; }
         ;
/********* END UnaryExpr *************/
/********* END ConditionalExpr ***********/
/*********** END ExprStmt ****************/

/******* 3 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN SelectionStmt *********************/              
SelectionStmt : T_If T_LeftParen Expr T_RightParen SelectionRestStmt {
                $$ = new IfStmt($3, $5->Nth(0), $5->Nth(1)); }
              ;

SelectionRestStmt : StmtWithScope T_Else StmtWithScope { 
                                ($$ = new List<Stmt*>)->Append($1);
                                $$->Append($3);}
                  | StmtWithScope %prec NO_ELSE { 
                                ($$ = new List<Stmt*>)->Append($1); 
                                $$->Append(NULL); }
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
//    SwitchStmt(Expr *expr, List<Case*> *cases, Default *def);            
//Case(IntConstant *label, List<Stmt*> *stmts) : SwitchLabel
// switch (expr) { switchstmtlist }
SwitchStmt : T_Switch T_LeftParen Expr T_RightParen T_LeftBrace 
                      SwitchStmtList T_RightBrace {
                                $$ = new SwitchStmt($3, $6->cases, $6->def);
                            }
            ;

// StmtList defined earlier
            //MyBlock
// List of cases and default
SwitchStmtList : StmtList { }
               | SwitchBlock { }
               /* ";" means empty */
               | ";" { }
               ;

/************** End SwitchStmt *********************/

/******* 5 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN CaseLabel *********************/
// Expr defined earlier
 //CaseLabel is SimpleStmt
// Case(IntConstant *label, List<Stmt*> *stmts)}
               
               //case (expr): & default:
CaseLabel : T_Case Expr2 T_Colon  { $$ = new Case($2, new List<Stmt *>);}
            | T_Case Expr2 T_Colon StmtList { $$ = new Case($2, $4->stmts);}
          ;

Expr2 : T_IntConstant { $$ = new IntConstant(yylloc, $1);}
      ;
          
DefaultLabel : T_Default T_Colon { $$ = new Default( new List<Stmt *>);}
             | T_Default T_Colon StmtList { $$ = new Default($3->stmts); }
             ;       
/************** END CaseLabel *********************/

/******* 6 ************/
/**********************/
/**********************/
/*********************/
/************** BEGIN IterStmt *********************/
IterStmt : T_While T_LeftParen Condition T_RightParen
                   StmtNoNewScope { $$ = new WhileStmt($3, $5);}
         | T_For T_LeftParen ForInitStmt ForRestStmt
                   T_RightParen StmtNoNewScope { 
                    $$ = new ForStmt($3, $4->Nth(0), $4->Nth(1), $6); }
         ;

StmtNoNewScope : CompoundStmtNoNewScope {}
               | SimpleStmt {}
               ;

Condition : Expr {}
          | TypeSpecifier T_Identifier T_Equal Initializer {}
          ;

// AssignExpr defined earlier
Initializer : AssignExpr {}
            ;

// Simplifying DeclarationStmt -> "declaration"
// VarDecl = "declaration"
ForInitStmt : ExprStmt {}
            | VarDecl {}
            ;

ForRestStmt : Conditionopt T_Semicolon {
                  ($$ = new List<Expr*>)->Append($1);
                   $$->Append(NULL); }
            | Conditionopt T_Semicolon Expr {
                  ($$ = new List<Expr*>)->Append($1);
                   $$->Append($3); }
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
*/
            
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
