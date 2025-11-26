#include<stdio.h>
#define PI 3.14
#define add(x,y) x+y
#define ADD(x,y) (x+y)
#define PRINT(str) printf(str)

void test(){
    printf("PI:%.2f\n",PI);
    printf("unsafe:%d\n",add(3,4)*5);  // 3+4*5   =23
    printf("safe:%d\n",ADD(3,4)*5);    // (3+4)*5 =35

    PRINT("hello world!\n");           // printf("hello world!\n"); str <-> "hello world!\n"
}

int main(){
    test();
    return 0;
}