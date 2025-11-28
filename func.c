#include "func.h" //<>表示绝对路径，一般是系统提供的函数库,在某一绝对绝对路径下
                  //""表示相对路径，一般是用户自定义的函数库,当前文件夹下的func.h头文件，与之进行绑定

//头文件的函数库源文件，用于实现头文件中声明的函数  
//函数的声明和实现是分开的，这样工程结构更加清晰，维护性强，开发效率高

void Produce(){
    printf("这是一个自定义函数库的函数!\n");
}
void Add(int a,int b){
    printf("a+b:%d\n",a+b);
}
void Sub(int a,int b){
    printf("a-b:%d\n",a-b);
}
