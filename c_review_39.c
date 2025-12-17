#include<stdio.h>

/*
    结构体进阶篇
*/

//匿名结构体
struct{
    int a;
    int b;
}stu;

struct{
    int a;
    int b;
} *p;

//p=&stu;  类型不同，无法赋值

/*
    结构体的内存对齐规则
    1.第一个成员从0偏移处存放
    
    2.剩余依次有序存放在对齐数整数倍的地址处，对齐数<->默认对齐数与成员大小中的较小值
      vs默认对齐数8，linux无默认对齐数的概念(即以成员大小本身为对齐数)
    
    3.结构体大小为最大对齐数的整数倍

    4.若成员为结构体，则该结构体成员的对齐数取决于该结构体的最大对齐数
*/

struct s1{
    char a;
    int b;
    char c;
};

void test1(){
    printf("s1 size:%d\n",sizeof(struct s1));
    /*
        理论：6个字节
        实际：内存对齐后，12个字节

        char a 地址0 1个字节
        int  b 4v8取4,地址4-7 4个字节
        char c 1v8取1,地址8   1个字节
        内存地址总的偏移0-8共9个字节
        最大对齐数4，所以尾地址偏移至11处,0-11共12个字节
    */
}

struct s2 {
	int a1;
	double a2;
	int arr[10];
};

void test2(){
    printf("s2 size:%d\n",sizeof(struct s2));
    /*
        理论：52个字节
        实际：内存对齐后，56个字节

        int a1 地址0-3 4个字节
        double a2 8v8取8,地址8-15 8个字节
        int arr[10] 40v8取8,地址16-55 40个字节 
        内存地址总的偏移0-55共56个字节
        最大对齐数8,56是8的整数倍，所以结构体的内存为56个字节
    */
}

struct test1{
	int a;
	float b;
};

struct test2{
	float a;
	char b;
	struct test1 c;
};

void test3(){
    printf("test1 size:%d\n",sizeof(struct test1));
    printf("test2 size:%d\n",sizeof(struct test2));
    /*
        理论：13个字节
        实际：内存对齐后，16个字节

        int a 地址0-3 4个字节
        float b 4v8取4 地址4-7 4个字节
        test1内存地址总的偏移0-7共8个字节

        float a 地址0-3 4个字节
        char b 1v8取1 地址4 1个字节
        struct test1 c 取最大对齐数4 地址8-15 8个字节
        test2内存地址总的偏移0-15共16个字节
    */
}

struct t1{
    char a;
    int b;
    char c;
};

struct t2{
    char a;
    char c;
    int b;
};

void test4(){
    printf("t1 size:%d\n",sizeof(struct t1));
    /*
        地址偏移：0,4-7,8 -> 0-9=9(最大对齐数4) -> 12
    */

    printf("t2 size:%d\n",sizeof(struct t2));
    /*
        地址偏移：0,1,4-7 -> 0-7=8(最大对齐数4) -> 8
    */
}

int main(){
    test1();
    test2();
    test3();

    test4();

    return 0;
}