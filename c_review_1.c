#include<stdio.h>

extern int g_test1;
//extern int g_test2;      //static修饰无法链接

typedef unsigned int s;
s s1;

void timer(){
    static int count=0;
    count++;
    printf("timer count:%d\n",count);
}

void test2(){
    int a=0;
    do{
        a++;
        if(a==10)
        continue;

        printf("%d\n",a);
    }while(a<20);
}

int main(){

    //goto flag1;

    printf("hello word!\n");
        register int  a=5;       //现代编译器更加智能，无需register变量
    
       
        auto int b=4;           //现代编译器中自动作用域的用法已经被淘汰
    signed int a1=10;           //其二进制最高位为符号位，0正1负
    unsigned int a2=20;         //无负号数，其二进制最高位为数据位

    timer();
    timer();

    printf("g_test1:%d\n",g_test1);
    //printf("g_test2:%d\n",g_test2);
    
    test2();

    return 0;
}
