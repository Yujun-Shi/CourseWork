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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 01/03/18
* Time: 11:23:40
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2017.11.18
****************************************************************************/

#include "myparser.h"
#include "GrammarTree.h"

#line 50 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 25 ".\\mylexer.l"

	// place any extra initialisation code here

#line 74 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 30 ".\\mylexer.l"

	// place any extra cleanup code here

#line 86 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 89 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 157 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 95 ".\\mylexer.l"
 /* JUST SKIP */ 
#line 164 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 96 ".\\mylexer.l"

	for(char* iter = yytext; *iter != '\0';++iter){
		if(*iter == '\n'){
			++curLineNo;
		}
	}

#line 177 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 103 ".\\mylexer.l"
 /*JUST SKIP*/ 
#line 184 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 104 ".\\mylexer.l"
 ++curLineNo; 
#line 191 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 105 ".\\mylexer.l"
 return ADD; 
#line 198 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 106 ".\\mylexer.l"
 return MINUS; 
#line 205 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 107 ".\\mylexer.l"
 return MUL; 
#line 212 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 108 ".\\mylexer.l"
 return DIV; 
#line 219 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 109 ".\\mylexer.l"
 return ASSIGN; 
#line 226 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 110 ".\\mylexer.l"
 return EQ; 
#line 233 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 111 ".\\mylexer.l"
 return NEQ; 
#line 240 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 112 ".\\mylexer.l"
 return GE; 
#line 247 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 113 ".\\mylexer.l"
 return LE; 
#line 254 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 114 ".\\mylexer.l"
 return GT; 
#line 261 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 115 ".\\mylexer.l"
 return LT; 
#line 268 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 116 ".\\mylexer.l"
 return ADDASSIGN; 
#line 275 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 117 ".\\mylexer.l"
 return MINUSASSIGN; 
#line 282 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 118 ".\\mylexer.l"
 return MULASSIGN; 
#line 289 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 119 ".\\mylexer.l"
 return DIVASSIGN; 
#line 296 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 122 ".\\mylexer.l"
 return VOID; 
#line 303 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 123 ".\\mylexer.l"
 return CHAR; 
#line 310 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 124 ".\\mylexer.l"
 return INT; 
#line 317 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 125 ".\\mylexer.l"
 return FLOAT; 
#line 324 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 126 ".\\mylexer.l"
 return DOUBLE; 
#line 331 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 128 ".\\mylexer.l"
 return IF; 
#line 338 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 129 ".\\mylexer.l"
 return ELSE; 
#line 345 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 130 ".\\mylexer.l"
 return FOR; 
#line 352 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 131 ".\\mylexer.l"
 return WHILE; 
#line 359 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 132 ".\\mylexer.l"
 return RETURN; 
#line 366 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 133 ".\\mylexer.l"
 return BREAK; 
#line 373 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 134 ".\\mylexer.l"
 return CONTINUE; 
#line 380 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 135 ".\\mylexer.l"
 return CONST; 
#line 387 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 137 ".\\mylexer.l"
return INPUT;
#line 394 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 138 ".\\mylexer.l"
return PRINT;
#line 401 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 140 ".\\mylexer.l"
 return COMMA; 
#line 408 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 141 ".\\mylexer.l"
 return SEMICOLON; 
#line 415 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 142 ".\\mylexer.l"
 return LBRACE; 
#line 422 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 143 ".\\mylexer.l"
 return RBRACE; 
#line 429 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 144 ".\\mylexer.l"
 return LPAREN; 
#line 436 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 145 ".\\mylexer.l"
 return RPAREN; 
#line 443 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 147 ".\\mylexer.l"
 return MODE; 
#line 450 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 148 ".\\mylexer.l"
 return BITNOT; 
#line 457 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 149 ".\\mylexer.l"
 return LOGICNOT; 
#line 464 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 150 ".\\mylexer.l"
 return BITAND; 
#line 471 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 151 ".\\mylexer.l"
 return BITOR; 
#line 478 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 152 ".\\mylexer.l"
 return BITXOR; 
#line 485 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 153 ".\\mylexer.l"
 return LEFTSHIFT; 
#line 492 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 154 ".\\mylexer.l"
 return RIGHTSHIFT; 
#line 499 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 155 ".\\mylexer.l"
 return LOGICAND; 
#line 506 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 156 ".\\mylexer.l"
 return LOGICOR; 
#line 513 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 158 ".\\mylexer.l"
 curInt = atoi(yytext); return INUMBER; 
#line 520 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 159 ".\\mylexer.l"
 curFloat = atof(yytext); return FNUMBER; 
#line 527 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 160 ".\\mylexer.l"
 curID = yytext; return ID; 
#line 534 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 161 ".\\mylexer.l"
 return INC; 
#line 541 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 162 ".\\mylexer.l"
 return DEC; 
#line 548 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 163 ".\\mylexer.l"
 curString = yytext; return STRING_LITERAL; 
#line 555 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 164 ".\\mylexer.l"
 curChar = yytext[1]; return CHAR_LITERAL; 
#line 562 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 248;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 39, 73 },
		{ 0, 9 },
		{ 3, 3 },
		{ 0, 53 },
		{ 84, 67 },
		{ 50, 16 },
		{ 43, 9 },
		{ 70, 32 },
		{ 85, 67 },
		{ 53, 17 },
		{ 51, 16 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 3, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 52, 16 },
		{ 3, 3 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 0, 53 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 71, 33 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 46, 13 },
		{ 48, 15 },
		{ 0, 15 },
		{ 0, 13 },
		{ 66, 29 },
		{ 75, 50 },
		{ 40, 73 },
		{ 44, 9 },
		{ 60, 25 },
		{ 72, 35 },
		{ 0, 50 },
		{ 64, 28 },
		{ 67, 29 },
		{ 73, 40 },
		{ 65, 28 },
		{ 61, 25 },
		{ 74, 43 },
		{ 49, 15 },
		{ 47, 13 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 105, 105 },
		{ 42, 44 },
		{ 104, 91 },
		{ 23, 1 },
		{ 104, 91 },
		{ 54, 19 },
		{ 55, 19 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 57, 21 },
		{ 58, 21 },
		{ 29, 1 },
		{ 94, 79 },
		{ 95, 79 },
		{ 45, 12 },
		{ 0, 51 },
		{ 59, 24 },
		{ 77, 59 },
		{ 30, 1 },
		{ 78, 60 },
		{ 31, 1 },
		{ 79, 61 },
		{ 80, 62 },
		{ 81, 63 },
		{ 32, 1 },
		{ 33, 1 },
		{ 82, 64 },
		{ 83, 65 },
		{ 41, 8 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 86, 68 },
		{ 87, 69 },
		{ 88, 70 },
		{ 89, 71 },
		{ 62, 26 },
		{ 90, 75 },
		{ 63, 27 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 92, 77 },
		{ 93, 78 },
		{ 38, 5 },
		{ 96, 80 },
		{ 22, 119 },
		{ 97, 81 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 22, 119 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 98, 82 },
		{ 99, 84 },
		{ 100, 86 },
		{ 101, 87 },
		{ 102, 88 },
		{ 103, 89 },
		{ 56, 20 },
		{ 106, 92 },
		{ 107, 94 },
		{ 108, 95 },
		{ 109, 96 },
		{ 91, 76 },
		{ 110, 98 },
		{ 111, 99 },
		{ 112, 100 },
		{ 113, 101 },
		{ 114, 103 },
		{ 68, 30 },
		{ 115, 108 },
		{ 116, 109 },
		{ 117, 113 },
		{ 118, 115 },
		{ 119, 118 },
		{ 69, 31 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 91, 76 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 119, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -4, 3 },
		{ 0, 0, 4 },
		{ 0, 103, 43 },
		{ 73, 0, 0 },
		{ 0, 0, 41 },
		{ 0, 76, 44 },
		{ -42, -30, 0 },
		{ 0, 0, 39 },
		{ 0, 0, 40 },
		{ 0, 39, 7 },
		{ 17, 12, 5 },
		{ 0, 0, 35 },
		{ 17, 11, 6 },
		{ 0, -34, 8 },
		{ 0, -34, 51 },
		{ 0, 0, 36 },
		{ 0, 28, 15 },
		{ 0, 149, 9 },
		{ 0, 34, 14 },
		{ 119, 0, 53 },
		{ 0, 0, 46 },
		{ 119, -12, 53 },
		{ 119, -41, 53 },
		{ 119, 22, 53 },
		{ 119, 27, 53 },
		{ 119, -42, 53 },
		{ 119, -43, 53 },
		{ 119, 107, 53 },
		{ 119, 126, 53 },
		{ 119, -101, 53 },
		{ 119, -54, 53 },
		{ 0, 0, 37 },
		{ 0, -60, 45 },
		{ 0, 0, 38 },
		{ 0, 0, 42 },
		{ 0, 0, 11 },
		{ 0, 0, 56 },
		{ 73, 34, 0 },
		{ 0, 0, 49 },
		{ 43, 0, 0 },
		{ 0, 32, 57 },
		{ 43, 50, 0 },
		{ 0, 0, 18 },
		{ 0, 0, 54 },
		{ 0, 0, 16 },
		{ 0, 0, 55 },
		{ 0, 0, 17 },
		{ -50, 18, 0 },
		{ -51, 91, 1 },
		{ 0, 0, 19 },
		{ 76, -63, 0 },
		{ 0, 0, 47 },
		{ 0, 0, 13 },
		{ 0, 0, 10 },
		{ 0, 0, 12 },
		{ 0, 0, 48 },
		{ 119, 2, 53 },
		{ 119, 8, 53 },
		{ 119, -3, 53 },
		{ 119, -9, 53 },
		{ 119, -6, 53 },
		{ 119, 1, 53 },
		{ 119, -1, 53 },
		{ 119, 0, 25 },
		{ 119, -105, 53 },
		{ 119, 24, 53 },
		{ 119, 14, 53 },
		{ 119, 26, 53 },
		{ 119, 27, 53 },
		{ 0, 0, 50 },
		{ -6, -31, 56 },
		{ 0, 0, 57 },
		{ -50, 87, 0 },
		{ 0, 146, 52 },
		{ 119, 65, 53 },
		{ 119, 49, 53 },
		{ 119, -17, 53 },
		{ 119, 67, 53 },
		{ 119, 66, 53 },
		{ 119, 107, 53 },
		{ 119, 0, 27 },
		{ 119, 88, 53 },
		{ 119, 0, 22 },
		{ 119, 96, 53 },
		{ 119, 90, 53 },
		{ 119, 108, 53 },
		{ 119, 101, 53 },
		{ 0, 0, 2 },
		{ 105, 42, 0 },
		{ 119, 104, 53 },
		{ 119, 0, 21 },
		{ 119, 96, 53 },
		{ 119, 108, 53 },
		{ 119, 106, 53 },
		{ 119, 0, 26 },
		{ 119, 100, 53 },
		{ 119, 101, 53 },
		{ 119, 102, 53 },
		{ 119, 105, 53 },
		{ 119, 0, 20 },
		{ 119, 119, 53 },
		{ 105, 0, 0 },
		{ 0, 26, 52 },
		{ 119, 0, 30 },
		{ 119, 0, 32 },
		{ 119, 112, 53 },
		{ 119, 122, 53 },
		{ 119, 0, 23 },
		{ 119, 0, 33 },
		{ 119, 0, 34 },
		{ 119, 114, 53 },
		{ 119, 0, 28 },
		{ 119, 108, 53 },
		{ 119, 0, 24 },
		{ 119, 0, 29 },
		{ 119, 125, 53 },
		{ 0, 71, 31 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 165 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


