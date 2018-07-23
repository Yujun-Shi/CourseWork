#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 112 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 01/03/18
# Time: 11:23:40
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

    1  translation_unit : external_declaration
    2                   | translation_unit external_declaration

    3  external_declaration : function_definition
    4                       | declaration

    5  function_definition : declaration_specifiers declarator compound_statement

    6  declaration_specifiers : type_specifier
    7                         | type_qualifier declaration_specifiers

    8  type_specifier : VOID
    9                 | CHAR
   10                 | INT
   11                 | FLOAT
   12                 | DOUBLE

   13  type_qualifier : CONST

   14  pointer : MUL
   15          | MUL pointer

   16  declarator : direct_declarator
   17             | pointer direct_declarator

   18  direct_declarator : ID

   19  $$1 :

   20  direct_declarator : direct_declarator LPAREN $$1 parameter_list RPAREN

   21  parameter_list : parameter_list COMMA parameter_declaration
   22                 | parameter_declaration
   23                 |

   24  parameter_declaration : declaration_specifiers declarator

   25  declaration : declaration_specifiers init_declarator_list SEMICOLON

   26  init_declarator_list : init_declarator
   27                       | init_declarator_list COMMA init_declarator

   28  init_declarator : declarator ASSIGN initializer
   29                  | declarator

   30  initializer : assign_expression

   31  expression : assign_expression
   32             | expression COMMA assign_expression

   33  assign_expression : logicor_expression ASSIGN assign_expression
   34                    | logicor_expression ADDASSIGN assign_expression
   35                    | logicor_expression MINUSASSIGN assign_expression
   36                    | logicor_expression MULASSIGN assign_expression
   37                    | logicor_expression DIVASSIGN assign_expression
   38                    | logicor_expression

   39  logicor_expression : logicor_expression LOGICOR logicand_expression
   40                     | logicand_expression

   41  logicand_expression : logicand_expression LOGICAND bitor_expression
   42                      | bitor_expression

   43  bitor_expression : bitor_expression BITOR bitxor_expression
   44                   | bitxor_expression

   45  bitxor_expression : bitxor_expression BITXOR bitand_expression
   46                    | bitand_expression

   47  bitand_expression : bitand_expression BITAND equality_expression
   48                    | equality_expression

   49  equality_expression : equality_expression EQ nonequality_expression
   50                      | equality_expression NEQ nonequality_expression
   51                      | nonequality_expression

   52  nonequality_expression : nonequality_expression GE shift_expression
   53                         | nonequality_expression LE shift_expression
   54                         | nonequality_expression GT shift_expression
   55                         | nonequality_expression LT shift_expression
   56                         | shift_expression

   57  shift_expression : shift_expression LEFTSHIFT add_expression
   58                   | shift_expression RIGHTSHIFT add_expression
   59                   | add_expression

   60  add_expression : add_expression ADD mul_expression
   61                 | add_expression MINUS mul_expression
   62                 | mul_expression

   63  mul_expression : mul_expression MUL prefix_expression
   64                 | mul_expression DIV prefix_expression
   65                 | mul_expression MODE prefix_expression
   66                 | prefix_expression

   67  prefix_expression : MINUS prefix_expression
   68                    | LOGICNOT prefix_expression
   69                    | BITNOT prefix_expression
   70                    | INC prefix_expression
   71                    | DEC prefix_expression
   72                    | postfix_expression

   73  postfix_expression : primary_expression
   74                     | postfix_expression INC
   75                     | postfix_expression DEC
   76                     | postfix_expression LPAREN argument_expression_list RPAREN

   77  argument_expression_list : assign_expression
   78                           | argument_expression_list COMMA assign_expression

   79  primary_expression : STRING_LITERAL
   80                     | ID
   81                     | INUMBER
   82                     | FNUMBER
   83                     | CHAR_LITERAL
   84                     | LPAREN expression RPAREN

   85  statement : compound_statement
   86            | expression_statement
   87            | selection_statement
   88            | iteration_statement
   89            | jump_statement
   90            | input_statement
   91            | print_statement

   92  input_statement : INPUT LPAREN primary_expression RPAREN SEMICOLON

   93  print_statement : PRINT LPAREN primary_expression RPAREN SEMICOLON

   94  $$2 :

   95  compound_statement : LBRACE $$2 RBRACE

   96  $$3 :

   97  compound_statement : LBRACE $$3 block_item_list RBRACE

   98  block_item_list : block_item
   99                  | block_item_list block_item

  100  block_item : declaration
  101             | statement

  102  expression_statement : SEMICOLON
  103                       | expression SEMICOLON

  104  iteration_statement : WHILE LPAREN expression RPAREN statement

  105  $$4 :

  106  iteration_statement : FOR LPAREN $$4 declaration expression_statement expression RPAREN statement
  107                      | FOR LPAREN expression_statement expression_statement expression RPAREN statement
  108                      | FOR LPAREN expression_statement expression_statement RPAREN statement

  109  selection_statement : IF LPAREN expression RPAREN statement
  110                      | IF LPAREN expression RPAREN statement ELSE statement

  111  jump_statement : CONTINUE SEMICOLON
  112                 | BREAK SEMICOLON
  113                 | RETURN SEMICOLON
  114                 | RETURN expression SEMICOLON


##############################################################################
# States
##############################################################################

state 0
	$accept : . translation_unit $end

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6

	external_declaration  goto 7
	translation_unit  goto 8
	declaration  goto 9
	type_qualifier  goto 10
	type_specifier  goto 11
	function_definition  goto 12
	declaration_specifiers  goto 13


state 1
	type_specifier : VOID .  (8)

	.  reduce 8


state 2
	type_specifier : CHAR .  (9)

	.  reduce 9


state 3
	type_specifier : INT .  (10)

	.  reduce 10


state 4
	type_specifier : FLOAT .  (11)

	.  reduce 11


state 5
	type_specifier : DOUBLE .  (12)

	.  reduce 12


state 6
	type_qualifier : CONST .  (13)

	.  reduce 13


state 7
	translation_unit : external_declaration .  (1)

	.  reduce 1


state 8
	$accept : translation_unit . $end  (0)
	translation_unit : translation_unit . external_declaration

	$end  accept
	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6

	external_declaration  goto 14
	declaration  goto 9
	type_qualifier  goto 10
	type_specifier  goto 11
	function_definition  goto 12
	declaration_specifiers  goto 13


state 9
	external_declaration : declaration .  (4)

	.  reduce 4


state 10
	declaration_specifiers : type_qualifier . declaration_specifiers

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6

	type_qualifier  goto 10
	type_specifier  goto 11
	declaration_specifiers  goto 15


state 11
	declaration_specifiers : type_specifier .  (6)

	.  reduce 6


state 12
	external_declaration : function_definition .  (3)

	.  reduce 3


state 13
	function_definition : declaration_specifiers . declarator compound_statement
	declaration : declaration_specifiers . init_declarator_list SEMICOLON

	ID  shift 16
	MUL  shift 17

	init_declarator  goto 18
	init_declarator_list  goto 19
	declarator  goto 20
	pointer  goto 21
	direct_declarator  goto 22


state 14
	translation_unit : translation_unit external_declaration .  (2)

	.  reduce 2


state 15
	declaration_specifiers : type_qualifier declaration_specifiers .  (7)

	.  reduce 7


state 16
	direct_declarator : ID .  (18)

	.  reduce 18


state 17
	pointer : MUL .  (14)
	pointer : MUL . pointer

	MUL  shift 17
	.  reduce 14

	pointer  goto 23


state 18
	init_declarator_list : init_declarator .  (26)

	.  reduce 26


state 19
	declaration : declaration_specifiers init_declarator_list . SEMICOLON
	init_declarator_list : init_declarator_list . COMMA init_declarator

	SEMICOLON  shift 24
	COMMA  shift 25


state 20
	function_definition : declaration_specifiers declarator . compound_statement
	init_declarator : declarator . ASSIGN initializer
	init_declarator : declarator .  (29)

	LBRACE  shift 26
	ASSIGN  shift 27
	.  reduce 29

	compound_statement  goto 28


state 21
	declarator : pointer . direct_declarator

	ID  shift 16

	direct_declarator  goto 29


state 22
	declarator : direct_declarator .  (16)
	direct_declarator : direct_declarator . LPAREN $$1 parameter_list RPAREN

	LPAREN  shift 30
	.  reduce 16


state 23
	pointer : MUL pointer .  (15)

	.  reduce 15


state 24
	declaration : declaration_specifiers init_declarator_list SEMICOLON .  (25)

	.  reduce 25


state 25
	init_declarator_list : init_declarator_list COMMA . init_declarator

	ID  shift 16
	MUL  shift 17

	init_declarator  goto 31
	declarator  goto 32
	pointer  goto 21
	direct_declarator  goto 22


state 26
	compound_statement : LBRACE . $$3 block_item_list RBRACE
	compound_statement : LBRACE . $$2 RBRACE
	$$2 : .  (94)
	$$3 : .  (96)

	RBRACE  reduce 94
	.  reduce 96

	$$2  goto 33
	$$3  goto 34


state 27
	init_declarator : declarator ASSIGN . initializer

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	initializer  goto 48
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 53
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 28
	function_definition : declaration_specifiers declarator compound_statement .  (5)

	.  reduce 5


state 29
	declarator : pointer direct_declarator .  (17)
	direct_declarator : direct_declarator . LPAREN $$1 parameter_list RPAREN

	LPAREN  shift 30
	.  reduce 17


state 30
	direct_declarator : direct_declarator LPAREN . $$1 parameter_list RPAREN
	$$1 : .  (19)

	.  reduce 19

	$$1  goto 61


state 31
	init_declarator_list : init_declarator_list COMMA init_declarator .  (27)

	.  reduce 27


state 32
	init_declarator : declarator . ASSIGN initializer
	init_declarator : declarator .  (29)

	ASSIGN  shift 27
	.  reduce 29


state 33
	compound_statement : LBRACE $$2 . RBRACE

	RBRACE  shift 62


state 34
	compound_statement : LBRACE $$3 . block_item_list RBRACE

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	CONST  shift 6
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	declaration  goto 74
	compound_statement  goto 75
	type_qualifier  goto 10
	type_specifier  goto 11
	declaration_specifiers  goto 76
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	block_item  goto 79
	statement  goto 80
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	block_item_list  goto 84
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 35
	primary_expression : LPAREN . expression RPAREN

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 86
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 36
	primary_expression : INUMBER .  (81)

	.  reduce 81


state 37
	primary_expression : FNUMBER .  (82)

	.  reduce 82


state 38
	primary_expression : ID .  (80)

	.  reduce 80


state 39
	primary_expression : STRING_LITERAL .  (79)

	.  reduce 79


state 40
	primary_expression : CHAR_LITERAL .  (83)

	.  reduce 83


state 41
	prefix_expression : MINUS . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 87
	primary_expression  goto 58


state 42
	prefix_expression : INC . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 88
	primary_expression  goto 58


state 43
	prefix_expression : DEC . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 89
	primary_expression  goto 58


state 44
	prefix_expression : LOGICNOT . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 90
	primary_expression  goto 58


state 45
	prefix_expression : BITNOT . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 91
	primary_expression  goto 58


state 46
	bitor_expression : bitor_expression . BITOR bitxor_expression
	logicand_expression : bitor_expression .  (42)

	BITOR  shift 92
	.  reduce 42


state 47
	bitxor_expression : bitand_expression .  (46)
	bitand_expression : bitand_expression . BITAND equality_expression

	BITAND  shift 93
	.  reduce 46


state 48
	init_declarator : declarator ASSIGN initializer .  (28)

	.  reduce 28


state 49
	bitand_expression : equality_expression .  (48)
	equality_expression : equality_expression . EQ nonequality_expression
	equality_expression : equality_expression . NEQ nonequality_expression

	EQ  shift 94
	NEQ  shift 95
	.  reduce 48


state 50
	nonequality_expression : nonequality_expression . LE shift_expression
	nonequality_expression : nonequality_expression . LT shift_expression
	nonequality_expression : nonequality_expression . GT shift_expression
	equality_expression : nonequality_expression .  (51)
	nonequality_expression : nonequality_expression . GE shift_expression

	GT  shift 96
	GE  shift 97
	LT  shift 98
	LE  shift 99
	.  reduce 51


state 51
	shift_expression : shift_expression . LEFTSHIFT add_expression
	shift_expression : shift_expression . RIGHTSHIFT add_expression
	nonequality_expression : shift_expression .  (56)

	LEFTSHIFT  shift 100
	RIGHTSHIFT  shift 101
	.  reduce 56


state 52
	bitor_expression : bitxor_expression .  (44)
	bitxor_expression : bitxor_expression . BITXOR bitand_expression

	BITXOR  shift 102
	.  reduce 44


state 53
	initializer : assign_expression .  (30)

	.  reduce 30


state 54
	assign_expression : logicor_expression . ASSIGN assign_expression
	assign_expression : logicor_expression . MULASSIGN assign_expression
	assign_expression : logicor_expression . MINUSASSIGN assign_expression
	logicor_expression : logicor_expression . LOGICOR logicand_expression
	assign_expression : logicor_expression . DIVASSIGN assign_expression
	assign_expression : logicor_expression .  (38)
	assign_expression : logicor_expression . ADDASSIGN assign_expression

	ASSIGN  shift 103
	ADDASSIGN  shift 104
	MINUSASSIGN  shift 105
	MULASSIGN  shift 106
	DIVASSIGN  shift 107
	LOGICOR  shift 108
	.  reduce 38


state 55
	logicand_expression : logicand_expression . LOGICAND bitor_expression
	logicor_expression : logicand_expression .  (40)

	LOGICAND  shift 109
	.  reduce 40


state 56
	prefix_expression : postfix_expression .  (72)
	postfix_expression : postfix_expression . INC
	postfix_expression : postfix_expression . DEC
	postfix_expression : postfix_expression . LPAREN argument_expression_list RPAREN

	LPAREN  shift 110
	INC  shift 111
	DEC  shift 112
	.  reduce 72


state 57
	mul_expression : prefix_expression .  (66)

	.  reduce 66


state 58
	postfix_expression : primary_expression .  (73)

	.  reduce 73


state 59
	add_expression : add_expression . MINUS mul_expression
	shift_expression : add_expression .  (59)
	add_expression : add_expression . ADD mul_expression

	ADD  shift 113
	MINUS  shift 114
	.  reduce 59


state 60
	mul_expression : mul_expression . MUL prefix_expression
	mul_expression : mul_expression . DIV prefix_expression
	mul_expression : mul_expression . MODE prefix_expression
	add_expression : mul_expression .  (62)

	MUL  shift 115
	DIV  shift 116
	MODE  shift 117
	.  reduce 62


state 61
	direct_declarator : direct_declarator LPAREN $$1 . parameter_list RPAREN
	parameter_list : .  (23)

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6
	.  reduce 23

	parameter_declaration  goto 118
	type_qualifier  goto 10
	type_specifier  goto 11
	parameter_list  goto 119
	declaration_specifiers  goto 120


state 62
	compound_statement : LBRACE $$2 RBRACE .  (95)

	.  reduce 95


state 63
	selection_statement : IF . LPAREN expression RPAREN statement ELSE statement
	selection_statement : IF . LPAREN expression RPAREN statement

	LPAREN  shift 121


state 64
	iteration_statement : FOR . LPAREN expression_statement expression_statement expression RPAREN statement
	iteration_statement : FOR . LPAREN expression_statement expression_statement RPAREN statement
	iteration_statement : FOR . LPAREN $$4 declaration expression_statement expression RPAREN statement

	LPAREN  shift 122


state 65
	iteration_statement : WHILE . LPAREN expression RPAREN statement

	LPAREN  shift 123


state 66
	jump_statement : RETURN . SEMICOLON
	jump_statement : RETURN . expression SEMICOLON

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 124
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 125
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 67
	jump_statement : BREAK . SEMICOLON

	SEMICOLON  shift 126


state 68
	jump_statement : CONTINUE . SEMICOLON

	SEMICOLON  shift 127


state 69
	expression_statement : SEMICOLON .  (102)

	.  reduce 102


state 70
	input_statement : INPUT . LPAREN primary_expression RPAREN SEMICOLON

	LPAREN  shift 128


state 71
	print_statement : PRINT . LPAREN primary_expression RPAREN SEMICOLON

	LPAREN  shift 129


state 72
	expression : expression . COMMA assign_expression
	expression_statement : expression . SEMICOLON

	SEMICOLON  shift 130
	COMMA  shift 131


state 73
	expression : assign_expression .  (31)

	.  reduce 31


state 74
	block_item : declaration .  (100)

	.  reduce 100


state 75
	statement : compound_statement .  (85)

	.  reduce 85


state 76
	declaration : declaration_specifiers . init_declarator_list SEMICOLON

	ID  shift 16
	MUL  shift 17

	init_declarator  goto 18
	init_declarator_list  goto 19
	declarator  goto 32
	pointer  goto 21
	direct_declarator  goto 22


state 77
	statement : print_statement .  (91)

	.  reduce 91


state 78
	statement : selection_statement .  (87)

	.  reduce 87


state 79
	block_item_list : block_item .  (98)

	.  reduce 98


state 80
	block_item : statement .  (101)

	.  reduce 101


state 81
	statement : expression_statement .  (86)

	.  reduce 86


state 82
	statement : iteration_statement .  (88)

	.  reduce 88


state 83
	statement : jump_statement .  (89)

	.  reduce 89


state 84
	block_item_list : block_item_list . block_item
	compound_statement : LBRACE $$3 block_item_list . RBRACE

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	CONST  shift 6
	LBRACE  shift 26
	RBRACE  shift 132
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	declaration  goto 74
	compound_statement  goto 75
	type_qualifier  goto 10
	type_specifier  goto 11
	declaration_specifiers  goto 76
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	block_item  goto 133
	statement  goto 80
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 85
	statement : input_statement .  (90)

	.  reduce 90


state 86
	expression : expression . COMMA assign_expression
	primary_expression : LPAREN expression . RPAREN

	RPAREN  shift 134
	COMMA  shift 131


state 87
	prefix_expression : MINUS prefix_expression .  (67)

	.  reduce 67


state 88
	prefix_expression : INC prefix_expression .  (70)

	.  reduce 70


state 89
	prefix_expression : DEC prefix_expression .  (71)

	.  reduce 71


state 90
	prefix_expression : LOGICNOT prefix_expression .  (68)

	.  reduce 68


state 91
	prefix_expression : BITNOT prefix_expression .  (69)

	.  reduce 69


state 92
	bitor_expression : bitor_expression BITOR . bitxor_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 135
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 93
	bitand_expression : bitand_expression BITAND . equality_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	equality_expression  goto 136
	nonequality_expression  goto 50
	shift_expression  goto 51
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 94
	equality_expression : equality_expression EQ . nonequality_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	nonequality_expression  goto 137
	shift_expression  goto 51
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 95
	equality_expression : equality_expression NEQ . nonequality_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	nonequality_expression  goto 138
	shift_expression  goto 51
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 96
	nonequality_expression : nonequality_expression GT . shift_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	shift_expression  goto 139
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 97
	nonequality_expression : nonequality_expression GE . shift_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	shift_expression  goto 140
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 98
	nonequality_expression : nonequality_expression LT . shift_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	shift_expression  goto 141
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 99
	nonequality_expression : nonequality_expression LE . shift_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	shift_expression  goto 142
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 100
	shift_expression : shift_expression LEFTSHIFT . add_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 143
	mul_expression  goto 60


state 101
	shift_expression : shift_expression RIGHTSHIFT . add_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 144
	mul_expression  goto 60


state 102
	bitxor_expression : bitxor_expression BITXOR . bitand_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitand_expression  goto 145
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 103
	assign_expression : logicor_expression ASSIGN . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 146
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 104
	assign_expression : logicor_expression ADDASSIGN . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 147
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 105
	assign_expression : logicor_expression MINUSASSIGN . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 148
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 106
	assign_expression : logicor_expression MULASSIGN . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 149
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 107
	assign_expression : logicor_expression DIVASSIGN . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 150
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 108
	logicor_expression : logicor_expression LOGICOR . logicand_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	logicand_expression  goto 151
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 109
	logicand_expression : logicand_expression LOGICAND . bitor_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 152
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 110
	postfix_expression : postfix_expression LPAREN . argument_expression_list RPAREN

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 153
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	argument_expression_list  goto 154


state 111
	postfix_expression : postfix_expression INC .  (74)

	.  reduce 74


state 112
	postfix_expression : postfix_expression DEC .  (75)

	.  reduce 75


state 113
	add_expression : add_expression ADD . mul_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	mul_expression  goto 155


state 114
	add_expression : add_expression MINUS . mul_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	mul_expression  goto 156


state 115
	mul_expression : mul_expression MUL . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 157
	primary_expression  goto 58


state 116
	mul_expression : mul_expression DIV . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 158
	primary_expression  goto 58


state 117
	mul_expression : mul_expression MODE . prefix_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	postfix_expression  goto 56
	prefix_expression  goto 159
	primary_expression  goto 58


state 118
	parameter_list : parameter_declaration .  (22)

	.  reduce 22


state 119
	parameter_list : parameter_list . COMMA parameter_declaration
	direct_declarator : direct_declarator LPAREN $$1 parameter_list . RPAREN

	RPAREN  shift 160
	COMMA  shift 161


state 120
	parameter_declaration : declaration_specifiers . declarator

	ID  shift 16
	MUL  shift 17

	declarator  goto 162
	pointer  goto 21
	direct_declarator  goto 22


state 121
	selection_statement : IF LPAREN . expression RPAREN statement ELSE statement
	selection_statement : IF LPAREN . expression RPAREN statement

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 163
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 122
	iteration_statement : FOR LPAREN . expression_statement expression_statement expression RPAREN statement
	iteration_statement : FOR LPAREN . expression_statement expression_statement RPAREN statement
	iteration_statement : FOR LPAREN . $$4 declaration expression_statement expression RPAREN statement
	$$4 : .  (105)

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45
	.  reduce 105

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	expression_statement  goto 164
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	$$4  goto 165


state 123
	iteration_statement : WHILE LPAREN . expression RPAREN statement

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 166
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 124
	jump_statement : RETURN SEMICOLON .  (113)

	.  reduce 113


state 125
	expression : expression . COMMA assign_expression
	jump_statement : RETURN expression . SEMICOLON

	SEMICOLON  shift 167
	COMMA  shift 131


state 126
	jump_statement : BREAK SEMICOLON .  (112)

	.  reduce 112


state 127
	jump_statement : CONTINUE SEMICOLON .  (111)

	.  reduce 111


state 128
	input_statement : INPUT LPAREN . primary_expression RPAREN SEMICOLON

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40

	primary_expression  goto 168


state 129
	print_statement : PRINT LPAREN . primary_expression RPAREN SEMICOLON

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40

	primary_expression  goto 169


state 130
	expression_statement : expression SEMICOLON .  (103)

	.  reduce 103


state 131
	expression : expression COMMA . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 170
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 132
	compound_statement : LBRACE $$3 block_item_list RBRACE .  (97)

	.  reduce 97


state 133
	block_item_list : block_item_list block_item .  (99)

	.  reduce 99


state 134
	primary_expression : LPAREN expression RPAREN .  (84)

	.  reduce 84


state 135
	bitor_expression : bitor_expression BITOR bitxor_expression .  (43)
	bitxor_expression : bitxor_expression . BITXOR bitand_expression

	BITXOR  shift 102
	.  reduce 43


state 136
	bitand_expression : bitand_expression BITAND equality_expression .  (47)
	equality_expression : equality_expression . EQ nonequality_expression
	equality_expression : equality_expression . NEQ nonequality_expression

	EQ  shift 94
	NEQ  shift 95
	.  reduce 47


state 137
	nonequality_expression : nonequality_expression . LE shift_expression
	equality_expression : equality_expression EQ nonequality_expression .  (49)
	nonequality_expression : nonequality_expression . LT shift_expression
	nonequality_expression : nonequality_expression . GT shift_expression
	nonequality_expression : nonequality_expression . GE shift_expression

	GT  shift 96
	GE  shift 97
	LT  shift 98
	LE  shift 99
	.  reduce 49


state 138
	nonequality_expression : nonequality_expression . LE shift_expression
	equality_expression : equality_expression NEQ nonequality_expression .  (50)
	nonequality_expression : nonequality_expression . LT shift_expression
	nonequality_expression : nonequality_expression . GT shift_expression
	nonequality_expression : nonequality_expression . GE shift_expression

	GT  shift 96
	GE  shift 97
	LT  shift 98
	LE  shift 99
	.  reduce 50


state 139
	shift_expression : shift_expression . LEFTSHIFT add_expression
	shift_expression : shift_expression . RIGHTSHIFT add_expression
	nonequality_expression : nonequality_expression GT shift_expression .  (54)

	LEFTSHIFT  shift 100
	RIGHTSHIFT  shift 101
	.  reduce 54


state 140
	shift_expression : shift_expression . LEFTSHIFT add_expression
	shift_expression : shift_expression . RIGHTSHIFT add_expression
	nonequality_expression : nonequality_expression GE shift_expression .  (52)

	LEFTSHIFT  shift 100
	RIGHTSHIFT  shift 101
	.  reduce 52


state 141
	shift_expression : shift_expression . LEFTSHIFT add_expression
	shift_expression : shift_expression . RIGHTSHIFT add_expression
	nonequality_expression : nonequality_expression LT shift_expression .  (55)

	LEFTSHIFT  shift 100
	RIGHTSHIFT  shift 101
	.  reduce 55


state 142
	shift_expression : shift_expression . LEFTSHIFT add_expression
	nonequality_expression : nonequality_expression LE shift_expression .  (53)
	shift_expression : shift_expression . RIGHTSHIFT add_expression

	LEFTSHIFT  shift 100
	RIGHTSHIFT  shift 101
	.  reduce 53


state 143
	add_expression : add_expression . MINUS mul_expression
	shift_expression : shift_expression LEFTSHIFT add_expression .  (57)
	add_expression : add_expression . ADD mul_expression

	ADD  shift 113
	MINUS  shift 114
	.  reduce 57


state 144
	add_expression : add_expression . MINUS mul_expression
	shift_expression : shift_expression RIGHTSHIFT add_expression .  (58)
	add_expression : add_expression . ADD mul_expression

	ADD  shift 113
	MINUS  shift 114
	.  reduce 58


state 145
	bitand_expression : bitand_expression . BITAND equality_expression
	bitxor_expression : bitxor_expression BITXOR bitand_expression .  (45)

	BITAND  shift 93
	.  reduce 45


state 146
	assign_expression : logicor_expression ASSIGN assign_expression .  (33)

	.  reduce 33


state 147
	assign_expression : logicor_expression ADDASSIGN assign_expression .  (34)

	.  reduce 34


state 148
	assign_expression : logicor_expression MINUSASSIGN assign_expression .  (35)

	.  reduce 35


state 149
	assign_expression : logicor_expression MULASSIGN assign_expression .  (36)

	.  reduce 36


state 150
	assign_expression : logicor_expression DIVASSIGN assign_expression .  (37)

	.  reduce 37


state 151
	logicand_expression : logicand_expression . LOGICAND bitor_expression
	logicor_expression : logicor_expression LOGICOR logicand_expression .  (39)

	LOGICAND  shift 109
	.  reduce 39


state 152
	logicand_expression : logicand_expression LOGICAND bitor_expression .  (41)
	bitor_expression : bitor_expression . BITOR bitxor_expression

	BITOR  shift 92
	.  reduce 41


state 153
	argument_expression_list : assign_expression .  (77)

	.  reduce 77


state 154
	argument_expression_list : argument_expression_list . COMMA assign_expression
	postfix_expression : postfix_expression LPAREN argument_expression_list . RPAREN

	RPAREN  shift 171
	COMMA  shift 172


state 155
	mul_expression : mul_expression . MUL prefix_expression
	mul_expression : mul_expression . DIV prefix_expression
	mul_expression : mul_expression . MODE prefix_expression
	add_expression : add_expression ADD mul_expression .  (60)

	MUL  shift 115
	DIV  shift 116
	MODE  shift 117
	.  reduce 60


state 156
	add_expression : add_expression MINUS mul_expression .  (61)
	mul_expression : mul_expression . MUL prefix_expression
	mul_expression : mul_expression . DIV prefix_expression
	mul_expression : mul_expression . MODE prefix_expression

	MUL  shift 115
	DIV  shift 116
	MODE  shift 117
	.  reduce 61


state 157
	mul_expression : mul_expression MUL prefix_expression .  (63)

	.  reduce 63


state 158
	mul_expression : mul_expression DIV prefix_expression .  (64)

	.  reduce 64


state 159
	mul_expression : mul_expression MODE prefix_expression .  (65)

	.  reduce 65


state 160
	direct_declarator : direct_declarator LPAREN $$1 parameter_list RPAREN .  (20)

	.  reduce 20


state 161
	parameter_list : parameter_list COMMA . parameter_declaration

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6

	parameter_declaration  goto 173
	type_qualifier  goto 10
	type_specifier  goto 11
	declaration_specifiers  goto 120


state 162
	parameter_declaration : declaration_specifiers declarator .  (24)

	.  reduce 24


state 163
	expression : expression . COMMA assign_expression
	selection_statement : IF LPAREN expression . RPAREN statement ELSE statement
	selection_statement : IF LPAREN expression . RPAREN statement

	RPAREN  shift 174
	COMMA  shift 131


state 164
	iteration_statement : FOR LPAREN expression_statement . expression_statement expression RPAREN statement
	iteration_statement : FOR LPAREN expression_statement . expression_statement RPAREN statement

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	expression_statement  goto 175
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 165
	iteration_statement : FOR LPAREN $$4 . declaration expression_statement expression RPAREN statement

	VOID  shift 1
	CHAR  shift 2
	INT  shift 3
	FLOAT  shift 4
	DOUBLE  shift 5
	CONST  shift 6

	declaration  goto 176
	type_qualifier  goto 10
	type_specifier  goto 11
	declaration_specifiers  goto 76


state 166
	expression : expression . COMMA assign_expression
	iteration_statement : WHILE LPAREN expression . RPAREN statement

	RPAREN  shift 177
	COMMA  shift 131


state 167
	jump_statement : RETURN expression SEMICOLON .  (114)

	.  reduce 114


state 168
	input_statement : INPUT LPAREN primary_expression . RPAREN SEMICOLON

	RPAREN  shift 178


state 169
	print_statement : PRINT LPAREN primary_expression . RPAREN SEMICOLON

	RPAREN  shift 179


state 170
	expression : expression COMMA assign_expression .  (32)

	.  reduce 32


state 171
	postfix_expression : postfix_expression LPAREN argument_expression_list RPAREN .  (76)

	.  reduce 76


state 172
	argument_expression_list : argument_expression_list COMMA . assign_expression

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	bitxor_expression  goto 52
	assign_expression  goto 180
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 173
	parameter_list : parameter_list COMMA parameter_declaration .  (21)

	.  reduce 21


state 174
	selection_statement : IF LPAREN expression RPAREN . statement ELSE statement
	selection_statement : IF LPAREN expression RPAREN . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 181
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 175
	iteration_statement : FOR LPAREN expression_statement expression_statement . expression RPAREN statement
	iteration_statement : FOR LPAREN expression_statement expression_statement . RPAREN statement

	LPAREN  shift 35
	RPAREN  shift 182
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 183
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 176
	iteration_statement : FOR LPAREN $$4 declaration . expression_statement expression RPAREN statement

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	expression_statement  goto 184
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 177
	iteration_statement : WHILE LPAREN expression RPAREN . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 185
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 178
	input_statement : INPUT LPAREN primary_expression RPAREN . SEMICOLON

	SEMICOLON  shift 186


state 179
	print_statement : PRINT LPAREN primary_expression RPAREN . SEMICOLON

	SEMICOLON  shift 187


state 180
	argument_expression_list : argument_expression_list COMMA assign_expression .  (78)

	.  reduce 78


state 181
	selection_statement : IF LPAREN expression RPAREN statement . ELSE statement
	selection_statement : IF LPAREN expression RPAREN statement .  (109)

	ELSE  shift 188
	.  reduce 109


state 182
	iteration_statement : FOR LPAREN expression_statement expression_statement RPAREN . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 189
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 183
	expression : expression . COMMA assign_expression
	iteration_statement : FOR LPAREN expression_statement expression_statement expression . RPAREN statement

	RPAREN  shift 190
	COMMA  shift 131


state 184
	iteration_statement : FOR LPAREN $$4 declaration expression_statement . expression RPAREN statement

	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 191
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	postfix_expression  goto 56
	prefix_expression  goto 57
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60


state 185
	iteration_statement : WHILE LPAREN expression RPAREN statement .  (104)

	.  reduce 104


state 186
	input_statement : INPUT LPAREN primary_expression RPAREN SEMICOLON .  (92)

	.  reduce 92


state 187
	print_statement : PRINT LPAREN primary_expression RPAREN SEMICOLON .  (93)

	.  reduce 93


state 188
	selection_statement : IF LPAREN expression RPAREN statement ELSE . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 192
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 189
	iteration_statement : FOR LPAREN expression_statement expression_statement RPAREN statement .  (108)

	.  reduce 108


state 190
	iteration_statement : FOR LPAREN expression_statement expression_statement expression RPAREN . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 193
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 191
	expression : expression . COMMA assign_expression
	iteration_statement : FOR LPAREN $$4 declaration expression_statement expression . RPAREN statement

	RPAREN  shift 194
	COMMA  shift 131


state 192
	selection_statement : IF LPAREN expression RPAREN statement ELSE statement .  (110)

	.  reduce 110


state 193
	iteration_statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement .  (107)

	.  reduce 107


state 194
	iteration_statement : FOR LPAREN $$4 declaration expression_statement expression RPAREN . statement

	IF  shift 63
	FOR  shift 64
	WHILE  shift 65
	RETURN  shift 66
	BREAK  shift 67
	CONTINUE  shift 68
	LBRACE  shift 26
	LPAREN  shift 35
	INUMBER  shift 36
	FNUMBER  shift 37
	ID  shift 38
	SEMICOLON  shift 69
	STRING_LITERAL  shift 39
	CHAR_LITERAL  shift 40
	INPUT  shift 70
	PRINT  shift 71
	MINUS  shift 41
	INC  shift 42
	DEC  shift 43
	LOGICNOT  shift 44
	BITNOT  shift 45

	bitor_expression  goto 46
	bitand_expression  goto 47
	equality_expression  goto 49
	nonequality_expression  goto 50
	shift_expression  goto 51
	expression  goto 72
	bitxor_expression  goto 52
	assign_expression  goto 73
	logicor_expression  goto 54
	logicand_expression  goto 55
	compound_statement  goto 75
	print_statement  goto 77
	selection_statement  goto 78
	postfix_expression  goto 56
	prefix_expression  goto 57
	statement  goto 195
	expression_statement  goto 81
	iteration_statement  goto 82
	jump_statement  goto 83
	primary_expression  goto 58
	add_expression  goto 59
	mul_expression  goto 60
	input_statement  goto 85


state 195
	iteration_statement : FOR LPAREN $$4 declaration expression_statement expression RPAREN statement .  (106)

	.  reduce 106


##############################################################################
# Summary
##############################################################################

59 token(s), 46 nonterminal(s)
115 grammar rule(s), 196 state(s)


##############################################################################
# End of File
##############################################################################
