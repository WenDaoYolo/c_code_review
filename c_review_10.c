#include<stdio.h>
#define LINE 4
#define ROW 4
/*
    二维数组
    1.定义，初始化
    2.访问，使用
    3.注意事项
*/

void PrintIA(int arr[LINE][ROW]){
    for(int i=0;i<LINE;i++)
    {
        printf("int_arr[%d]:",i);
        for(int j=0;j<ROW;j++)
            printf("%d ",arr[i][j]);
        putchar('\n');
    }
}

void test1(){
    int arr1[2][4]={{1,2,3,4},{0,1}};
    int arr2[][5]={3,3,3,3,3,4};

    arr1[0][0]=2;        //数组下标法
    *(arr2[0]+1)=1;      //数组下标法+指针偏法
                         //二维数组名==二维数组首元素地址==一维数组地址
                         //二维数组元素==一维数组名
                         //一维数组名==一维数组首元素地址
                         //arr2等价于&arr2[0],arr2[0]等价于&arr2[0][0]
    PrintIA(arr1);
    PrintIA(arr2);
}

int main(){
    test1();
    int a[5];

    return 0;
}