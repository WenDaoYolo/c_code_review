#include<stdio.h>
#include "func.h"                //自定义函数库

void test1();                    //声明

void test1(){                    //定义，注意函数可以嵌套调用，但不能嵌套定义
    printf("test1!\n");
}

void test2(){                    //直接定义，也可以声明和定义统一进行<但是不建议这样>
    test1();                     //嵌套调用，注意test1要在此之前就声明，否则编译器无法识别
    printf("test2!\n");
    //test3();                   //test3函数的定义在此函数之后，所以无法识别
                                 //要么向前声明，要么在该函数之前定义，要么采用头文件与函数库的方式
}

void test3(){
    ;
}

int main(){
    int a=20;
    int b=10;

    Produce();
    Add(a,b);
    Sub(a,b);

    return 0;
}