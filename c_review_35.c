#include<stdio.h>
#include<assert.h>
/*
    函数进阶篇
    模拟实现各类函数
    strncmp,strncat,strncpy
*/

int my_strncmp(const char* str1,const char* str2,int n){
    assert(str1!=NULL);
    assert(str2!=NULL);

    int tmp=1;
    while(*str1==*str2&&tmp<=n){
        if(*str1=='\0'||tmp==n)
            return 0;
        tmp++;
        str1++;
        str2++;
    }
    return *str1-*str2;
}

char* my_strncpy(char* destination,const char* source,int n){
    assert(destination!=NULL);
    assert(source!=NULL);

    while(*destination++=*source++,--n>0)
        if(*source=='\0')
            break;

    while(n>0)
    {
        *destination++='\0';
        n--;
    }

    return destination;
}

char* my_strncat(char* destination,const char* source,int n){
    assert(destination!=NULL);
    assert(source!=NULL);
    char* tmp=destination;

    while(*destination++!='\0');
    destination--;                   //找到\0后还会++一次，所以要回退到\0的位置

    while(*source!='\0'&&n-->0)
        *destination++=*source++;

    *destination='\0';
    return tmp;
}

void test1(){
    char str1[]="abcdws";
    char str2[]="abcdfs";

    if(my_strncmp("jackts","jackww",4)==0)
        printf("part of them are same!\n");
    
    if(my_strncmp(str1,str2,5)>0)
        printf("str1 > str2!\n");

    if(my_strncmp(str2,str1,5)<0)
        printf("str1 < str2!\n");
}

void test2(){
    char str[20]="hello world!";
    my_strncpy(str," jackisok",5);
    printf("%s\n",str);

    char str2[20]="hello world!";
    my_strncpy(str2," jackisok",20);
    printf("%s\n",str2);
}

void test3(){
    char str1[20]="hello";
    char str2[20]="world";
    char str3[20]="jack";

    my_strncat(str1,"jack",3);
    my_strncat(str2,"jack",5);
    my_strncat(str3,"jack",10);

    printf("%s\n",str1);
    printf("%s\n",str2);
    printf("%s\n",str3);
}

int main(){
    test1();
    test2();
    printf("-------\n");
    test3();

    return 0;
}