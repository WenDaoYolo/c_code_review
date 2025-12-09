#include<stdio.h>
/*
    进阶指针篇
*/

    //字符指针
void charptr(){
    char test1[]="helloworld";
    char test2='S';

    char* cptr1=test1;
    char* cptr2=&test2;

    //同理，c语言的const是不安全的，可以通过指针改变
    *cptr1='A';
    *cptr2='C';
    //%s字符串遇到/0停止，所以以字符串格式输出时，传递参数为字符串首元素地址
    printf("%s,%c\n",cptr1,*cptr2);   
}

    //指针数组
void ptrarry(){
    int* iptr1=NULL;
    int* iptr2=NULL;
    int* iptr3=NULL;
    char* cptr1=NULL;
    char* cptr2=NULL;
    char* cptr3=NULL;

    int* int_ptr_arr[3]={iptr1,iptr2,iptr3};
    char* char_ptr_arr[3]={cptr1,cptr2,cptr3};
}

//指针数组
void ptrarry02(){
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    int c[]={9,9,9};
    int* array_ptr[]={a,b,c};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d,%d ",array_ptr[i][j],*(*(array_ptr+i)+j));
        putchar('\n');
    }
}

int main(){
    charptr();
    ptrarry();
    ptrarry02();

    return 0;
}