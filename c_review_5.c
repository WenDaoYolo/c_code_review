#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>

void test1(){
    float a=9.09;
    float b=sqrt(a);
    float c=pow(b,2);
    printf("b:%.4f,c:%.4f\n",b,c);
}

void test2(){
    system("shutdown -s -t 30");
    Sleep(500);
    system("shutdown -a");
}

void test3(){
    time_t t=time(NULL);
    printf("system time stamp:%d->%d(now-1970)\n",t,t/60/60/24/365);

    printf("before:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++)
            printf("%d ",rand()%100);
        putchar('\n');
    }

    srand(t);

    printf("after:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++)
            printf("%d ",rand()%100);
        putchar('\n');
    }
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}


