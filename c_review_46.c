#include<stdio.h>
#include<stdlib.h>
/*
    动态内存进阶篇
    动态内存开辟常见错误
*/

//1.不对返回值进行判断，直接接收并解引用
void test1(){
    int* ptr=(int*)malloc(sizeof(10000000000000000000000)); //有时候空间过大可能开辟失败
    *ptr=30;
    printf(":%d\n",*ptr);

    free(ptr);
    ptr=NULL;
}

//2.越界访问非法内存
void test2(){
    int* ptr=(int*)malloc(sizeof(int)*2);
    if(ptr==NULL)
        perror("malloc:");
    
    for(int i=0;i<10;i++)
    {
        *(ptr+i)=i*10;
        printf("%d ",*(ptr+i));
    }
    putchar('\n');

    free(ptr);
    ptr=NULL;
}

//3.对同一块空间重复释放
void test3(){
    int* ptr=(int*)malloc(sizeof(int));
    if(ptr==NULL)
        perror("malloc:");

    int* ptr_2=ptr;
    free(ptr);       //ptr和ptr_2指向同一块空间,这块空间被重复释放
    free(ptr_2);
    ptr=NULL;
    ptr_2=NULL;
}

//4.使用free释放非动态内存
void test4(){
    int a=20;
    int* ptr=&a;

    free(ptr);
    ptr=NULL;
}

//5.内存泄漏
void test5(){
    int* ptr=(int*)malloc(sizeof(int)*20);
    if(ptr=NULL)
        perror("malloc:");
    
    ptr=NULL;  //内存未释放，指针置空后则找不到内存空间
}

//6.对已经释放的内存再次进行访问(也属于非法内存访问)
void test6(){
    int* ptr=(int*)malloc(sizeof(int));
    if(ptr=NULL)
        perror("malloc:");
    
    free(ptr);
    *ptr=30;
}   

//7.只释放部分开辟的内存而非全部(也属于内存泄漏)
void test7(){
    int* ptr=(int*)malloc(sizeof(int)*10);
    if(ptr=NULL)
        perror("malloc:");

    ptr+=5;       //ptr指针偏移到地址+5处
    free(ptr);    //只释放了后面20个字节的空间，前面20个字节的空间未释放
    ptr=NULL;
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();

    return 0;
}