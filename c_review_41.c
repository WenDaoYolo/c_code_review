#include<stdio.h>
/*
    结构体进阶篇
    位段
*/

struct test1{
    int a:2;
    int b:4;
    int c:6;
    int d;
    int f;
};

struct test2{
    int a:2;
    int b:30;
    int c:6;
};

void test11(){
    printf("test1 size:%d\n",sizeof(struct test1));
    /*
        int a,开辟4个字节32位,a使用2位，剩余30位
        int b,剩余30位，b使用4位，剩余24位
        int c,剩余24位，c使用6位，剩余18位
        int d,开辟4个字节
        int f,开辟4个字节

        总共开辟4+4+4个字节，所以结构体的大小为12个字节
    */
}

void test22(){
    printf("test2 size:%d\n",sizeof(struct test2));
    /*
        int a,开辟4个字节32位,a使用2位，剩余30位
        int b,剩余30位，b使用30位，剩余0位
        int c,剩余0位不够，int类型则开辟4个字节，使用6位剩余26位

        总共开辟4+4个字节，所以结构体的大小为8个字节
    */
}

int main(){
    test11();
    test22();

    return 0;
}