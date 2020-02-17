#include <stdio.h>
#include <klee/klee.h>
#include <stdlib.h>

int digits(int num){
    if (num==0){
        printf("%d\n",num);
        return 0;
    }
    if (num<0){
        num=(abs(num));
        while (num > 10) {
            printf("%d\n", num % 10);
            num/=10;
        }
        num = num - 2 * num;
        printf("%d\n", num);
        return 1;
    }
    else{
        while (num != 0) {
            printf("%d\n", num % 10);
            num/=10;
        }
        return 2;
    }
}


int main(){
    int number;
    klee_make_symbolic(&number, sizeof(number), "x");
    return digits(number);
}

       
