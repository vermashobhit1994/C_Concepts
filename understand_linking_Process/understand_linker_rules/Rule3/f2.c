//program to understand how linking is done between the multiple weak symbols
#include<stdio.h>
int a;//weak symbol
int b;//weak symbol
int func()
{
    a  = 45;//a is modified in f2.c
    b = 78;
    printf("in file f2 a = %d,b = %d\n",a,b);
    a = 100;//a is modified again
    return 0;
}
