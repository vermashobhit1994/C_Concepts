//program to understand how linking is done between the multiple weak symbols
#include<stdio.h>
int a;//weak symbol
int b;//weak symbol
void func();
int main()
{
    
    b = 20;//b is modified in f1.c
    a = 23;
    func();
    printf("in file f1 a = %d, b= %d\n",a,b);//here we get value of a after modfication
    return 0;
}
