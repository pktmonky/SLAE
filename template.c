#include<stdio.h>
#include<string.h>
 
 
unsigned char code[] =
"";
 
main()
{

    int (*ret)() = (int(*)())code;
 
    ret();
 
}
