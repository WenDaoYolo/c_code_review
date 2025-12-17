#include<stdio.h>
/*
    结构体进阶篇

*/

//设置默认对齐数为2个字节
#pragma pack(2)

struct test{
	char b;
	int a;
	char c;
};

void test1(){
    printf("test size:%d\n",sizeof(struct test));
    /*
        默认对齐数:2
        char b：地址0,大小1字节
        int a：对齐数2,地址2-5,大小4字节
        char c：对齐数1,地址6,大小1字节
        内存总地址：0-6,7个字节,最大对齐数2,所以补充至2的最小整数倍8
        所以结构体最终地址和大小:0-7共8个字节
    */  
}

typedef struct stu{
    int a;
    char b;
    float c;
}stu1_3;

void print1(stu1_3 sw){
    printf("%d,%d,%.2f\n",sw.a,sw.b,sw.c);
}

void print2(stu1_3* sw){
    printf("%d,%d,%.3f\n",sw->a,sw->b,sw->c);
}

void test2(){
    stu1_3 s={3,4,5.6};
    print1(s);
    print2(&s);
}

int main(){
    test1();
    test2();

    return 0;
}

//还原默认对齐数
#pragma pack()