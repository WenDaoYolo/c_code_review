#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    进阶篇函数
    qsort的使用
    模拟实现qsort
*/

struct stu{
    int age;
    char sex[5];
    char name[15];
};

//****使用者提供的元素比较方法****

//按名字升序排序
int CmpByname_up(const void* e1,const void* e2){
    return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}

//按名字降序排序
int CmpByname_down(const void* e1,const void* e2){
    return -strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}

//按年龄升序排序
int CmpByage_up(const void* e1,const void* e2){
    return  ((struct stu*)e1)->age-((struct stu*)e2)->age;
}

//按年龄降序排序
int CmpByage_down(const void* e1,const void* e2){
    return  -(((struct stu*)e1)->age-((struct stu*)e2)->age);
}

//...


void DisplayArray(struct stu arr[],int length){
    for(int i=0;i<length;i++)
    printf("%d:%s,%s,%d\n",i,arr[i].name,arr[i].sex,arr[i].age);
    putchar('\n');
}

void test1(){
    struct stu stuarr[3]={{14,"男","zhangsan"},{11,"女","lisi"},{19,"男","wangwu"}};
    int stu_length=sizeof(stuarr)/sizeof(struct stu);

    printf("before:\n");
    DisplayArray(stuarr,stu_length);

    //qsort(要操作内存的地址,元素的个数,元素的大小,元素的比较方法)
    qsort(stuarr,stu_length,sizeof(struct stu),CmpByage_up);

    printf("after:\n");
    DisplayArray(stuarr,stu_length);
}

//****模拟实现qsort函数****
void my_swap(void* e1,void* e2,int width){      //这里的类型是确定的，可以直接使用char*
    char* tmp;
    for(int i=0;i<width;i++)                  
    {
        *tmp=*((char*)e1+i);
        *((char*)e1+i)=*((char*)e2+i);
        *((char*)e2+i)=*tmp;
    }
}

void my_qsort(void* base,int num_t,int size_t,int(*cmp_fun_ptr)(const void*,const void*)){
    char* ptr=(char*)base;
    for(int s=0;s<num_t-1;s++){
        for(int i=0;i<num_t-s-1;i++){
            if(cmp_fun_ptr(((char*)base+i*size_t),((char*)base+(i+1)*size_t))>0)
                my_swap(((char*)base+i*size_t),((char*)base+(i+1)*size_t),size_t);
        }
    }
}

void test2(){
    struct stu stuarr[3]={{14,"男","zhangsan"},{11,"女","lisi"},{19,"男","wangwu"}};
    int stu_length=sizeof(stuarr)/sizeof(struct stu);

    printf("before:\n");
    DisplayArray(stuarr,stu_length);

    //my_qsort(要操作内存的地址,元素的个数,元素的大小,元素的比较方法)
    my_qsort(stuarr,stu_length,sizeof(struct stu),CmpByage_down);

    printf("after:\n");
    DisplayArray(stuarr,stu_length);
}

int main(){
    test1();
    printf("--------------\n");
    test2();

    return 0;
}