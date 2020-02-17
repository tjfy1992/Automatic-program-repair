#include <stdio.h>
#include <klee/klee.h>

char grade(int g){
    int A=90, B=80, C=70, D=60;
    if(g >= A){
        return 'A';
    }

    else if(g >= B){
        return 'B';
    }

    else if(g >= B){
        return 'C';
    }

    else if(g >= D){
        return 'D';
    }

    else return 'F';
}


int main(){
    int g;
    klee_make_symbolic(&g, sizeof(g), "x");
    klee_assume(g >= 0);
    klee_assume(g <= 100);
    return grade(g);
}

       
