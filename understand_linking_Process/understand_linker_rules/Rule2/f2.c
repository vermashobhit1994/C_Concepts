//Program to understand rule that between the strong symbol and multiple weak symbol strong symbol  is allowed
#include<stdio.h>
float a ; //weak symbol
int func()//stron symbol
{
    a = 10.45;
    printf("in file f2 a = %f\n",a);
    return 0;
}
