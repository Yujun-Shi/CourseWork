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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 01/03/18
# Time: 11:23:40
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  \/\/.*

    2  \/\*([^\*\/]|\*[^\/])*\*\/

    3  [ \t]+

    4  [\n]

    5  \+

    6  \-

    7  \*

    8  \/

    9  \=

   10  \==

   11  \!=

   12  \>=

   13  \<=

   14  \>

   15  \<

   16  \+=

   17  \-=

   18  \*=

   19  \/=

   20  "void"

   21  "char"

   22  "int"

   23  "float"

   24  "double"

   25  "if"

   26  "else"

   27  "for"

   28  "while"

   29  "return"

   30  "break"

   31  "continue"

   32  "const"

   33  "input"

   34  "print"

   35  \,

   36  \;

   37  \{

   38  \}

   39  \(

   40  \)

   41  \%

   42  \~

   43  \!

   44  \&

   45  \|

   46  \^

   47  \<\<

   48  \>\>

   49  \&\&

   50  \|\|

   51  (\+|\-)?([0-9])+

   52  (\+|\-)?([0-9])+(\.([0-9])+((\E|\e)(\+|\-)?([0-9])+)?)?

   53  [a-zA-Z_](([a-zA-Z0-9_])+)?

   54  \+\+

   55  \-\-

   56  \"([^\"]|\\\")*\"

   57  \'([^\"]|\\\")?\'


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x22               goto 6
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5e               goto 23
	0x5f               goto 22
	0x61               goto 22
	0x62               goto 24
	0x63               goto 25
	0x64               goto 26
	0x65               goto 27
	0x66               goto 28
	0x67 - 0x68 (2)    goto 22
	0x69               goto 29
	0x6a - 0x6f (6)    goto 22
	0x70               goto 30
	0x71               goto 22
	0x72               goto 31
	0x73 - 0x75 (3)    goto 22
	0x76               goto 32
	0x77               goto 33
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 34
	0x7c               goto 35
	0x7d               goto 36
	0x7e               goto 37


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x22               goto 6
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5e               goto 23
	0x5f               goto 22
	0x61               goto 22
	0x62               goto 24
	0x63               goto 25
	0x64               goto 26
	0x65               goto 27
	0x66               goto 28
	0x67 - 0x68 (2)    goto 22
	0x69               goto 29
	0x6a - 0x6f (6)    goto 22
	0x70               goto 30
	0x71               goto 22
	0x72               goto 31
	0x73 - 0x75 (3)    goto 22
	0x76               goto 32
	0x77               goto 33
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 34
	0x7c               goto 35
	0x7d               goto 36
	0x7e               goto 37


state 3
	0x09               goto 3
	0x20               goto 3

	match 3


state 4
	match 4


state 5
	0x3d               goto 38

	match 43


state 6
	0x00 - 0x21 (34)   goto 6
	0x22               goto 39
	0x23 - 0x5b (57)   goto 6
	0x5c               goto 40
	0x5d - 0xff (163)  goto 6


state 7
	match 41


state 8
	0x26               goto 41

	match 44


state 9
	0x00 - 0x21 (34)   goto 42
	0x23 - 0x26 (4)    goto 42
	0x27               goto 43
	0x28 - 0x5b (52)   goto 42
	0x5c               goto 44
	0x5d - 0xff (163)  goto 42


state 10
	match 39


state 11
	match 40


state 12
	0x3d               goto 45

	match 7


state 13
	0x2b               goto 46
	0x30 - 0x39 (10)   goto 17
	0x3d               goto 47

	match 5


state 14
	match 35


state 15
	0x2d               goto 48
	0x30 - 0x39 (10)   goto 17
	0x3d               goto 49

	match 6


state 16
	0x2a               goto 50
	0x2f               goto 51
	0x3d               goto 52

	match 8


state 17
	0x2e               goto 53
	0x30 - 0x39 (10)   goto 17

	match 51


state 18
	match 36


state 19
	0x3c               goto 54
	0x3d               goto 55

	match 15


state 20
	0x3d               goto 56

	match 9


state 21
	0x3d               goto 57
	0x3e               goto 58

	match 14


state 22
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 53


state 23
	match 46


state 24
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 59
	0x73 - 0x7a (8)    goto 22

	match 53


state 25
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 60
	0x69 - 0x6e (6)    goto 22
	0x6f               goto 61
	0x70 - 0x7a (11)   goto 22

	match 53


state 26
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 62
	0x70 - 0x7a (11)   goto 22

	match 53


state 27
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 63
	0x6d - 0x7a (14)   goto 22

	match 53


state 28
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 64
	0x6d - 0x6e (2)    goto 22
	0x6f               goto 65
	0x70 - 0x7a (11)   goto 22

	match 53


state 29
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 66
	0x67 - 0x6d (7)    goto 22
	0x6e               goto 67
	0x6f - 0x7a (12)   goto 22

	match 53


state 30
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 68
	0x73 - 0x7a (8)    goto 22

	match 53


state 31
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 69
	0x66 - 0x7a (21)   goto 22

	match 53


state 32
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 70
	0x70 - 0x7a (11)   goto 22

	match 53


state 33
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 71
	0x69 - 0x7a (18)   goto 22

	match 53


state 34
	match 37


state 35
	0x7c               goto 72

	match 45


state 36
	match 38


state 37
	match 42


state 38
	match 11


state 39
	match 56


state 40
	0x00 - 0x21 (34)   goto 6
	0x22               goto 73
	0x23 - 0x5b (57)   goto 6
	0x5c               goto 40
	0x5d - 0xff (163)  goto 6


state 41
	match 49


state 42
	0x27               goto 74


state 43
	0x27               goto 74

	match 57


state 44
	0x22               goto 42
	0x27               goto 74


state 45
	match 18


state 46
	match 54


state 47
	match 16


state 48
	match 55


state 49
	match 17


state 50
	0x00 - 0x29 (42)   goto 50
	0x2a               goto 75
	0x2b - 0x2e (4)    goto 50
	0x30 - 0xff (208)  goto 50


state 51
	0x00 - 0x09 (10)   goto 51
	0x0b - 0xff (245)  goto 51

	match 1


state 52
	match 19


state 53
	0x30 - 0x39 (10)   goto 76


state 54
	match 47


state 55
	match 13


state 56
	match 10


state 57
	match 12


state 58
	match 48


state 59
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 77
	0x66 - 0x7a (21)   goto 22

	match 53


state 60
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 78
	0x62 - 0x7a (25)   goto 22

	match 53


state 61
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 79
	0x6f - 0x7a (12)   goto 22

	match 53


state 62
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 80
	0x76 - 0x7a (5)    goto 22

	match 53


state 63
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 81
	0x74 - 0x7a (7)    goto 22

	match 53


state 64
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 82
	0x70 - 0x7a (11)   goto 22

	match 53


state 65
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 83
	0x73 - 0x7a (8)    goto 22

	match 53


state 66
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 25


state 67
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6f (15)   goto 22
	0x70               goto 84
	0x71 - 0x73 (3)    goto 22
	0x74               goto 85
	0x75 - 0x7a (6)    goto 22

	match 53


state 68
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 86
	0x6a - 0x7a (17)   goto 22

	match 53


state 69
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 87
	0x75 - 0x7a (6)    goto 22

	match 53


state 70
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 88
	0x6a - 0x7a (17)   goto 22

	match 53


state 71
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 89
	0x6a - 0x7a (17)   goto 22

	match 53


state 72
	match 50


state 73
	0x00 - 0x21 (34)   goto 6
	0x22               goto 39
	0x23 - 0x5b (57)   goto 6
	0x5c               goto 40
	0x5d - 0xff (163)  goto 6

	match 56


state 74
	match 57


state 75
	0x00 - 0x2e (47)   goto 50
	0x2f               goto 90
	0x30 - 0xff (208)  goto 50


state 76
	0x30 - 0x39 (10)   goto 76
	0x45               goto 91
	0x65               goto 91

	match 52


state 77
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 92
	0x62 - 0x7a (25)   goto 22

	match 53


state 78
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 93
	0x73 - 0x7a (8)    goto 22

	match 53


state 79
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 94
	0x74               goto 95
	0x75 - 0x7a (6)    goto 22

	match 53


state 80
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 22
	0x62               goto 96
	0x63 - 0x7a (24)   goto 22

	match 53


state 81
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 97
	0x66 - 0x7a (21)   goto 22

	match 53


state 82
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61               goto 98
	0x62 - 0x7a (25)   goto 22

	match 53


state 83
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 27


state 84
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 99
	0x76 - 0x7a (5)    goto 22

	match 53


state 85
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 22


state 86
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 100
	0x6f - 0x7a (12)   goto 22

	match 53


state 87
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 101
	0x76 - 0x7a (5)    goto 22

	match 53


state 88
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x63 (3)    goto 22
	0x64               goto 102
	0x65 - 0x7a (22)   goto 22

	match 53


state 89
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 103
	0x6d - 0x7a (14)   goto 22

	match 53


state 90
	match 2


state 91
	0x2b               goto 104
	0x2d               goto 104
	0x30 - 0x39 (10)   goto 105


state 92
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6a (10)   goto 22
	0x6b               goto 106
	0x6c - 0x7a (15)   goto 22

	match 53


state 93
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 21


state 94
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 107
	0x75 - 0x7a (6)    goto 22

	match 53


state 95
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 108
	0x6a - 0x7a (17)   goto 22

	match 53


state 96
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 109
	0x6d - 0x7a (14)   goto 22

	match 53


state 97
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 26


state 98
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 110
	0x75 - 0x7a (6)    goto 22

	match 53


state 99
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 111
	0x75 - 0x7a (6)    goto 22

	match 53


state 100
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 112
	0x75 - 0x7a (6)    goto 22

	match 53


state 101
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 113
	0x73 - 0x7a (8)    goto 22

	match 53


state 102
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 20


state 103
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 114
	0x66 - 0x7a (21)   goto 22

	match 53


state 104
	0x30 - 0x39 (10)   goto 105


state 105
	0x30 - 0x39 (10)   goto 105

	match 52


state 106
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 30


state 107
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 32


state 108
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 115
	0x6f - 0x7a (12)   goto 22

	match 53


state 109
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 116
	0x66 - 0x7a (21)   goto 22

	match 53


state 110
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 23


state 111
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 33


state 112
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 34


state 113
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 117
	0x6f - 0x7a (12)   goto 22

	match 53


state 114
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 28


state 115
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 118
	0x76 - 0x7a (5)    goto 22

	match 53


state 116
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 24


state 117
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 29


state 118
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 119
	0x66 - 0x7a (21)   goto 22

	match 53


state 119
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 31


#############################################################################
# Summary
#############################################################################

1 start state(s)
57 expression(s), 119 state(s)


#############################################################################
# End of File
#############################################################################
