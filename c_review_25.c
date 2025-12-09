#include<stdio.h>
/*
    进阶指针篇
*/

    //数组指针
void arrayptr(){
    int arr[3]={0};
    int* parrf=arr;                        //整型指针，指向数组的首元素
    int (*parr)[3]=&arr;                   //数组指针，指向整个数组

    (*parr)[0]=1;
    printf("after:%d\n",(*parr)[0]);       //解引用得到整个数组即数组名，再通过下标来访问数组的元素
                                           //注意此时无法直接通过指针偏移的方式来访问数组内元素
                                           //因为指针的类型为数组，一次偏移会跳过整个数组
    printf("after:%d\n",*((*parr)+1));     //可以解引用得到数组名即首元素地址后再进行指针的偏移
    printf("after:%d\n",*((int*)parr+1));  //可以强转指针的类型再来访问(强转后指针指向内存首地址,即首元素)
 } 

void test1(){
    int test[3]={1,2,3};
    int(*pt)[3]=&test;
    printf("%d\n",*(*pt));
}

    //数组指针数组
void arrayptr_array(){
    int (*ptr[3])[3];
    char (*d[10])[5];
}
    //数组指针与指针指向了数组
void test2(){
    int arr[3]={1,2,3};
    int* parrf=arr;
    int (*parr)[3]=&arr;
    printf("parrf:%p,+1:%p,size:%d\n",parrf,parrf+1,sizeof(*parrf));
    printf("parr:%p,+1:%p,size:%d\n",parr,parr+1,sizeof(*parr));       //解引用得到整个数组即数组名
}                                                                      //sizeof(数组名)求得则是整个数组大小

//数组指针接收一维数组传参
void test3(int (*ptr)[],int length){
    for(int i=0;i<length;i++)
        printf("%d ",(*ptr)[i]);
    putchar('\n');
}

//数组指针接收二维数组传参,注意指针指向数组的长度必须确定
//因为数组指针在偏移时需要根据数组大小来确定步长，其次二维数组列的长度必须确定
void test4(int (*ptr)[3],int length){      
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",(*(ptr+i))[j]);
        putchar('\n');
    }
}

void test34(){
    int arr[3]={1,2,3};
    int arr2[4][3]={{1,2,3},{3,2,1},{1,1,1},{3,3,3}};
    test3(&arr,3);
    test4(arr2,4);
}

 int main(){
    arrayptr();
    test1();
    arrayptr_array();
    test2();
    test34();

    return 0;
 }