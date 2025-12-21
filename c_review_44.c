#include<stdio.h>
#include<string.h>
/*
    自定义类型进阶篇
    联合体union
*/

union test{
    char a;
    int b;
    short c;
};

void test1(){
    union test s={65};
    printf("%c,%d,%d\n",s.a,s.b,s.c);
}

union ttt{
    int a;
    char b;
};

void test2(){
    union ttt t1={256};   // 联合体大小为4个字节，小端存储：0 256 0 0
    t1.b=4;               // 修改低1个字节的内容，小端存储：4 256 0 0
    printf("%d\n",t1.a);  //0->4 256+4=260
}

void CheckMulBytes(){   
    union ttt test={1};   //1 0 0 0 或 0 0 0 1
    if(test.b==1)         //char整型提升后再进行比较
        printf("当前机器小端字节序\n");
    else
        printf("当前机器大端字节序\n");
}

//***************************************************
enum person_type{                 //对象的类型
	STUDENT,
	TEACHER
};

struct PersonInformaiton_basic{   //相同部分采用结构体
    char name[20];
    char sex[10];
    char address[20];
    enum person_type type;        //用于记录当前对象的类型，防止对象访问错误或未初始化的数据
};

union PersonInformation_unsame{   //不同部分采用联合体，访问时需要根据对象类型再访问
    int student_id;
    char teacher_title[16];
};

void test3(){
    struct PersonInformaiton_basic s1_b={"zhangsan","male","wuhan-xinzhou",STUDENT};
    struct PersonInformaiton_basic t1_b={"lisi","female","wuhan-hongshan",TEACHER};

    union PersonInformation_unsame s1_u,t1_u;
    s1_u.student_id=32306;                //学生对象则使用学生id
    strcpy(t1_u.teacher_title,"advanced");//老师对象则使用老师职位
                                          //另一个成员不需要使用，则会被当前成员覆盖，也不会造成空间的浪费
                                          
    printf("student:%s,%s,%s,%d\n",s1_b.name,s1_b.sex,s1_b.address,s1_u.student_id);
    printf("teacher:%s,%s,%s,%s\n",t1_b.name,t1_b.sex,t1_b.address,t1_u.teacher_title);
}
//***************************************************

union un{
    int b;                            //int 4个字节，对齐数4
	char test[11];                    //char 1个字节，对齐数1
};

int main(){
    test1();
    printf("-------\n");
    test2();
    printf("-------\n");
    CheckMulBytes();
    test3();

    printf("union size:%d\n",sizeof(union un)); //最大成员11,最大对齐数4 -> 联合体最终大小12

    return 0;
}