#include<stdio.h>
#include<ctype.h>
/*
    函数进阶篇
    模拟实现各类函数
    字符函数
*/

void test1(){
    char Big='W';
    char small='w';
    int integer=50;

    if(isupper(Big))
        printf("%c is upper!\n",Big);
    if(islower(small))
        printf("%c is lower!\n",small);

    if(isdigit('5'))
        printf("%c is digit!\n",'5');

    printf("after:%c\n",tolower(Big));
    printf("after:%c\n",toupper(small));
}

void test2(){
    char str1[10]="hELLO";
    char* ptr=str1;
    
    printf("before:%s\n",str1);

    while(*ptr!='\0')
    {
        if(isupper(*ptr))
            *ptr=tolower(*ptr);
        else
            *ptr=toupper(*ptr);         
        ptr++;
    }

    printf("after:%s\n",str1);    
}

//***模拟实现isupper,islower,toupper,tolower,isdigit***

int my_toupper(char s){
    if(s>='a'&&s<='z')
        return s-32;
    else
        return -1;
}

int my_tolower(char s){
    if(s>='A'&&s<='Z')
        return s+32;
    else
        return -1;
}

int my_isdgit(char s){
    if(s>='0'&&s<='9')
        return 1;
    return 0;
}

int my_isupper(char s){
    if(s>='A'&&s<='Z')
        return 1;
    return 0;
}

int my_islower(char s){
    if(s>='a'&&s<='z')
        return 1;
    return 0;
}

void test3(){
    char a1='W';
    char b1='w';
    char c1='5';

    if(my_isdgit(c1))
        printf("%c is digit\n",c1);
    if(my_isdgit(a1))
        printf("%c is digit\n",a1);

    if(my_islower(b1))
        printf("%c is lower\n",b1);
    if(my_islower(a1))
        printf("%c is lower\n",a1);

    if(my_isupper(b1))
        printf("%c is upper\n",b1);
    if(my_isupper(a1))
        printf("%c is upper\n",a1);
    
    printf("%c -> %c\n",a1,tolower(a1));
    printf("%c -> %c\n",b1,toupper(b1));
}

int main(){
    test1();
    printf("--------\n");
    test2();
    printf("--------\n");
    test3();

    return 0;
}