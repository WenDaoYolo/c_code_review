#include<stdio.h>
#include<assert.h>
/*
    函数进阶篇
    模拟实现各类函数
    strtok,strstr
*/

char* my_strstr(const char* str1,const char* str2){
    assert(str1!=NULL);
    assert(str2!=NULL);

    if(*str2=='\0')
        return (char*)str1;

    const char* start=str1;
    const char* end=str1;
    const char* pstr2=str2;

    while(*start++){                     //改进，当剩余字符串小于字串时则无需再查找
        end=start;
        while(*end){
            if(*end!=*pstr2&&*pstr2!='\0')
                break;
            end++;
            pstr2++;
        }

        if(*pstr2=='\0')
            return (char*)start;
    }
    return NULL;
}

//******************************************************MARK
char* my_strtok(char* str,const char* flag){
    assert(str!=NULL);
    assert(flag!=NULL);

    static char* str_tmp=NULL;         //后续再来解决实现，内存地址是动态变化的
                                       //无法用static来记录，函数无法找到第一次内存的地址
    static int position=0;

    char* flag_tmp=flag;

    if(str==NULL)
        str=str_tmp+position;

    while(*str!='\0')
    {
        while(*flag_tmp!='\0')
        {
            if(*flag_tmp==*str)
            {
                *str='\0';
                position++;
            }
            position++;
        }
        str++;
    }
}
//******************************************************MARK

void test1(){
    char str1[20]="jack is a good boy!";
    char str2[10]="girl";
    char str3[10]="good";
    char* position=NULL;

    if(position=my_strstr(str1,str2),position==NULL)
        printf("%s is not child string of %s\n",str2,str1);
    else
    {
        printf("%s is child string of %s\n",str2,str1);
        //指针相减求之间的元素个数，不包含尾元素则刚好对应下标位置
        printf("position int string1:%d\n",position-str1);
    }
    
    if(position=my_strstr(str1,str3),position==NULL)
        printf("%s is not child string of %s\n",str3,str1);
    else
    {
        printf("%s is child string of %s\n",str3,str1);
        printf("position int string1:%d\n",position-str1);
    }
}

int main(){
    test1();

    return 0;
}