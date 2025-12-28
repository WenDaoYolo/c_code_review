#include<stdio.h>
/*
    文件进阶篇
    顺序读写
*/

void test1(){
    FILE* ptr=fopen("./test.txt","w");
    if(ptr==NULL)
        perror("fopen:");
    else
        printf("open file success!\n");

    fputc('L',ptr);
    fputc('Y',ptr);
    fputc('Y',ptr);

    fputs("hello world\n""myname is",ptr);
    fprintf(ptr,"this is \na test[%s][%d]\n","2306450114",3);

    //以二进制的形式写入外存,格式更加通用，测试:64(小端存储)->01000000 0 0 0
    //->通过专用的二进制文本编辑器来查看
    int tst=64;
    fwrite(&tst,sizeof(int),1,ptr);  //基址，元素的大小，元素的数量->数量和边界的确定

    fclose(ptr);
    ptr==NULL;
}

void test2(){
    FILE* ptr=fopen("./test.txt","r");
    printf("Order 1:%c\n",fgetc(ptr));
    printf("Order 2:%c\n",fgetc(ptr));
    printf("Order 3:%c\n",fgetc(ptr));

    //注意因为读取的数据是常量值,需要存储起来,所以要定义变量空间来暂存，而非指针索引的方式来指向
    //因为指针只能指向不能存储，而读取出来的数据需要先存储起来，不能直接去操作的
    char str[30];

    //字符串格式读取需要\0结束符，编译器会默认将数组尾元素填充\0
    //不管指定字符数多大，fgets最多只读取一行的数据
    fgets(str,30,ptr);         
    printf("Order 4:%s\n",str);

    //此时文件指针偏移到第二行首字符处

    //以字符串的形式读取数据，读取字符遇到\0为止
    //注意scanf系列函数读取到空格，回车(换行符\n)，tab制表键也会停止读取
    fscanf(ptr,"%s",&str);
    printf("string read:%s\n",str);

    char str2[20];
    //此时指针偏移到文件第二行空格处
    fread(str2,11,1,ptr);
    printf("fread value:%s\n",str2);
}

int main(){
    //when test1 funcion finished,to lookup the test.txt
    test1();
    
    //read data from test.txt
    test2();

    return 0;
}