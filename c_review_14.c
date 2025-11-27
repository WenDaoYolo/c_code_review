#include<stdio.h>

/*
    指针篇
    数组传参
    数组指针
    指针数组
*/

void test1(){
    int a1=3,a2=4,a3=5;
    int* arr[3]={&a1,&a2,&a3};
    for(int i=0;i<3;i++)
        printf("%d ",*arr[i]);
    putchar('\n');
}

void test2(){
    int arr2[]={1,2,3,4,5,6};
    int (*parr1)[]=&arr2;
    int (*parr2)[6]=&arr2;
}

void test3(int arr[5],int length){
    printf("outside size:%d\n",length);
    printf("inside size:%d\n",sizeof(arr));
}

int main(){
    int arr[5]={0};
    test1();
    test2();
    test3(arr,sizeof(arr));

    return 0;
}