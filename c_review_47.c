#include<stdio.h>
#define TAX 5
#define STRING "helloworld"
#define ADD(x,y) ((x)+(y))

#define FUN1 \
printf("why?\n");

#define MAX 50
#define MIN 1
#define MMADD (M##AX+MI##N)
#define ITOS(s) #s
#define PRINT(x,FORMAT) printf("the value of "#x" is:" FORMAT,x);

/*
    进阶篇预处理
*/

void WriteLog(){
    FILE* ptr=fopen("log.txt","a+");
    if(ptr==NULL)
        perror("fopen");
    //更新后需要重新生成文件，所以可以记录文件的更新时间
    fprintf(ptr,"更新时间:%s %s 文件位置:%s 行数:%d\n",__DATE__,__TIME__,__FILE__,__LINE__);
    fclose(ptr);
    ptr=NULL;
}
#define max(a,b) ((a)>(b)?(a):(b))

#define test2 20

int main(){
    printf("%d,%s\n",TAX,STRING);
    printf("%d\n",ADD(3,4));
    FUN1
    printf("%d\n",MMADD);
    int test=1314;
    printf("variable:%s,value:%d\n",ITOS(test),test);
    printf("hello"" world!""\n");
    PRINT(test,"%d");

    int m=3;
	int n=4;
	int s=max(m++,n++);            //会被替换为((m++)>(n++)?(m++):(n++)),直接替换的操作，会使得参数发生多次变动，并且是永久性的
	printf("\n%d %d %d\n",s,m,n);  //5 4 6

    printf("%d\n",test2);
    #undef test2                   //移除预定义标识符
    //printf("%d\n",test2);        //无法识别

    WriteLog();
    return 0;
}