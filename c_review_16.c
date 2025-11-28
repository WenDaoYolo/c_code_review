#include<stdio.h>
/*
    指针篇
    指针-指针
    指针运算符的结合律

    案例分析
    int arr[4]={1,2,3,4} 
    short* pa=arr;

                        低地址                                    高地址
    以字节为单位的存储顺序 小端:01000000 02000000 03000000 04000000
                      数据低位                                    数据高位

    大端存储:
    00000001 00000002 00000003 00000004 =1,2,3,4
    000A0000 001e0014 00000003 00000004 =655360,1966100,3,4

    指针的相关注意事项
*/

void test1(){
    int arr[3] = { 1,2,3 };
    printf("%d\n",&arr[2]-&arr[0]);
    printf("%d\n", &arr[2]+1 - &arr[0]);     //即&arr[3]-&arr[0]
}

void test2(){
    int arr[2]={1,3};
    printf("%d\n",*(arr+1));
    printf("%d\n",*arr+1);
}

int* test3()             //wild pointer
{
    int s=3;
    int* ps=&s;
    printf("normal pointer:%d\n",*ps);
    return ps;
}

void test4(){             //wild pointer
    int arr[4]={1,2,3,4};
    int* parr=arr;
    for(int i=0;i<=4;i++)
        printf("%d ",parr[i]);
    putchar('\n');
}

void test5(){              //pointer can not initzation
    int* ps;
    char* pa;
    printf("wild pointer:%d,%c\n",*ps,*pa);
}

int main(){
    //test1();
    //test2();
    
    int* ptr=test3();
    printf("wild pointer:%d\n",*ptr);
    
    test4();
    //test5();

    return 0;
}
