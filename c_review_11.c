#include<stdio.h>
#include<string.h>
/*
    结构体篇
*/

struct Student{
    int id;
    char name[10];
    int age;
}s1,s2;

void InitStruct(){
    s1.age=20;
    s1.id=0;
    strcpy(s1.name,"张三");

    s2.age=22;
    s2.id=1;
    strcpy(s2.name,"李四");
}

void Display(struct Student* stu){
    printf("name:%s,age:%d,id:%d\n",stu->name,stu->age,stu->id);
}

void test(){
    InitStruct();
    Display(&s1);
    Display(&s2);

    struct Student s3={2,"王五",24};
    struct Student* ps3=&s3;
    printf("name:%s\n",s3.name);
    printf("age:%d\n",ps3->age);
    printf("id:%d\n",(*ps3).id);
}

int main(){
    test();

    return 0;
}