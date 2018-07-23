%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2017.11.18
****************************************************************************/

#include "myparser.h"
#include "GrammarTree.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

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

// place any declarations here
singleLineComment \/\/.*
mulLineComment \/\*([^\*\/]|\*[^\/])*\*\/
delim [ \t]
whitespace {delim}+
newline [\n]
add \+
minus \-
mul \*
div \/
assign \=
neq \!=
eq \==
ge \>=
le \<=
gt \>
lt \<
addassign \+=
minusassign \-=
mulassign \*=
divassign \/=

comma \,
semicolon \;
lbrace \{
rbrace \}
lparen \(
rparen \)

mode \%
bitnot \~
logicnot \!
bitand \&
bitor \|
bitxor \^
leftshift \<\<
rightshift \>\>
logicand \&\&
logicor \|\|

intNumber (\+|\-)?([0-9])+
floatNumber (\+|\-)?([0-9])+(\.([0-9])+((\E|\e)(\+|\-)?([0-9])+)?)?
id [a-zA-Z_](([a-zA-Z0-9_])+)?
stringLiteral \"([^\"]|\\\")*\"
charLiteral \'([^\"]|\\\")?\'
// prefix and postfix expression
inc \+\+
dec \-\-


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{singleLineComment} { /* JUST SKIP */ }
{mulLineComment} {
	for(char* iter = yytext; *iter != '\0';++iter){
		if(*iter == '\n'){
			++curLineNo;
		}
	}
}
{whitespace} { /*JUST SKIP*/ }
{newline} { ++curLineNo; }
{add} { return ADD; }
{minus} { return MINUS; }
{mul} { return MUL; }
{div} { return DIV; }
{assign} { return ASSIGN; }
{eq} { return EQ; }
{neq} { return NEQ; }
{ge} { return GE; }
{le} { return LE; }
{gt} { return GT; }
{lt} { return LT; }
{addassign} { return ADDASSIGN; }
{minusassign} { return MINUSASSIGN; }
{mulassign} { return MULASSIGN; }
{divassign} { return DIVASSIGN; }


"void" { return VOID; }
"char" { return CHAR; }
"int" { return INT; }
"float" { return FLOAT; }
"double" { return DOUBLE; }

"if" { return IF; }
"else" { return ELSE; }
"for" { return FOR; }
"while" { return WHILE; }
"return" { return RETURN; }
"break" { return BREAK; }
"continue" { return CONTINUE; }
"const" { return CONST; }

"input"		{return INPUT;}
"print"		{return PRINT;}

{comma} { return COMMA; }
{semicolon} { return SEMICOLON; }
{lbrace} { return LBRACE; }
{rbrace} { return RBRACE; }
{lparen} { return LPAREN; }
{rparen} { return RPAREN; }

{mode} { return MODE; }
{bitnot} { return BITNOT; }
{logicnot} { return LOGICNOT; }
{bitand} { return BITAND; }
{bitor} { return BITOR; }
{bitxor} { return BITXOR; }
{leftshift} { return LEFTSHIFT; }
{rightshift} { return RIGHTSHIFT; }
{logicand} { return LOGICAND; }
{logicor} { return LOGICOR; }

{intNumber} { curInt = atoi(yytext); return INUMBER; }
{floatNumber} { curFloat = atof(yytext); return FNUMBER; }
{id} { curID = yytext; return ID; } 
{inc} { return INC; }
{dec} { return DEC; }
{stringLiteral} { curString = yytext; return STRING_LITERAL; }
{charLiteral} { curChar = yytext[1]; return CHAR_LITERAL; }
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

