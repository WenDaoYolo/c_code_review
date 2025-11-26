#include<stdio.h>
/*
    结构体的嵌套定义和链式访问
*/
struct Base{
    const char* name;
    int age;
    const char* sex;
};

struct Student{
    struct Base Information;
    int sid;
    int uid;
};

void Display(struct Student* s){
    printf("Name:%s,age:%d,Sex:%s,sid:%d,uid:%d\n",
        s->Information.name,s->Information.age,s->Information.sex,
        s->sid,s->uid);
}

int main(){
    struct Student s1={{"张三",22,"男"},0,11};
    Display(&s1);

    return 0;
}

