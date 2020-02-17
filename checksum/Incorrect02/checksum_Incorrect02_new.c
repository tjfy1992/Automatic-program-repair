#include <string.h>
#include <klee/klee.h>
#include <stdio.h>

char checksum(char instring[], int len){
    char checksumchar;
    int checksum_summation = 0;
    for(int i=0; i < len; i++)
    {
        checksum_summation = checksum_summation + (int)instring[1];
    }
    checksum_summation %= 64;
    checksum_summation += 32;
    checksumchar = (char)checksum_summation;
    return checksumchar;
}

int main ()
{
    char instring[2];
    int len;
    klee_make_symbolic(instring, sizeof(char)*2, "str_in_string");
    klee_make_symbolic(&len, sizeof(len), "len");
    klee_assume(len==2);
    checksum(instring, len);
    return 0;
}
