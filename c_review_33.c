#include<stdio.h>
#include<string.h>
/*
    函数进阶篇
    使用各类函数
    strlen
    strcmp,strcat,strcpy
    strncmp,strncat,strncpy
    strtok,strstr,strerror
*/

void test1(){
    const char* str1="hello world!";
    char str2[10]="hela";
    
    if(strcmp(str1,str2)>0)
        printf("str1>str2\n");
    else if(strcmp(str1,str2)<0)
        printf("str1<str2\n");
    else
        printf("str1 = str2\n");
    
    printf("str1 length:%d\n",strlen(str1));
    printf("str2 length:%d\n",strlen(str2));
}

void test2(){
    const char* str1="jack";
    char str2[20]="hello!";
    
    strcat(str2,str1);
    printf("%s\n",str2);

    strcpy(str2,str1);
    printf("%s\n",str2);
}

void test3(){
    char str1[10]="JACK OK";
    char str2[10]="JACK KO";
    if(strncmp(str1,str2,4)>0)
        printf("str1>str2\n");
    else if(strncmp(str1,str2,4)<0)
        printf("str1<str2\n");
    else 
        printf("str1 = str2\n");

    strncat(str1,str2,1);
    printf("strncat:%s\n",str1);

    strncpy(str1,str2,6);
    printf("strncpy:%s\n",str1);
}

void test4(){
    perror("test4():\n");
    printf("errorno 0:%s\n",strerror(0));
    printf("errorno 1:%s\n",strerror(1));
    printf("errorno 2:%s\n",strerror(2));
    printf("errorno 3:%s\n",strerror(3));
    printf("errorno 4:%s\n",strerror(4));
    printf("errorno 5:%s\n",strerror(5));
    printf("errorno 6:%s\n",strerror(6));
    printf("errorno 7:%s\n",strerror(7));
}

void test5(){
    char str1[20]="jack is a good boy!";
    char str2[10]="girl";
    char str3[10]="good";
    char* position=NULL;

    if(position=strstr(str1,str2),position==NULL)
        printf("%s is not child string of %s\n",str2,str1);
    else
    {
        printf("%s is child string of %s\n",str2,str1);
        //指针相减求之间的元素个数，不包含尾元素则刚好对应下标位置
        printf("position int string1:%d\n",position-str1);
    }
    
    if(position=strstr(str1,str3),position==NULL)
        printf("%s is not child string of %s\n",str3,str1);
    else
    {
        printf("%s is child string of %s\n",str3,str1);
        printf("position int string1:%d\n",position-str1);
    }
}

void test6(){
    //单次切割
    char str1[]="3547474131@qq.com";
    char* revalue;
    char flag[]="@.";
    
    revalue=strtok(str1,flag);
    printf("%s\n",revalue);

    revalue=strtok(NULL,flag);
    printf("%s\n",revalue);

    revalue=strtok(NULL,flag);
    printf("%s\n",revalue);

    //循环切割
    char str[]="wanggong_2306450114_lyy";
    char* rep=NULL;
    for(rep=strtok(str,"_");rep!=NULL;rep=strtok(NULL,"_"))  //for循环初始部分只执行一次
        printf("%s\n",rep);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}