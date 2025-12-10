#include<stdio.h>

/*
    指针进阶篇
    函数指针
*/

//typedef重定义函数指针类型
typedef void(*vpf)(int);                  

void test1(){
    void(*signal(int,void(*)(int)))(int);
    //请问signal是个什么东西?O.o
    //这是一个函数声明，signal是函数名,后面()内的为函数参数，剩下的为函数的返回类型

    /*分析：
        signal和()先结合说明signal是一个函数
        ()内的为函数的参数，形参1为整型int;形参2为函数指针void(*)(int),指针指向的为函数，函数的参数为int返回类型为void
        剩下的则为signal函数的返回类型，*说明返回类型为指针，()说明指针指向的是函数，函数的参数为int,返回类型为void
    */

    //通过typedef来简化定义的逻辑语法
    vpf signal2(int,vpf);
}

void test2(){
    (*(void(*)())0)();
    //这又是个什么东西?o.O
    //将0强转为函数指针类型，然后再进行调用

    /*分析：
        void(*)()是一个函数指针类型
        (函数指针类型)0,将0强制类型转换
        *(函数指针类型)0(),解引用0找到函数名，然后通过()调用
    */

    //所以也等价于((void(*)())0)()
}

//函数指针数组
int t1(int a,int b){
    return a+b;
}

int t2(int a,int b){
    return a-b;
}
int main(){
    int(*fun_ptr_array[2])(int,int)={t1,t2};
    

    return 0;
}