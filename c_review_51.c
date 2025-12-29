#include<stdio.h>
#include<windows.h>
/*
    文件进阶篇
    文件的原理和测试--文件读取的结束以及文件缓冲区
    
*/


/*                    通用组件                     */
void CloseFile(FILE* ptr1,FILE* ptr2){
    fclose(ptr1);
    fclose(ptr2);
    ptr1=NULL;
    ptr2=NULL;
}

void CheckFile(FILE* ptr1,FILE* ptr2){
    if(ptr1==NULL||ptr2==NULL)
        perror("fopen:");
}

void CheckEndType(FILE* ptr_source){
    if(feof(ptr_source))
        printf("read finished!\n");
    else if(ferror(ptr_source))
        printf("read error!\n");
}
/*                    通用组件                     */

void CopyNewTxt_0(){
    FILE* ptr_source=fopen("./test51.txt","r");
    FILE* ptr_destination=fopen("./test51_0.txt","w");
    CheckFile(ptr_source,ptr_destination);

    int c;
    while((c=fgetc(ptr_source))!=EOF)          //!=的优先级高于=赋值
        fputc(c,ptr_destination);
    
    
    CheckEndType(ptr_source);
    CloseFile(ptr_source,ptr_destination);
}

#define ONCE_SIZE 5

void CopyNewTxt_1(){
    FILE* ptr_source=fopen("./test51.txt","r");
    FILE* ptr_destination=fopen("./test51_1.txt","w");
    CheckFile(ptr_source,ptr_destination);
    
    char buffer[5]={0};
    int count=0;
    while(fgets(buffer,ONCE_SIZE,ptr_source)!=NULL)
        printf("count:%d\n",++count),fputs(buffer,ptr_destination);

    CheckEndType(ptr_source);
    CloseFile(ptr_source,ptr_destination);
}

#define once_size 3

void CopyNewTxt_2(){
    FILE* ptr_source=fopen("./test51.txt","r");
    FILE* ptr_destination=fopen("./test51_2.txt","w");
    CheckFile(ptr_source,ptr_destination);
    char buffer[once_size];
    size_t real=0;

    do{
        real=fread(buffer,sizeof(char),once_size,ptr_source);
        fwrite(buffer,sizeof(char),real,ptr_destination);
    }while(real==once_size);

    CheckEndType(ptr_source);
    CloseFile(ptr_source,ptr_destination);
}

void TestFileBuffer_0(){
    FILE* ptr=fopen("./test51_3.txt","w");
    CheckFile(ptr,ptr);
    fputs("文件缓冲区已刷新!\n",ptr);
    
    printf("立即查看文本文件,发现函数执行完成后数据并没有立即写入\n");
    printf("等待10s后,文件输出缓冲区立即刷新,此时再次查看文本文件\n");
    Sleep(10000);
    fflush(ptr);
    printf("Program Finished!\n");
}

int main(){
    //CopyNewTxt_0();
    //CopyNewTxt_1();
    //CopyNewTxt_2();
    TestFileBuffer_0();

    return 0;
}