#include<stdio.h>

/*
    进阶篇指针
    函数指针数组的指针
    回调函数
*/

//函数指针数组的指针
float fun1(int a,int b){
    return 0.1;
}

float fun2(int a,int b){
    return 0.1;
}

float fun3(int a,int b){
    return 0.1;
}

void test1(){
    //函数指针数组
    float(*funptr_array[3])(int,int)={fun1,fun2,fun3};
    //函数指针数组的指针
    float(*(*fun_ptr_array_ptr)[3])(int,int)=&funptr_array;   
}

//回调函数,在一个函数中通过函数地址调用其他函数，被调的函数就是回调函数
//主调方采用回调机制，通过传进来的地址来调用各种函数相当一个函数调用中心

void fun4(){                   //回调函数
    printf("yes\n");
}

void fun5(){                   //回调函数
    printf("no\n");
}

void test2(void(*funptr)()){   //主调函数
    funptr();
}

int main(){
    test1();
    test2(fun4);
    test2(fun5);

    return 0;
}