#include <stdio.h>
#include <klee/klee.h>

int smallest(int n1, int n2, int n3, int n4){
    if (n1 < n2 && n1 < n3 && n1 < n4)
        return n1;

    else if (n3 != n1 && n2 < n3 && n2 < n4)
        return n2;
      
    else if (n3 < n4)
        return n3;

    else
        return n4;
}


int main(){
    int a,b,c,d;
    klee_make_symbolic(&a, sizeof(a), "w");
    klee_make_symbolic(&b, sizeof(b), "x");
    klee_make_symbolic(&c, sizeof(c), "y");
    klee_make_symbolic(&d, sizeof(d), "z");
    return smallest(a, b, c, d);
}

       
