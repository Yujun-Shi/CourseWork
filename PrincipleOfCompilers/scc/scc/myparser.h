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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/03/18
* Time: 11:23:40
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 29 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 44 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE shared_ptr<GrammarNode>
#endif

#line 82 "myparser.h"
#define VOID 257
#define CHAR 258
#define INT 259
#define FLOAT 260
#define DOUBLE 261
#define IF 262
#define FOR 263
#define WHILE 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define CONST 268
#define LBRACE 269
#define RBRACE 270
#define LPAREN 271
#define RPAREN 272
#define INUMBER 273
#define FNUMBER 274
#define ID 275
#define SEMICOLON 276
#define STRING_LITERAL 277
#define CHAR_LITERAL 278
#define INPUT 279
#define PRINT 280
#define NO_ELSE 281
#define ELSE 282
#define EMPTY 283
#define COMMA 284
#define ASSIGN 285
#define ADDASSIGN 286
#define MINUSASSIGN 287
#define MULASSIGN 288
#define DIVASSIGN 289
#define LOGICOR 290
#define LOGICAND 291
#define BITOR 292
#define BITXOR 293
#define BITAND 294
#define EQ 295
#define NEQ 296
#define GT 297
#define GE 298
#define LT 299
#define LE 300
#define LEFTSHIFT 301
#define RIGHTSHIFT 302
#define ADD 303
#define MINUS 304
#define MUL 305
#define DIV 306
#define MODE 307
#define INC 308
#define DEC 309
#define UMINUS 310
#define LOGICNOT 311
#define BITNOT 312
#define POST 313
#endif
