//Program to understand rule that between the strong symbol and multiple weak symbol the strong symbol is allowed
#include<stdio.h>
int func();
int a = 10;
int b = 20;
int main()
{
    func();//function call in file f2.c 
    printf("In f1 file a = %d\n",a);//a gets modified and we get garbage value
    printf("In f1 file b = %d\n",b);
    return 0;
}
 
