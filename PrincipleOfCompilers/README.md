# SCC: My Simple Compiler



##1. About

This is my implementation of a simple compiler.

The implementation is based on Yacc and Lex. All .y and .l files have already been processed into corresponding .h and .cpp files by Parser Generator. Therefore, simply execute the visual studio project will be ok.

This compiler is a c compiler. It will compile the c code into x86 assembly code (specifically 80586) on windows architecture. 

I ran my code on visual studio 2015



##2. How to execute

First, recompile the project on your machine. (Or you can simply use the exe file that I provided)

Second, use the following command line to execute:

```
scc /path/to/your/c/file
```

Then, a file named 'tmp.asm' will be generated.



##3. Result

compile the following c code

```c
int n;
void fibs(int n) {
    int res = 1;
    int pingpong = 1;
    for (int i = 0; i < n; ++i) {
        int t = res;
        res += pingpong;
        pingpong = t;
        if (i < 3 || i > 5 && i < 7) {
            print(1); // hard coded output stream
        }
        else {
            print(n); // hard coded output stream
        }
    }
}
void main(){
    input(n); // hard coded input stream
    n *= 2;
    fibs(n);
}
```

into the following assembly code

```asm
	.586
	.model flat, stdcall
	option casemap : none
	include \masm32\macros\macros.asm
	include    \masm32\include\msvcrt.inc
	includelib \masm32\lib\msvcrt.lib
	.data
	format db "%d",0
	input_buffer DWORD ?
	newline BYTE 13,10,0
	_n DWORD 0
	.code
start:
	call main
	invoke crt__exit,0
fibs proc
	push ebp
	mov ebp, esp
	sub esp, 16
	mov eax, 1
	mov 0[ebp-4], eax
	mov eax, 1
	mov 0[ebp-8], eax
	mov eax, 0
	mov 0[ebp-12], eax
_L0:
	mov eax, 0[ebp-12]
	mov ebx, 8[ebp]
	cmp eax, ebx
	jl _L1
	jmp _L2
_L1:
	mov eax, 0[ebp-4]
	mov 0[ebp-16], eax
	mov eax, 0[ebp-4]
	add eax, 0[ebp-8]
	mov 0[ebp-4], eax
	mov eax, 0[ebp-16]
	mov 0[ebp-8], eax
	mov eax, 0[ebp-12]
	mov ebx, 3
	cmp eax, ebx
	jl _L3
	jmp _L6
_L6:
	mov eax, 0[ebp-12]
	mov ebx, 5
	cmp eax, ebx
	jg _L7
	jmp _L4
_L7:
	mov eax, 0[ebp-12]
	mov ebx, 7
	cmp eax, ebx
	jl _L3
	jmp _L4
_L3:
	mov eax, 1
	invoke crt_printf, OFFSET format, eax
	invoke crt_printf, OFFSET newline
	jmp _L5
_L4:
	mov eax, 8[ebp]
	invoke crt_printf, OFFSET format, eax
	invoke crt_printf, OFFSET newline
_L5:
	mov eax, 0[ebp-12]
	add eax, 1
	mov 0[ebp-12], eax
	jmp _L0
_L2:
	add esp, 16
	pop ebp
	ret
fibs endp
main proc
	push ebp
	mov ebp, esp
	sub esp, 0
	invoke crt_scanf, OFFSET format, addr input_buffer
	mov eax, input_buffer
	mov _n, eax
	mov eax, _n
	mov ebx, 2
	mul ebx
	mov _n, eax
	mov eax, _n
	push eax
	call fibs
	add esp, 4
	add esp, 0
	pop ebp
	ret
main endp
end start
```

