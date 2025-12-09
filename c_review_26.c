#include<stdio.h>
/*
    进阶指针篇
*/

void test1(){
    /* 接收一维、二维数组的形参 */

    int arr[3];      //会退化为指向首元素的指针
    int* parr;       //指向数组首元素的指针
    int (*ptr)[3];   //数组指针

    int* arrs[10];   //整型指针数组
    int** arrss;     //二级指针 -> 指向指针数组的首元素地址，即一级指针的地址
}


void Print_1(int** ppa){
    printf("%d\n",**ppa);
}

void Print_2(int* (*ptr)[]){
    printf("%d\n",*(*ptr)[0]);
}

void test2(){
    int a=111;
    int b=222;
    int c=333;
    int* pb=&b;
    int* ptr_array[3]={&a,&b,&c};
    
    Print_1(ptr_array);
    Print_1(&pb);
    Print_2(&ptr_array);
}

/* 函数指针 */
void func(int c){
    printf("hello %d!",c);
}

void test3(){
    int a=10,b=20;
    void(*funcptr1)(int)=func;
    void(*funcptr2)(int)=&func;
    
    func(a);
    (&func)(b);

    funcptr1(666);
    (*funcptr2)(999);

}

int main(){
    test2();
    test3();

    return 0;
}