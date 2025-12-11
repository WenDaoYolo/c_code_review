#include<stdio.h>
/*
    进阶篇指针
    指针全解

    掌握优先级、结合性、主体对象、以及定义语法的逻辑，再困难的逻辑也能轻松拆解
*/

void test1(){
    //1.一级指针、二级指针、三级指针
    int* pa=NULL;
    int** ppa=&pa;
    int*** pppa=&ppa;
}

void test2(){
    //2.常量指针、常指针、常量常指针
    int a=5;
    int b=6;
    int c=7;
    const int* ptr1=&a;
    //*ptr1=3;
    int* const ptr2=&b;
    //ptr2=&a;
    const int* const ptr3=&c;
    //*ptr3=4;
    //ptr3=&a;
}

void fun1(int a,float b,char c){
    printf("array_ptr!\n");
}

void test3(){
    //3.字符指针、数组指针、函数指针
    char str2[]="Jack!";
    const char* cptr="hello";
    printf("%s\n",cptr);
    cptr=str2;
    printf("%s\n",cptr);

    char(*c_array_ptr)[]=&str2;
    printf("%c\n",*(*c_array_ptr));

    void(*fun_ptr)(int,float,char)=fun1;
    fun_ptr(3,4.1,'W');
}

float fun2(char a,int b){
    printf("fun_ptr_array! 1\n");
    return 0.1;
}

float fun3(char a,int b){
    printf("fun_ptr_array! 2\n");
    return 0.1;
}

float fun4(char a,int b){
    printf("fun_ptr_array! 3\n");
    return 0.1;
}

void test4(){
    //4.指针数组、函数指针数组、数组指针数组
    int a=10,b=20,c=30;
    int*(ptr_array[3])={&a,&b,&c};
    printf("%d\n",*ptr_array[0]);

    float(*fun_ptr_array[3])(char,int)={fun2,&fun3,fun4};
    fun_ptr_array[0]('A',44);
    fun_ptr_array[1]('A',44);
    fun_ptr_array[2]('A',44);

    float sss[3]={1.11,2.22,3.33};
    float(*ptrr)[3]=&sss;
    float(*array_ptr_array[1])[3]={ptrr};
    printf("%f\n",***array_ptr_array);
    printf("%f\n",*(**array_ptr_array+1));
    printf("%f\n",*(**array_ptr_array+2));
}

void test5(){
    //5.指针数组指针、函数指针数组指针
    //6.指针数组指针数组，数组指针数组指针
    printf("--------------------------------------\n");
    int*(*ptr_array_ptr)[4]=NULL;
    void(*(*fun_ptr_array_ptr)[3])(int,int)=NULL;

    int*(*ptr_array_ptr_array[3])[2]={0};
    /*
        主体对象数组
        arr[3]数组，*类型为指针
        [2]指针指向的对象为数组
        int*数组的类型为整型指针
    */
    int(*(*array_ptr_array_ptr)[3])[1]=NULL;
    /*
        主体对象为指针
        *arr指针，[3]指向的对象是数组
        *数组的类型是指针
        [1]指针指向的对象是数组,int数组的类型是整型
    */
   printf("test is finished!\n");
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}