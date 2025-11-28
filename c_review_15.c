#include<stdio.h>
    /*
        指针篇
        指针类型的意义
        指针运算
    */

                                  //指针可以指向不同类型的对象,但是不建议这么做
void test1(){
    int a=0x66661234;
    char* cpa=&a;                 //char类型的指针只能访问一个字节的空间
    short* spa=(short*)&a;        //short类型的指针只能访问两个字节的空间
                                  //强制类型转换，取消警告                              

    printf("cpa:%d\n",*cpa);      //取低一个字节空间的值，0x34 = 52
    printf("spa:%d\n",*spa);      //取低两个字节空间的值，0x1234 = 4096+512+52 = 4660
}

void test2(){
    int s1;

    char aa;
    short bb;
    int cc;
    float dd;
    double ee;

    char* a=&aa;
    short* b=&bb;
    int* c=&cc;
 
    printf("test int:%p next:%p\n",&s1,&s1+1);                     //直接操作地址进行运算
    
    printf("char:%p next:%p\n",a,a+1);                             //操作指针间接进行运算
    printf("short:%p next:%p\n",b,b+1);
    printf("int:%p next:%p\n",c,c+1);
}

void test3(){
    printf("\n----------------------\n");
    int arr[4]={1,2,3,4};
    short* pa=arr;

    printf("before:");
    for(int i=0;i<4;i++)
        printf("%d ",arr[i]);
    putchar('\n');             //大端存储：
                               //00000001 00000002 00000003 00000004 =1,2,3,4
    for(int i=0;i<4;i++)       //000A0000 001e0014 00000003 00000004 =655360,1966100,3,4
        *(pa+i)=10*i;          //小端存储：

    printf("after:");
    for(int i=0;i<4;i++)
        printf("%d ",arr[i]);
    putchar('\n');
}

void test4(){
    int arr[2]={1,2};               //数组地址从低到高变化
    if(&arr[0]<&arr[1])
	    printf("<\n");
    if(&arr[0]==&arr[0])
	    printf("==\n");
}

void test5(){
    int arr[3]={1,2,3};
    int* parr=arr;
    printf("%d\n",*(arr+1));        //直接运算，等价于下标法 arr[1]
    printf("%d\n",*(parr+2));       //间接运算，等价于下标法 parr[2]
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    test5();

    return 0;
}