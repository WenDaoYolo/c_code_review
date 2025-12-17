#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<assert.h>
/*
    函数进阶篇
    模拟实现各类函数
    内存函数
    memset,memcpy,memcmp,memmove
*/

void test1(){
    char sa[4]={'a','b','c','d'};
    printf("%c,%c,%c,%c\n",sa[0],sa[1],sa[2],sa[3]);
    memset(sa,'6',2);
    printf("%c,%c,%c,%c\n",sa[0],sa[1],sa[2],sa[3]);

    //多字节数据涉及到字节序 小端字节序:2-256-0-0 2-0-0-0 3-0-0-0 4-0-0-0
    int ia[4]={258,2,3,4};
    printf("%d,%d,%d,%d\n",ia[0],ia[1],ia[2],ia[3]);

    memset(ia,0,1);
    printf("%d,%d,%d,%d\n",ia[0],ia[1],ia[2],ia[3]);

    memset(ia,0,2);
    printf("%d,%d,%d,%d\n",ia[0],ia[1],ia[2],ia[3]);
}

void test2(){
    int ia1[4]={512,2,3,4};     //小端：0-512-0-0 2-0-0-0 3-0-0-0 4-0-0-0
    int ia2[4]={0,2,3,4};       //小端：0-0-0-0 2-0-0-0 3-0-0-0 4-0-0-0

    if(memcmp(ia1,ia2,1)==0)
        printf("1 bytes:ia1==ia2\n");

    if(memcmp(ia1,ia2,2)>0);
        printf("2 bytes:ia1>ia2\n");
}

void test3(){
    char a[5]={'w','a','s','d','p'};
    memcpy(a,"1234",4);
    printf("%c,%c,%c,%c,%c\n",a[0],a[1],a[2],a[3],a[4]);

    //memcpy无法完成有内存重叠的数据拷贝
    char s[5]={'1','2','3','4','5'};

    //s的1234拷贝到s-1的2345
    //从前向后的拷贝顺序，需要进行拷贝的源数据被修改则无法完成拷贝
    //1 2 3 4 5 -> 1 1 2 3 4 -> 1 1 1 3 4 ->... -> 1 1 1 1 1->编译器可能会优化
    memcpy(s+1,s,4);
    
    printf("%c,%c,%c,%c,%c\n",s[0],s[1],s[2],s[3],s[4]);
}

void test4(){
    char s[5]={'1','2','3','4','5'};

    //memmove可以拷贝内存重叠的数据
    memmove(s+1,s,4);           

    printf("%c,%c,%c,%c,%c\n",s[0],s[1],s[2],s[3],s[4]);
}

void* my_memcpy(void* destination,const void* source,int n){
    assert(destination!=NULL);
    assert(source!=NULL);
    int i=0;

    while(i<n){
        *((char*)destination+i)=*((char*)source+i);
        i++;
    }
    return destination;
}

void* my_memmove(void* destination,const void* source,int n){
    assert(destination!=NULL);
    assert(source!=NULL);

    if((char*)source<(char*)destination)
    {
        n--;
        while(n>=0){
            *((char*)destination+n)=*((char*)source+n);
            n--;
        }
    }
    else
    {
        int i=0;
        while(i<n)
        {
            *((char*)destination+i)=*((char*)source+i);
            i++;
        }
    }

    return destination;
}

void test5(){
    char a[5]={'w','a','s','d','p'};
    my_memcpy(a,"99",2);
    printf("%c,%c,%c,%c,%c\n",a[0],a[1],a[2],a[3],a[4]);

    char s[5]={'1','2','3','4','5'};
    my_memcpy(s+1,s,4);             //全1，自己编写的函数编译器不会优化逻辑
    printf("%c,%c,%c,%c,%c\n",s[0],s[1],s[2],s[3],s[4]);
}

void test6(){
    char a[5]={'w','a','s','d','p'};
    my_memmove(a,"666",3);
    printf("%c,%c,%c,%c,%c\n",a[0],a[1],a[2],a[3],a[4]);

    char s[5]={'1','2','3','4','5'};
    my_memmove(s+1,s,4);
    printf("%c,%c,%c,%c,%c\n",s[0],s[1],s[2],s[3],s[4]);
}

int main(){
    test1();
    test2();
    printf("-------------\n");
    test3();
    printf("-------------\n");
    test4();
    printf("-------------\n");
    printf("-------------\n");
    test5();
    printf("-------------\n");
    printf("-------------\n");
    test6();

    return 0;
}