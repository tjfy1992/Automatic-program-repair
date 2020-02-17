#include <stdio.h>
#include <klee/klee.h>

int median(int a, int b, int c){
    if(((a>=b)&&(a<=c))||((a<=b)&&(a>=c))){
        return a;
    }
    else if(((b>=a)&&(b<=c))||((b<a)&&(b>=c))){
        return b;
    }
    else if (((c>a)&&(c<b))||((c<a)&&(c>b))){
        return c;
    }
    return 0;
}


int main(){
    int a,b,c;
    klee_make_symbolic(&a, sizeof(a), "x");
    klee_make_symbolic(&b, sizeof(b), "y");
    klee_make_symbolic(&c, sizeof(c), "z");
    return median(a, b, c);
}

       
