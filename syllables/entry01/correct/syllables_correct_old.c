#include <string.h>
#include <klee/klee.h>
#include <stdio.h>

int syllables(char instring[], int len){
    int numVowels = 0;
    for(int i=0; i < len; i++) { 
	if (instring[i] == 'a' || instring[i] == 'e' || instring[i] == 'i' || instring[i] == 'o' || instring[i] == 'u' || instring[i] == 'y'){
	    numVowels += 2;
        }
    }
    return numVowels;
}

int main ()
{
    char instring[2];
    int len;
    klee_make_symbolic(instring, sizeof(char)*2, "str_in_string");
    klee_make_symbolic(&len, sizeof(len), "len");
    klee_assume(len==2);
    return syllables(instring, len);
}
