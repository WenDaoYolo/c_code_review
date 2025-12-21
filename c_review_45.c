#include<stdio.h>
#include<stdlib.h>
/*
    动态内存进阶篇
    动态内存函数
*/

void test1(){
    int* ptr=(int*)malloc(sizeof(int)*10);
    if(ptr==NULL)
        perror("malloc:");

    for(int i=0;i<10;i++)
        printf("%d ",*(ptr+i));
    putchar('\n');

    for(int i=0;i<10;i++)
        *(ptr+i)=i*10;

    for(int i=0;i<10;i++)
        printf("%d ",*(ptr+i));
    putchar('\n');

    free(ptr);
    ptr==NULL;
}

void test2(){
    int* ptr=(int*)calloc(3,sizeof(int));
    if(ptr==NULL)
        perror("calloc:");
    
    for(int i=0;i<3;i++)
        printf("%d ",*(ptr+i));
    putchar('\n');

    for(int i=0;i<3;i++)
        *(ptr+i)=i*100;

    for(int i=0;i<3;i++)
        printf("%d ",*(ptr+i));
    putchar('\n');

    free(ptr);
    ptr=NULL;
}

void value_input(int* ptr,int num){
    for(int i=0;i<num;i++)
        *(ptr+i)=i*2;
}

void value_output(int* ptr,int num){
    for(int i=0;i<num;i++)
        printf("%d ",*(ptr+i));
    putchar('\n');
}

void test3(){
    int num=10;
    int* ptr=(int*)malloc(sizeof(int)*num);
    if(ptr==NULL)
        perror("malloc:");

    value_input(ptr,num);
    value_output(ptr,num);

    num=20;
    int* tmp=(int*)realloc(ptr,sizeof(int)*num);
    if(tmp==NULL)
        perror("realloc:");
    ptr=tmp;
    tmp=NULL;

    value_input(ptr,num);
    value_output(ptr,num);
    
    free(ptr);
    ptr=NULL;
}

void test4(){
    char* ptr=(char*)realloc(NULL,sizeof(char));
    *ptr='w';
    printf("value:%c\n",*ptr);

    free(ptr);
    ptr=NULL;
    
    free(ptr);          //free参数为NULL，不会发生任何行为
}

int main(){
    test1();
    printf("------\n");
    test2();
    printf("-------\n");
    test3();
    test4();

    return 0;
}