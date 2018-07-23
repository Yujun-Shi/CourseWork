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
