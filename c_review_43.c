#include<stdio.h>
/*
    自定义类型进阶篇
    枚举类型
*/

enum weekday{
    mon,
    tue,
    wen=20,
    thir,
    fri
};

enum sex{
    male='M',
    female='F',
    test='A'
};

void test1(){
    enum weekday s1=thir;
    s1=mon;
    printf("%d,%d,%d,%d,%d\n",mon,tue,wen,thir,s1);
}

void test2(){
    enum sex m=male;
    enum sex f=female;
    enum sex t=test;
    printf("char enum test:%d,%d,%d,%c,%c,%c\n",m,f,t,m,f,t);
    printf("%d\n",sizeof(t));
}

int main(){
    test1();
    test2();

    return 0;
}