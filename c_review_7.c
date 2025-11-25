#include<stdio.h>
                               //输入端以回车(\n)结束输入，getchar能够读取\n
void ClearBuffer()             //利用此特性，清理数据缓冲区,让后面能读取正确的数据
{
    while(getchar()!='\n')
    {
        ;
    }
}
    
int main(){
    getchar();

    long long int id=0;        //int整型数最大取值2^31-1=...(默认int为signed)
                               //若存放不下数据则要采用更大的数据类型
    printf("input your id:\n");
    ClearBuffer();

    scanf("%lld",&id);         //清理数据缓冲区后，输入流就能读取到正确的数据
    printf("id:%lld",id);

    return 0;
}