#include<stdio.h>
#include<stddef.h>
#pragma pack(4)
#pragma pack()
                       //防止头文件重复包含方法1:pragma once -> 只能在头文件中使用
#ifndef _TEST_         //防止头文件重复包含方法2
#define _TEST_

#if !www               //防止头文件重复包含方法3
#define www 3          //条件预编译的嵌套
#endif

/*
    进阶篇预处理
*/

#if 0
这是一个注释
你好世界
#endif


#define a1 3
#define a2 4

#if a1>a2
#define print printf("yes!\n");
#elif a1==a2
#define print printf("same!\n");
#else
#define print printf("no!\n");

#endif

struct test{
    int a;             //0
    char b;            //4
    float c;           //8
    double d;          //16     
};

void PrintOffsetof(){
    printf("a:%d\n",offsetof(struct test,a));
    printf("b:%d\n",offsetof(struct test,b));
    printf("c:%d\n",offsetof(struct test,c));
    printf("d:%d\n",offsetof(struct test,d));
}

int main(){
    print  
    PrintOffsetof();
    
    return 0;
}

#endif