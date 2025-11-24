/*
    逻辑截断
    
    表达式求值：优先级，结合性，数据类型转换
    隐式类型转换 整型提升与数据截断
    算术转换
*/

#include<stdio.h>

int test=0;

//逻辑截断
void TestForyf(){
    if((1)||(test++))
        ;
    if((0)&&(test++))
        ;
    if(0,0,test++,3)
        printf("逗号表达式取最后一个表达式的值\n");
}

void test2(){
    int i=0;
    i++;
    ++i;
    printf("first:%d\n",i);
    printf("second:%d\n",i++);     //先use,再++
    printf("third:%d\n",++i);      //先++,再use
}

int main(){
    printf("test before: %d\n",test);
    TestForyf();
    printf("test after: %d\n",test);

    ///////////////////////////////////////////////////////////////
    /*
        0.++--的规则针对的是两个操作的顺序(使用和变化) - 与操作符本身的优先级无关
        1.隐式类型转换 - 整型提升与数据截断
        2.寻常算术转换 - 又称向上转型，运算时向精度更高的数据对齐
    */

    signed short t=-3;  //11111111 11111101
    t=t+4;              //整型运算操作，整型提升:11111111 11111111 11111111 11111101+000...000 00000100
                        //结果再进行数据截断:1 00000000 00000000 00000000 00000001=00000000 00000001=1
    printf("t:%d\n",t);
    


    signed short t2=321;  //00000001 01000001                 
    char t3=t2;           //数据截断后：01000001 = 65,再存入t3
    printf("t3:%d\n",t3); //整型操作，以整数的形式输出，则对t3进行整型提升

    int ss=1.1444;        //同理，对1.1444进行截断后再存入ss...
    printf("ss:%d\n",ss);   

    //数据存储决定是否数据截断         
    int p1=3;
    float p2=3.14;
    printf("int plus float value:%d\n",p1+p2);  //p1先转型为float再与p2进行运算
                                                //运算结果没有截断，而是直接以整型的方式输出，float会解析为int,结果是一个很大的整数
                            

    int ttt=100;
    float sss=20.33;
    printf("算术转换:%.2f",ttt+sss);              //向上转型为float，同理没有进行截断
                                                 //但是结果以float格式输出，float解析为float
    return 0;
}