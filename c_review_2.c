#include<stdio.h>
/*
    原反补的转换
    sizeof();
    三目运算符
    左移右移
    操作符的操作数顺序
*/
int main(){
    /*
        +0与-0其补码是唯一的
    */
    signed int a=0;       //000...000 -> 000...000
    signed int b=-0;      //100...000 -> 111...111+1 -> (1溢出舍弃)000...000
    if((a|1)==(b|1))
        printf("补码相同");
    int c=0;
    printf("%d\n",sizeof(c++));  //编译阶段根据类型推断结果
                                 //然后直接进行替换，不会在执行阶段执行表达式
    printf("c:%d\n",c);

    //(c>d?c:d)=5;               三目运算符返回的是值而非变量，所以其返回值不能作为可修改的左值

    //左移，高位溢出丢弃，低位补0
    signed test=-1;   //两个字节, 补码:11111111 11111111
    printf("before:%d\n",test);
    test=test<<7;     //左移7位后 补码：1111111 10000000 -> 1000000 01111111+1 -> 10000000 10000000 = -128(10)  
    printf("after:%d\n",test);  
    
    //右移分为逻辑右移和算术右移，具体采用哪种取决于编译器
    //逻辑右移 -> 低位溢出丢弃，高位固定补0
    //算术右移 -> 低位溢出丢弃，高位补原符号位
    signed short test2=-10;   //补码：11111111 11110110
    unsigned short test3=10;  //不存在原反补的概念，存储的就是其二进制机器数本身:00000000 00001010
    test2=test2>>4;           //算术：11111111 11111111 =-1 逻辑：00001111 11111111 =2^12+2^13+2^14+1
    
    printf("test2:%d\n",test2);

    test3=test3>>4;           //00000000 00000000
    printf("test3:%d\n",test3);

    //练习1:signed short test4=-29 >>6->算术:10000000 00000001=-1 逻辑:01111110 00000000=...
    signed short test4=-29;
    test4=test4>>6;
    printf("test4:%d\n",test4);

    //练习2:signed short good1=-123 >> 4 
    //     unsigned short good2=123 >> 4

    signed short good1=-123;        //补码：11111111 10000101
    unsigned short good2=123;       //机器数:00000000 01111011
    printf("good1 before:%d\n",good1);
    printf("good2 before:%d\n",good2);

    good1>>=4;                      //算术：11111111 11111000 =10000000 00001000 =-8 逻辑:...
    good2>>=4;                      //逻辑：00000000 00000111 = 7

    int as[5]={1,2,3,4,5};
    as[4]=3;
    4[as]=4;                        //操作数顺序不影响语法，了解即可，建议还是按照常规逻辑coding
    
    printf("good1 after:%d\n",good1);
    printf("good2 after:%d\n",good2);
    
    return 0;
}