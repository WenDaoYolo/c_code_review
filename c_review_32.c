#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    进阶篇函数
    模拟实现各类函数
*/

void test1(){
    const char* str=" 999999999";           //字符串过长结果则会出错
    int value=atoi(str);
    printf("value:%d\n",value);
}

//***atoi函数的模拟 递归方式***

//必须使用全局的变量来记录权重，局部变量在每次函数调用结束后自动销毁，无法记录总体的权重
int pow_count=0;

//求整数的幂次方,使用long long以防结果存不下，后面使用long long 同理
long long int_pow(int x,int y){
    long long value=x;
    for(int i=0;i<y-1;i++)
        value*=x;
    return value;
}

//递归求值
long long read_i(const char* str_tmp){

    //遇到\n或者非数字字符则停止读取
    if(*(str_tmp+1)=='\n'||*(str_tmp+1)<48||*(str_tmp+1)>57)
        return *(str_tmp)-'0';  //将字符串转为整数
    else
    {
        long long value=read_i(str_tmp+1);
        pow_count++;
        return ((*str_tmp)-'0')*int_pow(10,pow_count)+value;
    }
}   

//函数主体
int my_atoi(const char* str){
    long long value=0;
    int flag=1;
    const char* str_tmp=str;

    //判断是否为空
    if(str_tmp==NULL||*str_tmp=='\n'){
        printf("NULL!\n");
        return value;
    }

    //跳过空白部分
    while(*str_tmp==' ')
        str_tmp++;

    //若有符号，判断正负号然后跳过，后续改进:处理连续多个正负号
    if(*str_tmp=='+')
    {
        str_tmp++;
        flag=1;
    }
    else if(*str_tmp=='-')
    {
        str_tmp++;
        flag=-1;
    }

    //0 - 9 ascll码 48 - 57 ,排除非数字字符
    if((*str_tmp<48||*str_tmp>57)&&(*str_tmp!='+'&&*str_tmp!='-'))
    {
        printf("string disable!\n");
        return value;
    }

    value=flag*read_i(str_tmp);

    //判断值是否超出int的范围，定义long long类型的value来接受
    //INT_MIN,INT_MAX,系统定义的常量标识符，表示int的最大和最小值
    if(value<INT_MIN||value>INT_MAX)
    {
        printf("the num is to large or small!\n");
        return 0;
    }

    return (int)value;
}

//测试
void test2(){
    const char* str="   -123456789w.adw432";
    int value=my_atoi(str);
    printf("my value:%d\n",value);
}

int main(){
    test1();
    test2();

    return 0;
}