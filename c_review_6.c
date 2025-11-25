#include<stdio.h>            //standard input output header

int main(){
                             //putchar(getchar());
                             //char test=getchar();
                             //缓冲区、内存与外存;读输入内存与写输出外存
    char s;
    while((s=getchar())!=EOF)//EOF(End Of File),通过定义可以发现，是系统定义的一个常量标识符，其值为-1
    {                        //是文件流的结束的标志，输入流读取到该标识符时停止读取 (stream流的概念详见进阶篇)
        putchar(s);          //键盘上通过ctrl+z组合键输入,注意数据缓冲区中
                             //该组合前面不能有任何的其他数据,否则输入流无法读取
    }                        //其他输入函数例如，scanf等同理
                             //他们都具有阻塞性，若缓冲区没有数据则会阻塞程序，等待用户输入后再
                             //读取数据，并唤醒程序继续运行
                             //回车用于结束输入端的输入，空格，tab是默认的数据分隔读取方式
                             //也可以自定义数据的读取方式或格式
    putchar('\n');
                               
    const char* str;         //constant
    scanf("%s",str);         //a string of char
    int a1,a2,b1,b2;         //integer

    puts(str);               //put a string of char

    scanf("%d%d",&a1,&a2);   //scan format
    scanf("%d-%d",&b1,&b2);

    printf("%d,%d\n",a1,a2); //print format
    printf("%d,%d\n",b1,b2);

    return 0;
}