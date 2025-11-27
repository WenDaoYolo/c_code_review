#include<stdio.h>
/*
    Ö¸ÕëÆª
*/

void test1(){
    printf("int*:%d,\n",sizeof(int*));
    printf("float*:%d\n",sizeof(float*));
    printf("char*:%d\n",sizeof(char*));
    printf("long long*:%d\n",sizeof(long long*));
}

void test2(){
    int a=3;
    int* pa=&a;
    int** ppa=&pa;
    printf("a:%d,%p\n",a,&a);
    printf("pa:%d,%p,%p\n",*pa,pa,&pa);
    printf("ppa:%d,%p,%p\n",**ppa,ppa,&ppa);
}

void test3(){
    int arr[3]={1,2,3};
    int* parr=arr;
    arr[0]=999;
    *(arr+1)=666;
    *(parr+2)=333;
    printf("arr:%d,%d,%d\n",arr[0],arr[1],arr[2]);
}

void test4(){
    //int* ss=&ss;         //error
    //int* w;              //wild pointer
    //*w=333;              //´æÔÚ·çÏÕ
}

int main(){
    //test1();
    //test2();
    test3();
    test4();

    return 0;
}