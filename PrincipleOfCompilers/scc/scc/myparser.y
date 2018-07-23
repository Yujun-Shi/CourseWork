%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2017.11.18
****************************************************************************/

#include "mylexer.h"
#include "GrammarTree.h"
#include "TableNode.h"
#include "NodeType.h"
#include <memory>
#include <fstream>
#include <cstring>

using namespace std;

shared_ptr<GrammarTree> g;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE shared_ptr<GrammarNode>
#endif
}


%token VOID CHAR INT FLOAT DOUBLE
%token IF FOR WHILE RETURN BREAK CONTINUE CONST
%token LBRACE RBRACE LPAREN RPAREN INUMBER FNUMBER ID SEMICOLON STRING_LITERAL CHAR_LITERAL
%token INPUT PRINT


%nonassoc NO_ELSE
%nonassoc ELSE

// maybe remove all of that
%left EMPTY
%left COMMA
%right ASSIGN ADDASSIGN MINUSASSIGN MULASSIGN DIVASSIGN
%left LOGICOR
%left LOGICAND
%left BITOR
%left BITXOR
%left BITAND
%left EQ NEQ
%left GT GE LT LE
%left LEFTSHIFT RIGHTSHIFT
%left ADD MINUS
%left MUL DIV MODE
%right INC DEC UMINUS LOGICNOT BITNOT // prefix
%left POST // postfix


%%
/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
translation_unit : external_declaration { $$ = $1; g->root = $$;}
				 | translation_unit external_declaration 
				 { 
					
					$$ = make_shared<GrammarNode>(new TransUnit(), 2, curLineNo); 
					$$->children[0] = $1;
					$$->children[1] = $2;
					g->root = $$;
				 }
				 ;
external_declaration : function_definition { $$ = $1; }
					 | declaration { $$ = $1; }
					 ;
function_definition : declaration_specifiers declarator compound_statement
					{
						$$ = make_shared<GrammarNode>(new FuncDef(), 3, curLineNo);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
						dynamic_cast<FuncDef*>($$->type.get())->idTable = TableNode::curNode->children.back();
					}
					;
/*
declaration_specifiers : type_specifier declaration_specifiers 
					   {
							$$ = make_shared<GrammarNode>(new DecSpec(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $2;
							DecSpec* tmp = dynamic_cast<DecSpec*>($2->type.get());
							dynamic_cast<DecSpec* >($$->type.get())->typeSpecList.assign(
								tmp->typeSpecList.begin(), tmp->typeSpecList.end());
								
							dynamic_cast<DecSpec* >($$->type.get())->typeSpecList.push_front(
								dynamic_cast<TypeSpec* >($1->type.get())->typeSpecItem
							);
					   }
					   |
*/
declaration_specifiers : type_specifier 
					   { 
							$$ = make_shared<GrammarNode>(new DecSpec(), 1, curLineNo);
							$$->children[0] = $1;
							dynamic_cast<DecSpec* >($$->type.get())->typeSpecList.push_front(
								dynamic_cast<TypeSpec* >($1->type.get())->typeSpecItem
							);
					   }
					   | type_qualifier declaration_specifiers 
					   {
						   $$ = make_shared<GrammarNode>(new DecSpec(), 2, curLineNo);
						   $$->children[0] = $1;
					   	   $$->children[1] = $2;
					   	   DecSpec* tmp = dynamic_cast<DecSpec*>($2->type.get());
						   dynamic_cast<DecSpec* >($$->type.get())->typeQualList.assign(
								tmp->typeQualList.begin(), tmp->typeQualList.end());
								
						   dynamic_cast<DecSpec* >($$->type.get())
								->typeQualList.push_front(
									dynamic_cast<TypeQual* >($1->type.get())->typeQualItem
								);
					   }
					   ;
type_specifier : VOID 
			   { 
				   $$ = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   $$->type->attr.name = "void";
				   dynamic_cast<TypeSpec* >($$->type.get())->typeSpecItem = VOID_T;
			   }
			   | CHAR 
			   {
				   $$ = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   $$->type->attr.name = "char";
			   	   dynamic_cast<TypeSpec* >($$->type.get())->typeSpecItem = CHAR_T;
			   }
			   | INT 
			   { 
				   $$ = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   $$->type->attr.name = "int";
			   	   dynamic_cast<TypeSpec* >($$->type.get())->typeSpecItem = INT_T;
			   }
			   | FLOAT 
			   {
				   $$ = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   $$->type->attr.name = "float";
			   	   dynamic_cast<TypeSpec* >($$->type.get())->typeSpecItem = FLOAT_T;
			   }
			   | DOUBLE 
			   {
				   $$ = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   $$->type->attr.name = "double";
			       dynamic_cast<TypeSpec* >($$->type.get())->typeSpecItem = DOUBLE_T;
			   }
			   ;
type_qualifier : CONST
			   {
				   $$ = make_shared<GrammarNode>(new TypeQual(), 0, curLineNo);
			   	   $$->type->attr.name = "const";
				   dynamic_cast<TypeQual* >($$->type.get())->typeQualItem = CONST_T;
			   }
			   ;
pointer : MUL 
		{
			$$ = make_shared<GrammarNode>(new PointerUse(), 0, curLineNo);
			$$->type->attr.pointerDegree = 1;
		}
		| MUL pointer
		{
			$$ = make_shared<GrammarNode>(new PointerUse(), 2, curLineNo);
			$$->type->attr.pointerDegree = 1 + $2->type->attr.pointerDegree;		
		}
		;
declarator : direct_declarator { $$ = $1; }
		   | pointer direct_declarator
		   {
			   $$ = make_shared<GrammarNode>(new Declarator(), 2, curLineNo);
			   $$->children[0] = $1;
			   $$->children[1] = $2;
		   }
		   ;
direct_declarator : ID
				  {
					   IdInfo dummy(NON_ID_TYPE_T, NON_QUAL_TYPE_T);
                       if(!TableNode::curNode->insertId(string(curID), dummy)){
							cout<<"syntax error at line: "<<curLineNo<<"\n";
							cout<<"duplicated id name in the same area!\n";
							exit(0);
					   }
					   IdDec* tmp = new IdDec();
					   tmp->table = TableNode::curNode;
					   $$ = make_shared<GrammarNode>(tmp, 0, curLineNo);
					   if(curID == NULL) {
						   exit(EXIT_FAILURE);
					   }
					   $$->type->attr.name = new char[1 + strlen(curID)];
				   	   strcpy_s($$->type->attr.name, 1 + strlen(curID), curID);
				  }
				  | direct_declarator LPAREN
				  {
					   extraAreaSupportSwitch = false;
					   TableNode::moveDown();
				  } parameter_list RPAREN
		   		  {
		   			   // note that I didn't reduce it as DirDeclarator since we have to deal with the
		   			   // scope issue of Function declaration
			   		   $$ = make_shared<GrammarNode>(new FuncDeclarator(), 2, curLineNo);
			   		   $$->children[0] = $1;
			   		   $$->children[1] = $4;
		   		  }
		   		  ;

parameter_list : parameter_list COMMA parameter_declaration
			   {
				   $$ = make_shared<GrammarNode>(new ParamList(), 2, curLineNo);
			   	   $$->children[0] = $1;
				   $$->children[1] = $3;
			   }
		       | parameter_declaration { $$ = $1; }
		       |{ $$ = make_shared<GrammarNode>(new ParamList(), 0, curLineNo); }
		       ;
parameter_declaration : declaration_specifiers declarator
					  {
						  $$ = make_shared<GrammarNode>(new ParamDec(), 2, curLineNo);
						  $$->children[0] = $1;
						  $$->children[1] = $2;
                          GrammarTree::obtainIdInfo($$->children[0]);
                          GrammarTree::fixIdInfo($$->children[1], true);
                          GrammarTree::resetIdInfo();
					      
                      }
					  ;

declaration : declaration_specifiers init_declarator_list SEMICOLON
			{
				$$ = make_shared<GrammarNode>(new Dec(), 2, curLineNo);
				$$->children[0] = $1;
				$$->children[1] = $2;
				// first, we don't support the type of function!
				// Note that the bug here implicitly doesn't support function type check
                GrammarTree::obtainIdInfo($$->children[0]);
                GrammarTree::fixIdInfo($$->children[1]);
			    GrammarTree::resetIdInfo();
                if(extraAreaSupportSwitch == false){
					if(typeid(*($$->children[1]->type)) == typeid(FuncDeclarator)){
						extraAreaSupportSwitch = true;
						TableNode::moveUp();
					}
				}
			}
			;

init_declarator_list : init_declarator 
					{
						$$ = $1;
					}
					| init_declarator_list COMMA init_declarator 
					{
						$$ = make_shared<GrammarNode>(new InitDecList(), 2, curLineNo);
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
					;
init_declarator : declarator ASSIGN initializer
				{
					$$ = make_shared<GrammarNode>(new InitDec(), 2, curLineNo);
					$$->children[0] = $1;
					$$->children[1] = $3;
				}
				| declarator{ $$ = $1; }
				;



initializer : assign_expression { $$ = $1; }
			;		  

expression : assign_expression { $$ = $1; }
		   | expression COMMA assign_expression 
		   {
			   $$ = make_shared<GrammarNode>(new Expr(), 2, curLineNo);
		   	   $$->children[0] = $1;
			   $$->children[1] = $3;
		   	   $$->type->attr.optype = COMMA;
		   }
		   ;
assign_expression : logicor_expression ASSIGN assign_expression 
				  {
					 $$ = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 $$->children[0] = $1;
					 $$->children[1] = $3;
					 $$->type->attr.optype = ASSIGN;
				  }
				  | logicor_expression ADDASSIGN assign_expression 
				  {
					 $$ = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 $$->children[0] = $1;
					 $$->children[1] = $3;
					 $$->type->attr.optype = ADDASSIGN;				  
				  }
				  | logicor_expression MINUSASSIGN assign_expression
				  {
					 $$ = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 $$->children[0] = $1;
					 $$->children[1] = $3;
					 $$->type->attr.optype = MINUSASSIGN;				  
				  }
				  | logicor_expression MULASSIGN assign_expression 
				  {
					 $$ = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 $$->children[0] = $1;
					 $$->children[1] = $3;
					 $$->type->attr.optype = MULASSIGN;				  
				  }
				  | logicor_expression DIVASSIGN assign_expression 
				  {
					 $$ = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 $$->children[0] = $1;
					 $$->children[1] = $3;
					 $$->type->attr.optype = DIVASSIGN;				  
				  }
				  | logicor_expression 
				  {
					  $$ = $1;
				  }
				  ;
logicor_expression : logicor_expression LOGICOR logicand_expression
				  {
					  $$ = make_shared<GrammarNode>(new LogOrExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
					  $$->type->attr.optype = LOGICOR;
				  }
				  | logicand_expression 
				  { 
					  $$ = $1; 
				  }
				  ;
logicand_expression : logicand_expression LOGICAND bitor_expression
					{
					  $$ = make_shared<GrammarNode>(new LogAndExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
					  $$->type->attr.optype = LOGICAND;
					}
					| bitor_expression 
					{
						$$ = $1;
					}
					; 
bitor_expression : bitor_expression BITOR bitxor_expression 
				 {
					  $$ = make_shared<GrammarNode>(new BitOrExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
					  $$->type->attr.optype = BITOR;
				 } 
				 | bitxor_expression 
				 {
					 $$ = $1;
				 }
				 ;
bitxor_expression : bitxor_expression BITXOR bitand_expression
				  {
					  $$ = make_shared<GrammarNode>(new BitXorExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
					  $$->type->attr.optype = BITXOR; 
				  }
				  | bitand_expression
				  {
					  $$ = $1;
				  }
				  ;
bitand_expression : bitand_expression BITAND equality_expression
				  {
					  $$ = make_shared<GrammarNode>(new BitAndExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
					  $$->type->attr.optype = BITAND;
				  }
				  | equality_expression 
				  {
					  $$ = $1;
				  }
				  ;
equality_expression : equality_expression EQ nonequality_expression 
					{
						$$ = make_shared<GrammarNode>(new EqualExpr(), 2, curLineNo);
						$$->children[0] = $1;
						$$->children[1] = $3;
						$$->type->attr.optype = EQ;
					}
					| equality_expression NEQ nonequality_expression
					{
						$$ = make_shared<GrammarNode>(new EqualExpr(), 2, curLineNo);
						$$->children[0] = $1;
						$$->children[1] = $3;
						$$->type->attr.optype = NEQ;
					}
					| nonequality_expression 
					{ 
						$$ = $1; 
					}
					;

nonequality_expression : nonequality_expression GE shift_expression
					   {
							$$ = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $3;
							$$->type->attr.optype = GE;
					   }
					   | nonequality_expression LE shift_expression 
					   {
							$$ = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $3;
							$$->type->attr.optype = LE;					
					   }
					   | nonequality_expression GT shift_expression 
					   {
							$$ = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $3;
							$$->type->attr.optype = GT;
					   }
					   | nonequality_expression LT shift_expression 
					   {
							$$ = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $3;
							$$->type->attr.optype = LT;
						}
						| shift_expression
						{ $$ = $1; }
						;
shift_expression : shift_expression LEFTSHIFT add_expression
				 {
					$$ = make_shared<GrammarNode>(new ShiftExpr(), 2, curLineNo);
					$$->children[0] = $1;
					$$->children[1] = $3;
					$$->type->attr.optype = LEFTSHIFT;
				 }
				 | shift_expression RIGHTSHIFT add_expression
				 {
					$$ = make_shared<GrammarNode>(new ShiftExpr(), 2, curLineNo);
					$$->children[0] = $1;
					$$->children[1] = $3;
					$$->type->attr.optype = RIGHTSHIFT;
				 }
				 | add_expression %prec EMPTY{ $$ = $1; }
				 ;

add_expression : add_expression ADD mul_expression 
			   {
				  $$ = make_shared<GrammarNode>(new AddExpr(), 2, curLineNo);
				  $$->children[0] = $1;
				  $$->children[1] = $3;
				  $$->type->attr.optype = ADD;
			   }
			   | add_expression MINUS mul_expression
			   {
				  $$ = make_shared<GrammarNode>(new AddExpr(), 2, curLineNo);
				  $$->children[0] = $1;
				  $$->children[1] = $3;
				  $$->type->attr.optype = MINUS;			   
			   }
			   | mul_expression
			   { $$ = $1; }
			   ;
mul_expression : mul_expression MUL prefix_expression
			   {
				   $$ = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   $$->children[0] = $1;
				   $$->children[1] = $3;
				   $$->type->attr.optype = MUL;
			   }
			   | mul_expression DIV prefix_expression 
			   {
				   $$ = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   $$->children[0] = $1;
				   $$->children[1] = $3;
				   $$->type->attr.optype = DIV;
			   }
			   | mul_expression MODE prefix_expression
			   {
				   $$ = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   $$->children[0] = $1;
				   $$->children[1] = $3;
				   $$->type->attr.optype = MODE;				   
			   }
			   | prefix_expression { $$ = $1; }
			   ;
			   
prefix_expression : MINUS prefix_expression %prec UMINUS
				  {
					  $$ = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  $$->children[0] = $2;
					  $$->type->attr.optype = MINUS;
				  }
				  | LOGICNOT prefix_expression
				  {
				  	  $$ = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  $$->children[0] = $2;
					  $$->type->attr.optype = LOGICNOT;
				  }
				  | BITNOT prefix_expression
				  {
				  	  $$ = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  $$->children[0] = $2;
					  $$->type->attr.optype = BITNOT;
				  }
				  | INC prefix_expression
				  {
				  	  $$ = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  $$->children[0] = $2;
					  $$->type->attr.optype = INC;				  
				  }
				  | DEC prefix_expression
				  {
				  	  $$ = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  $$->children[0] = $2;
					  $$->type->attr.optype = DEC;
				  }
				  | postfix_expression  %prec POST
				  { 
					  $$ = $1; 
				  }
				  ;
postfix_expression : primary_expression 
				  {
					$$ = $1;
				  }
				  | postfix_expression %prec POST INC
				  {
					  $$ = make_shared<GrammarNode>(new PostfixExpr(), 1, curLineNo);
					  $$->children[0] = $1;
					  $$->type->attr.optype = INC;
				  }
				  | postfix_expression %prec POST DEC
				  {
					  $$ = make_shared<GrammarNode>(new PostfixExpr(), 1, curLineNo);
					  $$->children[0] = $1;
					  $$->type->attr.optype = DEC;
				  }
				  | postfix_expression LPAREN argument_expression_list RPAREN
				  {
					  $$ = make_shared<GrammarNode>(new FuncCallExpr(), 2, curLineNo);
					  $$->children[0] = $1;
					  $$->children[1] = $3;
				  }
				  ;
argument_expression_list : assign_expression
						 {
							$$ = $1;
						 }
						 | argument_expression_list COMMA assign_expression
						 {
							$$ = make_shared<GrammarNode>(new ArgExprList(), 2, curLineNo);
							$$->children[0] = $1;
							$$->children[1] = $3;
						 }
						 ;

primary_expression : STRING_LITERAL
				   {
					   $$ = make_shared<GrammarNode>(new StringUse(), 0, curLineNo);
					   $$->type->attr.name = new char[1 + strlen(curString)];
				   	   strcpy_s($$->type->attr.name, 1 + strlen(curString), curString);
				   }
				   | ID 
				   { 
					   IdInfo dummy;
					   if(!TableNode::curNode->lookupId(string(curID), dummy))
					   {
						   cout<<"syntax error at line: "<<curLineNo<<"\n";
					   	   cout<<"id: " << curID << " not declared";
					   	   exit(0);
					   }
					   IdUse* tmp = new IdUse();
					   tmp->table = TableNode::curNode;
					   $$ = make_shared<GrammarNode>(tmp, 0, curLineNo);
					   // assert! curID shouldn't be NULL by now!
					   if(curID == NULL) {
						   cout<<"syntax error!\n";
					   	   return;
					   }
					   $$->type->attr.name = new char[1 + strlen(curID)];
				   	   strcpy_s($$->type->attr.name, 1 + strlen(curID), curID);
				   }
				   | INUMBER
				   {
					   $$ = make_shared<GrammarNode>(new INumUse(), 0, curLineNo);
				   	   $$->type->attr.intVal = curInt;
				   }
				   | FNUMBER
				   {
					   $$ = make_shared<GrammarNode>(new FNumUse(), 0, curLineNo);
				   	   $$->type->attr.floatVal = curFloat;
				   }
				   | CHAR_LITERAL
				   {
					   $$ = make_shared<GrammarNode>(new CharUse(), 0, curLineNo);
					   $$->type->attr.charVal = curChar;
				   }
				   | LPAREN expression RPAREN 
				   {
					   $$ = $2;
					   // $$->type->attr.floatVal = curFloat;
				   }
				   ;

statement : compound_statement { $$ = $1; }
		  | expression_statement { $$ = $1; }
		  | selection_statement { $$ = $1; }
		  | iteration_statement { $$ = $1; }
		  | jump_statement { $$ = $1; }
		  | input_statement { $$ = $1; }
		  | print_statement { $$ = $1; }
		  ;
input_statement : INPUT LPAREN primary_expression RPAREN SEMICOLON
				{
					$$ = make_shared<GrammarNode>(new InputStmt(), 1, curLineNo);
					$$->children[0] = $3;
				}
				;
print_statement : PRINT LPAREN primary_expression RPAREN SEMICOLON
				{
					$$ = make_shared<GrammarNode>(new PrintStmt(), 1, curLineNo);
					$$->children[0] = $3;
				}
				;				

compound_statement : LBRACE 
					{
						if(extraAreaSupportSwitch == false){
							extraAreaSupportSwitch = true;
						}else{
							TableNode::moveDown();
						}
					}
					RBRACE
					{
						$$ = make_shared<GrammarNode>(new CmpStmt(), 0, curLineNo);
						TableNode::moveUp();
					}
				    | LBRACE 
				    {
						if(extraAreaSupportSwitch == false){
							extraAreaSupportSwitch = true;
						}else{
							TableNode::moveDown();
						}
				    }
				    block_item_list RBRACE
				    {
					    $$ = $3;
					    TableNode::moveUp();
				    }
				    ;
block_item_list : block_item { $$ = $1; }
				| block_item_list block_item 
				{
					$$ = make_shared<GrammarNode>(new BlockItemList(), 2, curLineNo);
					$$->children[0] = $1;
					$$->children[1] = $2;
				}
				;
block_item : declaration { $$ = $1; }
		   | statement { $$ = $1; }
		   ;
expression_statement : SEMICOLON {$$ = make_shared<GrammarNode>(new EmptyStmt(),0,curLineNo);}
					 | expression SEMICOLON { $$ = $1; }
					 ;

iteration_statement : WHILE LPAREN expression RPAREN statement
					{
						$$ = make_shared<GrammarNode>(new IterStmt(), 2, curLineNo);
						$$->children[0] = $3;
						$$->children[1] = $5;
					}
					| FOR LPAREN
					{
						extraAreaSupportSwitch = false; // push it down
						TableNode::moveDown(); // move it down
					}
					declaration expression_statement expression RPAREN statement
					{
						$$ = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						$$->children[0] = $4;
						$$->children[1] = $5;
						$$->children[2] = $6;
						$$->children[3] = $8;
					}
					| FOR LPAREN expression_statement expression_statement expression RPAREN statement
					{
						$$ = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						$$->children[0] = $3;
						$$->children[1] = $4;
						$$->children[2] = $5;
						$$->children[3] = $7;
					}
					| FOR LPAREN expression_statement expression_statement RPAREN statement
					{
						$$ = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						$$->children[0] = $3;
						$$->children[1] = $4;
						$$->children[2] = make_shared<GrammarNode>(new EmptyStmt(), 0, curLineNo);
						$$->children[3] = $6;
					}
					;

selection_statement : IF LPAREN expression RPAREN statement %prec NO_ELSE
					{
						$$ = make_shared<GrammarNode>(new SelStmt(), 2, curLineNo);
						$$->children[0] = $3;
						$$->children[1] = $5;
					}
					| IF LPAREN expression RPAREN statement ELSE statement 
					{
						$$ = make_shared<GrammarNode>(new SelStmt(), 3, curLineNo);
						$$->children[0] = $3;
						$$->children[1] = $5;
						$$->children[2] = $7;
					}
					;
jump_statement : CONTINUE SEMICOLON 
			   { 
				   $$ = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo); 
			   	   $$->type->attr.jmptype = CONTINUE;
			   }
			   | BREAK SEMICOLON 
			   { 
				   $$ = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo);
			   	   $$->type->attr.jmptype = BREAK;
			   }
			   | RETURN SEMICOLON 
			   {
				   $$ = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo);
			   	   $$->type->attr.jmptype = RETURN;
			   }
			   | RETURN expression SEMICOLON 
			   {
				   $$ = make_shared<GrammarNode>(new JmpStmt(), 1, curLineNo);
				   $$->type->attr.jmptype = RETURN;
			   }
			   ;
%%


/////////////////////////////////////////////////////////////////////////////
// programs section


int main(int argc, char* argv[])
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	g = make_shared<GrammarTree>();
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = new ifstream(argv[1]);
			n = parser.yyparse();
			ofstream os("tmp.asm");
			g->printTree();
            GrammarTree::recursiveBuildTripleAddr(g->root);
            GrammarTree::genCode(os);
		}
	}
	return n;
}