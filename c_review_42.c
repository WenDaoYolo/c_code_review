#include<stdio.h>
#include<stdlib.h>
/*
    结构体进阶篇
    柔性数组
*/

struct test{
    int a;
    char b;
    int arr[];
};

void PrintArr(struct test* pt,int num){
    for(int i=0;i<num;i++)
    {
        printf("%d ",pt->arr[i]);
    }
        putchar('\n');
}

void InitArr(struct test* pt,int num){
    for(int i=0;i<num;i++)
    {
        pt->arr[i]=i*10;
    }

    pt->a=-1;
    pt->b='w';
}

void Destroy(struct test* pt){
    free(pt);
    pt=NULL;
    printf("Destroy success!\n");
}

void test1(){
    struct test* pt=(struct test*)malloc(sizeof(struct test)+10*sizeof(int));
    InitArr(pt,10);
    PrintArr(pt,10);
    printf("before stuct size:%d\n",sizeof(*pt));

    struct test* tmp=(struct test*)realloc(pt,sizeof(struct test)+20*sizeof(int));
    if(tmp==NULL)
    {
        printf("realloc is error!\n");
        return;
    }

    pt=tmp;
    tmp=NULL;
    InitArr(pt,20);
    PrintArr(pt,20);
    printf("after stuct size:%d\n",sizeof(*pt));
    
    Destroy(pt);
}

int main(){
    test1();

    return 0;
}
