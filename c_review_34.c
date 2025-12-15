#include<stdio.h>
#include<string.h>
#include<assert.h>
/*
    函数进阶篇
    模拟实现各类函数
    strlen,strcmp,strcat,strcpy
*/

int my_strlen(const char* str){
    const char* ptr=str;
    int length=0;
    while(*ptr!='\0')
    {
        length++;
        ptr++;
    }
    return length;
}

int my_strcmp(const char* str1,const char* str2){
    if(str1==NULL||str2==NULL)
    {
        printf("error:null ptr!\n");
        return -999;
    }    

    while(*str1!='\0'||*str2!='\0'){
        if(*str1>*str2)
            return 1;
        else if(*str1<*str2)
            return -1;
        str1++;
        str2++;
    }

    if(*str1=='\0'&&*str2=='\0')
        return 0;
    else if(*str1=='\0')
        return -1;
    else
        return 1;
}

int my_strcmp2(const char* str1,const char* str2){
    assert(str1!=NULL&&str2!=NULL);
    while(*str1==*str2)          //先判断他们是否相同
    {
        if(*str1=='\n')
            return 0;
        str1++;
        str2++;
    }
    return *str1-*str2;          //若不相同则跳出循环，然后返回他们的差值
}

char* my_strcat(char* destination,const char* source){
    assert(destination!=NULL);
    assert(source!=NULL);

    while(*destination!='\0')
        destination++;

    while(*source!='\n')
    {
        *destination=*source;
        destination++;
        source++;
    }
    
    *destination='\0';
    return destination;
}

char* my_strcpy(char* destination,const char* source){
    assert(destination!=NULL);
    assert(source!=NULL);

    while(*source!=0){
        *destination=*source;
        destination++;
        source++;
    }
    *destination='\0';

    return destination;
}

void test1(){
    char s[]="hello world!";
    printf("the string:%s length is:%d\n",s,my_strlen(s));
}

void test2(){
    char str1[]="abcdefg";
    char str2[]="ABCDEFG";

    if(my_strcmp("jack","hello world")>0)
        printf(">0 yes!\n");

    if(my_strcmp("jack","jack")==0)
        printf("==0 yes!\n");

    if(my_strcmp(str2,str1)<0)
        printf("<0 yes!\n");

    if(my_strcmp(str2,NULL)>0)
        printf("null test!\n");
}

void test3(){
    char str1[]="abcdefg";
    char str2[]="ABCDEFG";

    if(my_strcmp2("jack","hello world")>0)
        printf(">0 yes!\n");

    if(my_strcmp2("jack","jack")==0)
        printf("==0 yes!\n");

    if(my_strcmp2(str2,str1)<0)
        printf("<0 yes!\n");

    //if(my_strcmp2(str2,NULL)>0)
    //printf("null test!\n");
}

void test4(){
    char str[20]="hello world";
    my_strcat(str,",lyy");
    printf("%s\n",str);

    //my_strcpy(NULL,NULL);
}

void test5(){
    char str1[20]={0};
    my_strcpy(str1,"my name is lyy!");
    printf("%s\n",str1);
    //my_strcpy(NULL,NULL);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}