/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 112 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 01/03/18
* Time: 11:23:40
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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

#line 59 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 34 ".\\myparser.y"

	// place any extra initialisation code here

#line 83 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 39 ".\\myparser.y"

	// place any extra cleanup code here

#line 97 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 83 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); g->root = (*(YYSTYPE YYFAR*)yyvalptr);
#line 207 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 85 ".\\myparser.y"
 
					
					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TransUnit(), 2, curLineNo); 
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
					g->root = (*(YYSTYPE YYFAR*)yyvalptr);
				 
#line 226 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 93 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 239 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 94 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 252 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 97 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new FuncDef(), 3, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
						dynamic_cast<FuncDef*>((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->idTable = TableNode::curNode->children.back();
					
#line 271 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 122 ".\\myparser.y"
 
							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new DecSpec(), 1, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
							dynamic_cast<DecSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecList.push_front(
								dynamic_cast<TypeSpec* >(yyattribute(1 - 1)->type.get())->typeSpecItem
							);
					   
#line 290 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 130 ".\\myparser.y"

						   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new DecSpec(), 2, curLineNo);
						   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
					   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
					   	   DecSpec* tmp = dynamic_cast<DecSpec*>(yyattribute(2 - 2)->type.get());
						   dynamic_cast<DecSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeQualList.assign(
								tmp->typeQualList.begin(), tmp->typeQualList.end());
								
						   dynamic_cast<DecSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())
								->typeQualList.push_front(
									dynamic_cast<TypeQual* >(yyattribute(1 - 2)->type.get())->typeQualItem
								);
					   
#line 315 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 145 ".\\myparser.y"
 
				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "void";
				   dynamic_cast<TypeSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecItem = VOID_T;
			   
#line 332 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "char";
			   	   dynamic_cast<TypeSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecItem = CHAR_T;
			   
#line 349 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 157 ".\\myparser.y"
 
				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "int";
			   	   dynamic_cast<TypeSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecItem = INT_T;
			   
#line 366 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 163 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "float";
			   	   dynamic_cast<TypeSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecItem = FLOAT_T;
			   
#line 383 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 169 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeSpec(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "double";
			       dynamic_cast<TypeSpec* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeSpecItem = DOUBLE_T;
			   
#line 400 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 176 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new TypeQual(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = "const";
				   dynamic_cast<TypeQual* >((*(YYSTYPE YYFAR*)yyvalptr)->type.get())->typeQualItem = CONST_T;
			   
#line 417 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 183 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PointerUse(), 0, curLineNo);
			(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.pointerDegree = 1;
		
#line 433 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 188 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PointerUse(), 2, curLineNo);
			(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.pointerDegree = 1 + yyattribute(2 - 2)->type->attr.pointerDegree;		
		
#line 449 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 193 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 462 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 195 ".\\myparser.y"

			   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new Declarator(), 2, curLineNo);
			   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
			   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
		   
#line 479 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 202 ".\\myparser.y"

					   IdInfo dummy(NON_ID_TYPE_T, NON_QUAL_TYPE_T);
                       if(!TableNode::curNode->insertId(string(curID), dummy)){
							cout<<"syntax error at line: "<<curLineNo<<"\n";
							cout<<"duplicated id name in the same area!\n";
							exit(0);
					   }
					   IdDec* tmp = new IdDec();
					   tmp->table = TableNode::curNode;
					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(tmp, 0, curLineNo);
					   if(curID == NULL) {
						   exit(EXIT_FAILURE);
					   }
					   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = new char[1 + strlen(curID)];
				   	   strcpy_s((*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name, 1 + strlen(curID), curID);
				  
#line 507 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 219 ".\\myparser.y"

					   extraAreaSupportSwitch = false;
					   TableNode::moveDown();
				  
#line 523 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 223 ".\\myparser.y"

		   			   // note that I didn't reduce it as DirDeclarator since we have to deal with the
		   			   // scope issue of Function declaration
			   		   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new FuncDeclarator(), 2, curLineNo);
			   		   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
			   		   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(4 - 5);
		   		  
#line 542 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 233 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ParamList(), 2, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
			   
#line 559 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 238 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 572 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#line 239 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ParamList(), 0, curLineNo); 
#line 580 "myparser.cpp"
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 242 ".\\myparser.y"

						  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ParamDec(), 2, curLineNo);
						  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
						  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
                          GrammarTree::obtainIdInfo((*(YYSTYPE YYFAR*)yyvalptr)->children[0]);
                          GrammarTree::fixIdInfo((*(YYSTYPE YYFAR*)yyvalptr)->children[1], true);
                          GrammarTree::resetIdInfo();
					      
                      
#line 600 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 254 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new Dec(), 2, curLineNo);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
				// first, we don't support the type of function!
				// Note that the bug here implicitly doesn't support function type check
                GrammarTree::obtainIdInfo((*(YYSTYPE YYFAR*)yyvalptr)->children[0]);
                GrammarTree::fixIdInfo((*(YYSTYPE YYFAR*)yyvalptr)->children[1]);
			    GrammarTree::resetIdInfo();
                if(extraAreaSupportSwitch == false){
					if(typeid(*((*(YYSTYPE YYFAR*)yyvalptr)->children[1]->type)) == typeid(FuncDeclarator)){
						extraAreaSupportSwitch = true;
						TableNode::moveUp();
					}
				}
			
#line 628 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 273 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 643 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 277 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new InitDecList(), 2, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					
#line 660 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 284 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new InitDec(), 2, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				
#line 677 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 289 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 690 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 294 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 703 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 297 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 716 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 299 ".\\myparser.y"

			   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new Expr(), 2, curLineNo);
		   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
			   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
		   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = COMMA;
		   
#line 734 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 307 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = ASSIGN;
				  
#line 752 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 314 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = ADDASSIGN;				  
				  
#line 770 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 321 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MINUSASSIGN;				  
				  
#line 788 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 328 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MULASSIGN;				  
				  
#line 806 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 335 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AssignExpr(), 2, curLineNo);
				  	 (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					 (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = DIVASSIGN;				  
				  
#line 824 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 342 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				  
#line 839 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 347 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new LogOrExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LOGICOR;
				  
#line 857 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 354 ".\\myparser.y"
 
					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
				  
#line 872 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 359 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new LogAndExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LOGICAND;
					
#line 890 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 366 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
					
#line 905 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 371 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new BitOrExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = BITOR;
				 
#line 923 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 378 ".\\myparser.y"

					 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				 
#line 938 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 383 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new BitXorExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = BITXOR; 
				  
#line 956 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 390 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				  
#line 971 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 395 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new BitAndExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = BITAND;
				  
#line 989 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 402 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				  
#line 1004 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 407 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new EqualExpr(), 2, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = EQ;
					
#line 1022 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 414 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new EqualExpr(), 2, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
						(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = NEQ;
					
#line 1040 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 421 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
					
#line 1055 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 427 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = GE;
					   
#line 1073 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 434 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LE;					
					   
#line 1091 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 441 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = GT;
					   
#line 1109 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 448 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new NonEqualExpr(), 2, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LT;
						
#line 1127 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 455 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1140 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 458 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ShiftExpr(), 2, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LEFTSHIFT;
				 
#line 1158 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 465 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ShiftExpr(), 2, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
					(*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = RIGHTSHIFT;
				 
#line 1176 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 471 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1189 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 475 ".\\myparser.y"

				  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AddExpr(), 2, curLineNo);
				  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = ADD;
			   
#line 1207 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 482 ".\\myparser.y"

				  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new AddExpr(), 2, curLineNo);
				  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MINUS;			   
			   
#line 1225 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 489 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1238 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 492 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MUL;
			   
#line 1256 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 499 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = DIV;
			   
#line 1274 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 506 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new MulExpr(), 2, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
				   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MODE;				   
			   
#line 1292 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 512 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1305 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 516 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(2 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = MINUS;
				  
#line 1322 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 522 ".\\myparser.y"

				  	  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(2 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = LOGICNOT;
				  
#line 1339 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 528 ".\\myparser.y"

				  	  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(2 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = BITNOT;
				  
#line 1356 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 534 ".\\myparser.y"

				  	  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(2 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = INC;				  
				  
#line 1373 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 540 ".\\myparser.y"

				  	  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrefixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(2 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = DEC;
				  
#line 1390 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 546 ".\\myparser.y"
 
					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
				  
#line 1405 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 551 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				  
#line 1420 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 555 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PostfixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = INC;
				  
#line 1437 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 561 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PostfixExpr(), 1, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
					  (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.optype = DEC;
				  
#line 1454 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 567 ".\\myparser.y"

					  (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new FuncCallExpr(), 2, curLineNo);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
					  (*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 4);
				  
#line 1471 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 574 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
						 
#line 1486 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 578 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new ArgExprList(), 2, curLineNo);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(3 - 3);
						 
#line 1503 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 586 ".\\myparser.y"

					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new StringUse(), 0, curLineNo);
					   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = new char[1 + strlen(curString)];
				   	   strcpy_s((*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name, 1 + strlen(curString), curString);
				   
#line 1520 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 592 ".\\myparser.y"
 
					   IdInfo dummy;
					   if(!TableNode::curNode->lookupId(string(curID), dummy))
					   {
						   cout<<"syntax error at line: "<<curLineNo<<"\n";
					   	   cout<<"id: " << curID << " not declared";
					   	   exit(0);
					   }
					   IdUse* tmp = new IdUse();
					   tmp->table = TableNode::curNode;
					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(tmp, 0, curLineNo);
					   // assert! curID shouldn't be NULL by now!
					   if(curID == NULL) {
						   cout<<"syntax error!\n";
					   	   return;
					   }
					   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name = new char[1 + strlen(curID)];
				   	   strcpy_s((*(YYSTYPE YYFAR*)yyvalptr)->type->attr.name, 1 + strlen(curID), curID);
				   
#line 1551 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 612 ".\\myparser.y"

					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new INumUse(), 0, curLineNo);
				   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.intVal = curInt;
				   
#line 1567 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 617 ".\\myparser.y"

					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new FNumUse(), 0, curLineNo);
				   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.floatVal = curFloat;
				   
#line 1583 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 622 ".\\myparser.y"

					   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new CharUse(), 0, curLineNo);
					   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.charVal = curChar;
				   
#line 1599 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 627 ".\\myparser.y"

					   (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
					   // $$->type->attr.floatVal = curFloat;
				   
#line 1615 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 633 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1628 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 634 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1641 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 635 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1654 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 636 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1667 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 637 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1680 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 638 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1693 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 639 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1706 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 642 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new InputStmt(), 1, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
				
#line 1722 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 648 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new PrintStmt(), 1, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
				
#line 1738 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 655 ".\\myparser.y"

						if(extraAreaSupportSwitch == false){
							extraAreaSupportSwitch = true;
						}else{
							TableNode::moveDown();
						}
					
#line 1757 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 663 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new CmpStmt(), 0, curLineNo);
						TableNode::moveUp();
					
#line 1773 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 668 ".\\myparser.y"

						if(extraAreaSupportSwitch == false){
							extraAreaSupportSwitch = true;
						}else{
							TableNode::moveDown();
						}
				    
#line 1792 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 676 ".\\myparser.y"

					    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 4);
					    TableNode::moveUp();
				    
#line 1808 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 681 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1821 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 683 ".\\myparser.y"

					(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new BlockItemList(), 2, curLineNo);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
					(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
				
#line 1838 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 689 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1851 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 690 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1864 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 692 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new EmptyStmt(),0,curLineNo);
#line 1877 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 693 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 1890 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 697 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new IterStmt(), 2, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
					
#line 1907 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 703 ".\\myparser.y"

						extraAreaSupportSwitch = false; // push it down
						TableNode::moveDown(); // move it down
					
#line 1923 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 708 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(4 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(6 - 8);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(8 - 8);
					
#line 1942 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 716 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(4 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(5 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(7 - 7);
					
#line 1961 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 724 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new IterStmt(), 4, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 6);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(4 - 6);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = make_shared<GrammarNode>(new EmptyStmt(), 0, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(6 - 6);
					
#line 1980 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 734 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new SelStmt(), 2, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 5);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 5);
					
#line 1997 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 740 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new SelStmt(), 3, curLineNo);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(3 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(5 - 7);
						(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(7 - 7);
					
#line 2015 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 748 ".\\myparser.y"
 
				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo); 
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.jmptype = CONTINUE;
			   
#line 2031 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 753 ".\\myparser.y"
 
				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.jmptype = BREAK;
			   
#line 2047 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 758 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new JmpStmt(), 0, curLineNo);
			   	   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.jmptype = RETURN;
			   
#line 2063 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 763 ".\\myparser.y"

				   (*(YYSTYPE YYFAR*)yyvalptr) = make_shared<GrammarNode>(new JmpStmt(), 1, curLineNo);
				   (*(YYSTYPE YYFAR*)yyvalptr)->type->attr.jmptype = RETURN;
			   
#line 2079 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "VOID", 257 },
		{ "CHAR", 258 },
		{ "INT", 259 },
		{ "FLOAT", 260 },
		{ "DOUBLE", 261 },
		{ "IF", 262 },
		{ "FOR", 263 },
		{ "WHILE", 264 },
		{ "RETURN", 265 },
		{ "BREAK", 266 },
		{ "CONTINUE", 267 },
		{ "CONST", 268 },
		{ "LBRACE", 269 },
		{ "RBRACE", 270 },
		{ "LPAREN", 271 },
		{ "RPAREN", 272 },
		{ "INUMBER", 273 },
		{ "FNUMBER", 274 },
		{ "ID", 275 },
		{ "SEMICOLON", 276 },
		{ "STRING_LITERAL", 277 },
		{ "CHAR_LITERAL", 278 },
		{ "INPUT", 279 },
		{ "PRINT", 280 },
		{ "NO_ELSE", 281 },
		{ "ELSE", 282 },
		{ "EMPTY", 283 },
		{ "COMMA", 284 },
		{ "ASSIGN", 285 },
		{ "ADDASSIGN", 286 },
		{ "MINUSASSIGN", 287 },
		{ "MULASSIGN", 288 },
		{ "DIVASSIGN", 289 },
		{ "LOGICOR", 290 },
		{ "LOGICAND", 291 },
		{ "BITOR", 292 },
		{ "BITXOR", 293 },
		{ "BITAND", 294 },
		{ "EQ", 295 },
		{ "NEQ", 296 },
		{ "GT", 297 },
		{ "GE", 298 },
		{ "LT", 299 },
		{ "LE", 300 },
		{ "LEFTSHIFT", 301 },
		{ "RIGHTSHIFT", 302 },
		{ "ADD", 303 },
		{ "MINUS", 304 },
		{ "MUL", 305 },
		{ "DIV", 306 },
		{ "MODE", 307 },
		{ "INC", 308 },
		{ "DEC", 309 },
		{ "UMINUS", 310 },
		{ "LOGICNOT", 311 },
		{ "BITNOT", 312 },
		{ "POST", 313 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: translation_unit",
		"translation_unit: external_declaration",
		"translation_unit: translation_unit external_declaration",
		"external_declaration: function_definition",
		"external_declaration: declaration",
		"function_definition: declaration_specifiers declarator compound_statement",
		"declaration_specifiers: type_specifier",
		"declaration_specifiers: type_qualifier declaration_specifiers",
		"type_specifier: VOID",
		"type_specifier: CHAR",
		"type_specifier: INT",
		"type_specifier: FLOAT",
		"type_specifier: DOUBLE",
		"type_qualifier: CONST",
		"pointer: MUL",
		"pointer: MUL pointer",
		"declarator: direct_declarator",
		"declarator: pointer direct_declarator",
		"direct_declarator: ID",
		"$$1:",
		"direct_declarator: direct_declarator LPAREN $$1 parameter_list RPAREN",
		"parameter_list: parameter_list COMMA parameter_declaration",
		"parameter_list: parameter_declaration",
		"parameter_list:",
		"parameter_declaration: declaration_specifiers declarator",
		"declaration: declaration_specifiers init_declarator_list SEMICOLON",
		"init_declarator_list: init_declarator",
		"init_declarator_list: init_declarator_list COMMA init_declarator",
		"init_declarator: declarator ASSIGN initializer",
		"init_declarator: declarator",
		"initializer: assign_expression",
		"expression: assign_expression",
		"expression: expression COMMA assign_expression",
		"assign_expression: logicor_expression ASSIGN assign_expression",
		"assign_expression: logicor_expression ADDASSIGN assign_expression",
		"assign_expression: logicor_expression MINUSASSIGN assign_expression",
		"assign_expression: logicor_expression MULASSIGN assign_expression",
		"assign_expression: logicor_expression DIVASSIGN assign_expression",
		"assign_expression: logicor_expression",
		"logicor_expression: logicor_expression LOGICOR logicand_expression",
		"logicor_expression: logicand_expression",
		"logicand_expression: logicand_expression LOGICAND bitor_expression",
		"logicand_expression: bitor_expression",
		"bitor_expression: bitor_expression BITOR bitxor_expression",
		"bitor_expression: bitxor_expression",
		"bitxor_expression: bitxor_expression BITXOR bitand_expression",
		"bitxor_expression: bitand_expression",
		"bitand_expression: bitand_expression BITAND equality_expression",
		"bitand_expression: equality_expression",
		"equality_expression: equality_expression EQ nonequality_expression",
		"equality_expression: equality_expression NEQ nonequality_expression",
		"equality_expression: nonequality_expression",
		"nonequality_expression: nonequality_expression GE shift_expression",
		"nonequality_expression: nonequality_expression LE shift_expression",
		"nonequality_expression: nonequality_expression GT shift_expression",
		"nonequality_expression: nonequality_expression LT shift_expression",
		"nonequality_expression: shift_expression",
		"shift_expression: shift_expression LEFTSHIFT add_expression",
		"shift_expression: shift_expression RIGHTSHIFT add_expression",
		"shift_expression: add_expression",
		"add_expression: add_expression ADD mul_expression",
		"add_expression: add_expression MINUS mul_expression",
		"add_expression: mul_expression",
		"mul_expression: mul_expression MUL prefix_expression",
		"mul_expression: mul_expression DIV prefix_expression",
		"mul_expression: mul_expression MODE prefix_expression",
		"mul_expression: prefix_expression",
		"prefix_expression: MINUS prefix_expression",
		"prefix_expression: LOGICNOT prefix_expression",
		"prefix_expression: BITNOT prefix_expression",
		"prefix_expression: INC prefix_expression",
		"prefix_expression: DEC prefix_expression",
		"prefix_expression: postfix_expression",
		"postfix_expression: primary_expression",
		"postfix_expression: postfix_expression INC",
		"postfix_expression: postfix_expression DEC",
		"postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN",
		"argument_expression_list: assign_expression",
		"argument_expression_list: argument_expression_list COMMA assign_expression",
		"primary_expression: STRING_LITERAL",
		"primary_expression: ID",
		"primary_expression: INUMBER",
		"primary_expression: FNUMBER",
		"primary_expression: CHAR_LITERAL",
		"primary_expression: LPAREN expression RPAREN",
		"statement: compound_statement",
		"statement: expression_statement",
		"statement: selection_statement",
		"statement: iteration_statement",
		"statement: jump_statement",
		"statement: input_statement",
		"statement: print_statement",
		"input_statement: INPUT LPAREN primary_expression RPAREN SEMICOLON",
		"print_statement: PRINT LPAREN primary_expression RPAREN SEMICOLON",
		"$$2:",
		"compound_statement: LBRACE $$2 RBRACE",
		"$$3:",
		"compound_statement: LBRACE $$3 block_item_list RBRACE",
		"block_item_list: block_item",
		"block_item_list: block_item_list block_item",
		"block_item: declaration",
		"block_item: statement",
		"expression_statement: SEMICOLON",
		"expression_statement: expression SEMICOLON",
		"iteration_statement: WHILE LPAREN expression RPAREN statement",
		"$$4:",
		"iteration_statement: FOR LPAREN $$4 declaration expression_statement expression RPAREN statement",
		"iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement",
		"iteration_statement: FOR LPAREN expression_statement expression_statement RPAREN statement",
		"selection_statement: IF LPAREN expression RPAREN statement",
		"selection_statement: IF LPAREN expression RPAREN statement ELSE statement",
		"jump_statement: CONTINUE SEMICOLON",
		"jump_statement: BREAK SEMICOLON",
		"jump_statement: RETURN SEMICOLON",
		"jump_statement: RETURN expression SEMICOLON"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 1, 2, 1 },
		{ 2, 1, 2 },
		{ 2, 1, 3 },
		{ 3, 3, 4 },
		{ 4, 1, 5 },
		{ 4, 2, 6 },
		{ 5, 1, 7 },
		{ 5, 1, 8 },
		{ 5, 1, 9 },
		{ 5, 1, 10 },
		{ 5, 1, 11 },
		{ 6, 1, 12 },
		{ 7, 1, 13 },
		{ 7, 2, 14 },
		{ 8, 1, 15 },
		{ 8, 2, 16 },
		{ 9, 1, 17 },
		{ 10, 0, 18 },
		{ 9, 5, 19 },
		{ 11, 3, 20 },
		{ 11, 1, 21 },
		{ 11, 0, 22 },
		{ 12, 2, 23 },
		{ 13, 3, 24 },
		{ 14, 1, 25 },
		{ 14, 3, 26 },
		{ 15, 3, 27 },
		{ 15, 1, 28 },
		{ 16, 1, 29 },
		{ 17, 1, 30 },
		{ 17, 3, 31 },
		{ 18, 3, 32 },
		{ 18, 3, 33 },
		{ 18, 3, 34 },
		{ 18, 3, 35 },
		{ 18, 3, 36 },
		{ 18, 1, 37 },
		{ 19, 3, 38 },
		{ 19, 1, 39 },
		{ 20, 3, 40 },
		{ 20, 1, 41 },
		{ 21, 3, 42 },
		{ 21, 1, 43 },
		{ 22, 3, 44 },
		{ 22, 1, 45 },
		{ 23, 3, 46 },
		{ 23, 1, 47 },
		{ 24, 3, 48 },
		{ 24, 3, 49 },
		{ 24, 1, 50 },
		{ 25, 3, 51 },
		{ 25, 3, 52 },
		{ 25, 3, 53 },
		{ 25, 3, 54 },
		{ 25, 1, 55 },
		{ 26, 3, 56 },
		{ 26, 3, 57 },
		{ 26, 1, 58 },
		{ 27, 3, 59 },
		{ 27, 3, 60 },
		{ 27, 1, 61 },
		{ 28, 3, 62 },
		{ 28, 3, 63 },
		{ 28, 3, 64 },
		{ 28, 1, 65 },
		{ 29, 2, 66 },
		{ 29, 2, 67 },
		{ 29, 2, 68 },
		{ 29, 2, 69 },
		{ 29, 2, 70 },
		{ 29, 1, 71 },
		{ 30, 1, 72 },
		{ 30, 2, 73 },
		{ 30, 2, 74 },
		{ 30, 4, 75 },
		{ 31, 1, 76 },
		{ 31, 3, 77 },
		{ 32, 1, 78 },
		{ 32, 1, 79 },
		{ 32, 1, 80 },
		{ 32, 1, 81 },
		{ 32, 1, 82 },
		{ 32, 3, 83 },
		{ 33, 1, 84 },
		{ 33, 1, 85 },
		{ 33, 1, 86 },
		{ 33, 1, 87 },
		{ 33, 1, 88 },
		{ 33, 1, 89 },
		{ 33, 1, 90 },
		{ 34, 5, 91 },
		{ 35, 5, 92 },
		{ 37, 0, 93 },
		{ 36, 3, 94 },
		{ 38, 0, 95 },
		{ 36, 4, 96 },
		{ 39, 1, 97 },
		{ 39, 2, 98 },
		{ 40, 1, 99 },
		{ 40, 1, 100 },
		{ 41, 1, 101 },
		{ 41, 2, 102 },
		{ 42, 5, 103 },
		{ 43, 0, 104 },
		{ 42, 8, 105 },
		{ 42, 7, 106 },
		{ 42, 6, 107 },
		{ 44, 5, 108 },
		{ 44, 7, 109 },
		{ 45, 2, 110 },
		{ 45, 2, 111 },
		{ 45, 2, 112 },
		{ 45, 3, 113 }
	};
	yyreduction = reduction;

	yytokenaction_size = 167;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 194, YYAT_SHIFT, 63 },
		{ 194, YYAT_SHIFT, 64 },
		{ 194, YYAT_SHIFT, 65 },
		{ 194, YYAT_SHIFT, 66 },
		{ 194, YYAT_SHIFT, 67 },
		{ 194, YYAT_SHIFT, 68 },
		{ 183, YYAT_SHIFT, 190 },
		{ 194, YYAT_SHIFT, 26 },
		{ 191, YYAT_SHIFT, 194 },
		{ 194, YYAT_SHIFT, 35 },
		{ 181, YYAT_SHIFT, 188 },
		{ 194, YYAT_SHIFT, 36 },
		{ 194, YYAT_SHIFT, 37 },
		{ 194, YYAT_SHIFT, 38 },
		{ 194, YYAT_SHIFT, 69 },
		{ 194, YYAT_SHIFT, 39 },
		{ 194, YYAT_SHIFT, 40 },
		{ 194, YYAT_SHIFT, 70 },
		{ 194, YYAT_SHIFT, 71 },
		{ 122, YYAT_SHIFT, 35 },
		{ 191, YYAT_SHIFT, 131 },
		{ 122, YYAT_SHIFT, 36 },
		{ 122, YYAT_SHIFT, 37 },
		{ 122, YYAT_SHIFT, 38 },
		{ 122, YYAT_SHIFT, 69 },
		{ 122, YYAT_SHIFT, 39 },
		{ 122, YYAT_SHIFT, 40 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 56, YYAT_SHIFT, 110 },
		{ 184, YYAT_ERROR, 0 },
		{ 54, YYAT_SHIFT, 103 },
		{ 54, YYAT_SHIFT, 104 },
		{ 54, YYAT_SHIFT, 105 },
		{ 54, YYAT_SHIFT, 106 },
		{ 54, YYAT_SHIFT, 107 },
		{ 54, YYAT_SHIFT, 108 },
		{ 184, YYAT_ERROR, 0 },
		{ 194, YYAT_SHIFT, 41 },
		{ 154, YYAT_SHIFT, 171 },
		{ 184, YYAT_ERROR, 0 },
		{ 184, YYAT_ERROR, 0 },
		{ 194, YYAT_SHIFT, 42 },
		{ 194, YYAT_SHIFT, 43 },
		{ 179, YYAT_SHIFT, 187 },
		{ 194, YYAT_SHIFT, 44 },
		{ 194, YYAT_SHIFT, 45 },
		{ 20, YYAT_SHIFT, 26 },
		{ 122, YYAT_SHIFT, 41 },
		{ 178, YYAT_SHIFT, 186 },
		{ 119, YYAT_SHIFT, 160 },
		{ 154, YYAT_SHIFT, 172 },
		{ 122, YYAT_SHIFT, 42 },
		{ 122, YYAT_SHIFT, 43 },
		{ 176, YYAT_SHIFT, 69 },
		{ 122, YYAT_SHIFT, 44 },
		{ 122, YYAT_SHIFT, 45 },
		{ 84, YYAT_SHIFT, 1 },
		{ 84, YYAT_SHIFT, 2 },
		{ 84, YYAT_SHIFT, 3 },
		{ 84, YYAT_SHIFT, 4 },
		{ 84, YYAT_SHIFT, 5 },
		{ 119, YYAT_SHIFT, 161 },
		{ 20, YYAT_SHIFT, 27 },
		{ 144, YYAT_SHIFT, 113 },
		{ 144, YYAT_SHIFT, 114 },
		{ 56, YYAT_SHIFT, 111 },
		{ 56, YYAT_SHIFT, 112 },
		{ 84, YYAT_SHIFT, 6 },
		{ 175, YYAT_SHIFT, 182 },
		{ 84, YYAT_SHIFT, 132 },
		{ 165, YYAT_SHIFT, 1 },
		{ 165, YYAT_SHIFT, 2 },
		{ 165, YYAT_SHIFT, 3 },
		{ 165, YYAT_SHIFT, 4 },
		{ 165, YYAT_SHIFT, 5 },
		{ 61, YYAT_SHIFT, 1 },
		{ 61, YYAT_SHIFT, 2 },
		{ 61, YYAT_SHIFT, 3 },
		{ 61, YYAT_SHIFT, 4 },
		{ 61, YYAT_SHIFT, 5 },
		{ 129, YYAT_ERROR, 0 },
		{ 165, YYAT_SHIFT, 6 },
		{ 143, YYAT_SHIFT, 113 },
		{ 143, YYAT_SHIFT, 114 },
		{ 129, YYAT_ERROR, 0 },
		{ 129, YYAT_ERROR, 0 },
		{ 61, YYAT_SHIFT, 6 },
		{ 129, YYAT_ERROR, 0 },
		{ 129, YYAT_ERROR, 0 },
		{ 138, YYAT_SHIFT, 96 },
		{ 138, YYAT_SHIFT, 97 },
		{ 138, YYAT_SHIFT, 98 },
		{ 138, YYAT_SHIFT, 99 },
		{ 137, YYAT_SHIFT, 96 },
		{ 137, YYAT_SHIFT, 97 },
		{ 137, YYAT_SHIFT, 98 },
		{ 137, YYAT_SHIFT, 99 },
		{ 50, YYAT_SHIFT, 96 },
		{ 50, YYAT_SHIFT, 97 },
		{ 50, YYAT_SHIFT, 98 },
		{ 50, YYAT_SHIFT, 99 },
		{ 125, YYAT_SHIFT, 167 },
		{ 19, YYAT_SHIFT, 24 },
		{ 156, YYAT_SHIFT, 115 },
		{ 156, YYAT_SHIFT, 116 },
		{ 156, YYAT_SHIFT, 117 },
		{ 155, YYAT_SHIFT, 115 },
		{ 155, YYAT_SHIFT, 116 },
		{ 155, YYAT_SHIFT, 117 },
		{ 125, YYAT_SHIFT, 131 },
		{ 19, YYAT_SHIFT, 25 },
		{ 60, YYAT_SHIFT, 115 },
		{ 60, YYAT_SHIFT, 116 },
		{ 60, YYAT_SHIFT, 117 },
		{ 142, YYAT_SHIFT, 100 },
		{ 142, YYAT_SHIFT, 101 },
		{ 141, YYAT_SHIFT, 100 },
		{ 141, YYAT_SHIFT, 101 },
		{ 140, YYAT_SHIFT, 100 },
		{ 140, YYAT_SHIFT, 101 },
		{ 139, YYAT_SHIFT, 100 },
		{ 139, YYAT_SHIFT, 101 },
		{ 136, YYAT_SHIFT, 94 },
		{ 136, YYAT_SHIFT, 95 },
		{ 59, YYAT_SHIFT, 113 },
		{ 59, YYAT_SHIFT, 114 },
		{ 51, YYAT_SHIFT, 100 },
		{ 51, YYAT_SHIFT, 101 },
		{ 49, YYAT_SHIFT, 94 },
		{ 49, YYAT_SHIFT, 95 },
		{ 169, YYAT_SHIFT, 179 },
		{ 168, YYAT_SHIFT, 178 },
		{ 166, YYAT_SHIFT, 177 },
		{ 163, YYAT_SHIFT, 174 },
		{ 152, YYAT_SHIFT, 92 },
		{ 151, YYAT_SHIFT, 109 },
		{ 145, YYAT_SHIFT, 93 },
		{ 135, YYAT_SHIFT, 102 },
		{ 120, YYAT_SHIFT, 17 },
		{ 86, YYAT_SHIFT, 134 },
		{ 72, YYAT_SHIFT, 130 },
		{ 71, YYAT_SHIFT, 129 },
		{ 70, YYAT_SHIFT, 128 },
		{ 68, YYAT_SHIFT, 127 },
		{ 67, YYAT_SHIFT, 126 },
		{ 66, YYAT_SHIFT, 124 },
		{ 65, YYAT_SHIFT, 123 },
		{ 64, YYAT_SHIFT, 122 },
		{ 63, YYAT_SHIFT, 121 },
		{ 55, YYAT_SHIFT, 109 },
		{ 52, YYAT_SHIFT, 102 },
		{ 47, YYAT_SHIFT, 93 },
		{ 46, YYAT_SHIFT, 92 },
		{ 34, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 62 },
		{ 32, YYAT_SHIFT, 27 },
		{ 29, YYAT_SHIFT, 30 },
		{ 26, YYAT_REDUCE, 94 },
		{ 22, YYAT_SHIFT, 30 },
		{ 21, YYAT_SHIFT, 16 },
		{ 17, YYAT_SHIFT, 17 },
		{ 8, YYAT_ACCEPT, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 165 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 166, 1, YYAT_DEFAULT, 165 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_DEFAULT, 165 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ -140, 1, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ -218, 1, YYAT_REDUCE, 29 },
		{ -111, 1, YYAT_ERROR, 0 },
		{ -108, 1, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_DEFAULT, 120 },
		{ -108, 1, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -110, 1, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ -125, 1, YYAT_REDUCE, 29 },
		{ -111, 1, YYAT_ERROR, 0 },
		{ -112, 1, YYAT_DEFAULT, 84 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ -135, 1, YYAT_REDUCE, 42 },
		{ -138, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -162, 1, YYAT_REDUCE, 48 },
		{ -195, 1, YYAT_REDUCE, 51 },
		{ -170, 1, YYAT_REDUCE, 56 },
		{ -138, 1, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -250, 1, YYAT_REDUCE, 38 },
		{ -137, 1, YYAT_REDUCE, 40 },
		{ -238, 1, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ -174, 1, YYAT_REDUCE, 59 },
		{ -189, 1, YYAT_REDUCE, 62 },
		{ -177, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ -118, 1, YYAT_ERROR, 0 },
		{ -119, 1, YYAT_ERROR, 0 },
		{ -120, 1, YYAT_ERROR, 0 },
		{ -126, 1, YYAT_DEFAULT, 184 },
		{ -127, 1, YYAT_ERROR, 0 },
		{ -128, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ -124, 1, YYAT_ERROR, 0 },
		{ -125, 1, YYAT_ERROR, 0 },
		{ -131, 1, YYAT_DEFAULT, 125 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ -196, 1, YYAT_DEFAULT, 194 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ -128, 1, YYAT_DEFAULT, 191 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -218, 1, YYAT_ERROR, 0 },
		{ -162, 1, YYAT_DEFAULT, 21 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ -252, 1, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ -170, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -219, 1, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ -151, 1, YYAT_REDUCE, 43 },
		{ -168, 1, YYAT_REDUCE, 47 },
		{ -199, 1, YYAT_REDUCE, 49 },
		{ -203, 1, YYAT_REDUCE, 50 },
		{ -176, 1, YYAT_REDUCE, 54 },
		{ -178, 1, YYAT_REDUCE, 52 },
		{ -180, 1, YYAT_REDUCE, 55 },
		{ -182, 1, YYAT_REDUCE, 53 },
		{ -216, 1, YYAT_REDUCE, 57 },
		{ -235, 1, YYAT_REDUCE, 58 },
		{ -153, 1, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ -151, 1, YYAT_REDUCE, 39 },
		{ -153, 1, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ -229, 1, YYAT_ERROR, 0 },
		{ -194, 1, YYAT_REDUCE, 60 },
		{ -197, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_DEFAULT, 165 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -134, 1, YYAT_DEFAULT, 191 },
		{ 0, 0, YYAT_DEFAULT, 176 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -135, 1, YYAT_DEFAULT, 191 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ -136, 1, YYAT_ERROR, 0 },
		{ -137, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 194 },
		{ -199, 1, YYAT_DEFAULT, 184 },
		{ -218, 1, YYAT_DEFAULT, 184 },
		{ 0, 0, YYAT_DEFAULT, 194 },
		{ -223, 1, YYAT_ERROR, 0 },
		{ -228, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ -272, 1, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_DEFAULT, 194 },
		{ -266, 1, YYAT_DEFAULT, 191 },
		{ -235, 1, YYAT_DEFAULT, 194 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_DEFAULT, 194 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_DEFAULT, 194 },
		{ -264, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ -262, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 106 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 129;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 194, 72 },
		{ 194, 73 },
		{ 194, 54 },
		{ 194, 55 },
		{ 194, 46 },
		{ 194, 52 },
		{ 194, 47 },
		{ 194, 49 },
		{ 194, 50 },
		{ 8, 14 },
		{ 8, 12 },
		{ 8, 13 },
		{ 176, 72 },
		{ 184, 191 },
		{ 10, 15 },
		{ 25, 32 },
		{ 194, 195 },
		{ 194, 85 },
		{ 194, 77 },
		{ 194, 75 },
		{ 8, 9 },
		{ 190, 193 },
		{ 25, 31 },
		{ 10, -1 },
		{ 194, 81 },
		{ 194, 82 },
		{ 110, 153 },
		{ 194, 78 },
		{ 194, 83 },
		{ 184, -1 },
		{ 184, -1 },
		{ 184, -1 },
		{ 184, -1 },
		{ 84, 76 },
		{ 84, 11 },
		{ 84, 10 },
		{ 176, 184 },
		{ 184, -1 },
		{ 184, -1 },
		{ 110, 154 },
		{ 184, -1 },
		{ 184, -1 },
		{ 84, 74 },
		{ 165, 76 },
		{ 165, 11 },
		{ 165, 10 },
		{ 109, -1 },
		{ 109, -1 },
		{ 109, -1 },
		{ 109, 152 },
		{ 161, 120 },
		{ 188, 192 },
		{ 165, 176 },
		{ 117, 159 },
		{ 117, 56 },
		{ 122, 164 },
		{ 117, 58 },
		{ 122, 165 },
		{ 161, 173 },
		{ 120, 21 },
		{ 120, 162 },
		{ 120, 22 },
		{ 84, 80 },
		{ 27, 48 },
		{ 182, 189 },
		{ 27, 53 },
		{ 172, -1 },
		{ 172, 180 },
		{ 177, 185 },
		{ 84, 133 },
		{ 114, 156 },
		{ 114, 57 },
		{ 108, 151 },
		{ 108, 46 },
		{ 102, -1 },
		{ 102, 145 },
		{ 101, 144 },
		{ 101, 60 },
		{ 99, 142 },
		{ 99, 59 },
		{ 95, 138 },
		{ 95, 51 },
		{ 93, -1 },
		{ 93, 136 },
		{ 92, -1 },
		{ 92, 135 },
		{ 76, 19 },
		{ 76, 18 },
		{ 61, 119 },
		{ 61, 118 },
		{ 34, 84 },
		{ 34, 79 },
		{ 26, 33 },
		{ 26, 34 },
		{ 0, 8 },
		{ 0, 7 },
		{ 175, 183 },
		{ 174, 181 },
		{ 164, 175 },
		{ 131, 170 },
		{ 129, 169 },
		{ 128, 168 },
		{ 123, 166 },
		{ 121, 163 },
		{ 116, 158 },
		{ 115, 157 },
		{ 113, 155 },
		{ 107, 150 },
		{ 106, 149 },
		{ 105, 148 },
		{ 104, 147 },
		{ 103, 146 },
		{ 100, 143 },
		{ 98, 141 },
		{ 97, 140 },
		{ 96, 139 },
		{ 94, 137 },
		{ 66, 125 },
		{ 45, 91 },
		{ 44, 90 },
		{ 43, 89 },
		{ 42, 88 },
		{ 41, 87 },
		{ 35, 86 },
		{ 30, 61 },
		{ 21, 29 },
		{ 20, 28 },
		{ 17, 23 },
		{ 13, 20 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 93, 8 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 165 },
		{ 0, -1 },
		{ 10, 165 },
		{ 0, -1 },
		{ 0, -1 },
		{ 120, 76 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 120, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 90, -1 },
		{ 116, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 120 },
		{ 55, -1 },
		{ 47, 172 },
		{ 0, -1 },
		{ 0, -1 },
		{ 114, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 51, 84 },
		{ 106, 184 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 93, 117 },
		{ 92, 117 },
		{ 91, 117 },
		{ 90, 117 },
		{ 89, 117 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, 161 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 100, 184 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 72, 25 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 194 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, 109 },
		{ 59, 102 },
		{ 91, 95 },
		{ 55, 99 },
		{ 89, 99 },
		{ 88, 99 },
		{ 87, 99 },
		{ 52, 101 },
		{ 85, 101 },
		{ 49, 114 },
		{ 52, 92 },
		{ 93, 172 },
		{ 92, 172 },
		{ 91, 172 },
		{ 90, 172 },
		{ 89, 172 },
		{ 52, 109 },
		{ 28, 172 },
		{ 8, 172 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, 114 },
		{ 42, 117 },
		{ 76, 117 },
		{ 75, 117 },
		{ 24, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, -1 },
		{ 86, 184 },
		{ 14, 176 },
		{ 85, 184 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 69, -1 },
		{ 68, -1 },
		{ 0, -1 },
		{ 81, 172 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 46, 10 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 176 },
		{ 39, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 184 },
		{ 0, -1 },
		{ 64, 194 },
		{ 79, 184 },
		{ -5, 184 },
		{ 35, 194 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, 194 },
		{ 0, -1 },
		{ -4, 194 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 18, 194 },
		{ 0, -1 },
		{ -12, 194 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -17, 95 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 768 ".\\myparser.y"



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
