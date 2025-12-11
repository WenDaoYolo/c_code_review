#include<stdio.h>

/*
    指针进阶篇
    函数指针数组的使用案例 - 转移表
    实现计算器加减乘除的功能

*/

float add(float a,float b){
    return a+b;
}

float sub(float a,float b){
    return a-b;
}

float div(float a,float b){
    return a/b;
}

float mul(float a,float b){
    return a*b;
}

void Menu(){
    //和转移表函数的下标对应,方便调用
    printf("***************\n");
    printf("**  0.add    **\n");
    printf("**  1.sub    **\n");
    printf("**  2.div    **\n");
    printf("**  3.mul    **\n");
    printf("**  4.exit   **\n");      
    printf("***************\n");
}

void Program(){
    int choose;
    float num1,num2;
    float(*fun_ptr_array[4])(float,float)={add,sub,div,mul};

    do{
        Menu();
        printf("Please input>");
        scanf("%d",&choose);
        if(choose>=0&&choose<=3)
        {
            printf("Please input ab>");
            scanf("%f%f",&num1,&num2);
            printf("\nthe result:%f\n",fun_ptr_array[choose](num1,num2));
        }
        else if(choose!=4)
            printf("Input is error!");
    }while(choose!=4);
}

int main(){
    Program();

    return 0;
}