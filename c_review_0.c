#include<stdio.h>

int g_test1=666;
static int g_test2=999;

// enum weekday{
//     mond=1,
//     tues=2,
//     wend=3,
//     thir=4,
//     frid,     //5
//     stur,     //6
//     sun       //7
// };

// int main(){
//     enum weekday now=stur;
//     short int a1=30;
//     short aa1=40;
//     int a2=40;
//     long int a3=400;
//     long a33=4001;
//     long long int a4=500;
//     long long a44=5001;

//     float a=4.1;
//     double b=4.22;
//     char c='c';
//     char d[]={"string"};        //or "string"
//     char d2[]={'s','t','r','i','n','g','\0'};

//     int* s1;
//     float* s2;
//     void* s3;
    
//     printf("enum:%d,%d\n",now,sizeof(now));
//     printf("short int:%d,%d\n",a1,sizeof(a1));
//     printf("int:%d,%d\n",a2,sizeof(a2));
//     printf("long int:%d,%d\n",a3,sizeof(a3));
//     printf("long long int:%d,%d\n",a4,sizeof(a4));

//     printf("---------\n");

//     printf("float:%-4.4f,%d\n",a,sizeof(a));
//     printf("double:%lf,%d\n",b,sizeof(b));
//     printf("char:%c,%d\n",c,sizeof(c));
//     printf("string1 :%s,%d\n",d,sizeof(d));
//     printf("string2:%s,%d\n",d2,sizeof(d2));

//     printf("---------\n");

//     printf("int*:%p,%d\n",s1,sizeof(s1));
//     printf("float*:%p,%d\n",s2,sizeof(s2));
//     printf("void*:%p,%d\n",s3,sizeof(s3));
//     printf("void:%d\n",sizeof(void));
    
//     int* sss=NULL;
//     printf("NULL:%d\n",sss);

//     return 0;
// }