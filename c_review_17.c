#include<stdio.h>
/*
    指针篇
    规避野指针
    void*空指针
    NULL空指针
    良好的编程习惯
    
    next: 
    const指针及其风险
    容器的级别
*/

void test1(){
    int test=10;
    int* int_ptr=NULL;                                //定义即初始化
    void* void_ptr=&test;                             //void*万能指针
    if(int_ptr!=NULL)                                 //使用前检查指针的有效性
    printf("int_ptr value:%d\n",*int_ptr);            //NULL空指针不能解引用
    printf("void_ptr value:%d\n",*((int*)void_ptr));  //void*空指针也不能直接解引用
}

void test2(){
    const int a=10;
    int* pa=&a;
    //a=20;         无法修改
    *pa=100;        //但通过指针可以修改

    printf("after:%d\n",*pa);
}

void test3(){
    int a=10,b=20;
    int* const pa=&a;
    const int* pb=&b;
    const int* const pa_2=&a;
    
    //pa=&b;
    //*pb=200;
    //pa_2=&b;
    //*pa_2=1000;
}

void test4(){
    const int a=10;
    const int* pa=&a;
    const int** ppa=&pa;
    int*** pppa=&ppa;
    ***pppa=20;
    printf("multiplex pointer:%d",a);
}

int main(){
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}