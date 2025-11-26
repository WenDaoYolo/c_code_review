#include<stdio.h>
#include<string.h>
#define N 5

/*
    一维数组
    1.定义，初始化
    2.访问，使用
    3.注意事项
*/

void PrintIA(int int_arr[N]){
    for(int i=0;i<N;i++)
        printf("%d ",int_arr[i]);
    putchar('\n');
}

void PrintFA(float float_arr[N]){
    for(int i=0;i<N;i++)
        printf("%.2f ",float_arr[i]);
    putchar('\n');
}

void test1(){
    int int_arr[N]={0};              //全0初始化，其余默认补缺省值0
    float float_arr[N]={1,2,3};      //不完全初始化，其余默认补缺省值
    int_arr[0]=2;                    //数组下标法
    *(int_arr+1)=4;                  //指针偏移法

    float* parr=float_arr;
    parr[0]=6;                       //指针下标法，等价于数组下标法
    *(parr+1)=9;                     //指针偏移法
    PrintIA(int_arr);
    PrintFA(float_arr);
}

void test2(){
    char str1[]={"hello word"};              //length=11,字符串初始法,自动补\0
    char str2[]={"what's your name?"};       //length=18,字符串初始法,自动补\0
    char str3[5]={'J','A','C','K','\0'};     //length=5,单字符初始法,手动补\0
    char char_arr[4]={'C','H','A','R'};      //length=4
    
    str1[0]='H';
    strcpy(str3,"MACK");                     //利用函数一次性修改数组的值

    printf("%s\n",str1);
    printf("%s\n",str2);
    printf("%s\n",str3);
    printf("%s\n",char_arr);                 //没有\0结束符，会在内存中先后持续访问
                                             //直到找到\0结束，会出现非法内存访问的情况              
}

int main(){
    test1();
    test2();
    
    return 0;
}