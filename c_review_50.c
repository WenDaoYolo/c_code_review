#include<stdio.h>
/*
    文件进阶篇
    随机读写、数据流函数的补充
*/

struct Stu{
	char name[20];
	char sex[5];
	int age;
};

void test1(){
    char s[20]={0};
	fgets(s,20-1,stdin);
	printf("%s\n",s);
}

void test2(){
    struct Stu stu1={0};
	fscanf(stdin,"%s%s%d",&stu1.name,&stu1.sex,&stu1.age);
	printf("%s,%s,%d\n",stu1.name,stu1.sex,stu1.age);
}

void test3(){
    struct Stu stu1={"zhangsan","male",14};
	fprintf(stdout,"%s-%s-%d\n",stu1.name,stu1.sex,stu1.age);
}

void test4(){
    fputs("this is a test!\n",stdout);
}
////////////////////////////////////////////////////////////////////////////
//补充sscanf,sprintf
struct test{
    char name[10];
    char sex[6];
    int age;
};

void test5(){
    struct test t1={"张三","男",19};
    struct test t2;
    char buffer[20];

    sprintf(buffer,"%s %s %d",t1.name,t1.sex,t1.age);//将数据读取到buffer字符串
                                                     //注意因为是字符串，所以各个参数要使用分隔符
                                                     //(相当于在在终端输入时使用分隔符分隔参数)
                                                     //否则会导致sscanf输出时无法解析
    printf("%s\n",buffer);

    char buffer2[20]={"李四,女,22"};
    sscanf(buffer,"%s%s%d",t2.name,t2.sex,&(t2.age));
    printf("%s %s %d\n",t2.name,t2.sex,t2.age);

    sscanf(buffer2,"%[^,],%[^,],%d",t2.name,t2.sex,&(t2.age));
    printf("%s %s %d\n",t2.name,t2.sex,t2.age);
}
////////////////////////////////////////////////////////////////////////////

void test6(){
    FILE* ptr=fopen("./test50.txt","r");
    if(ptr==NULL)
        perror("fopen:");

    printf("%c ",fgetc(ptr));
    printf("%c ",fgetc(ptr));
    printf("ptr position:%d\n",ftell(ptr));
    rewind(ptr);
    printf("ptr reset:%d\n",ftell(ptr));
    fseek(ptr,-2,SEEK_END);
    printf("ptr end -1(total 21):%d\n",ftell(ptr));
    printf("value:%c\n",fgetc(ptr));
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();

    return 0;
}