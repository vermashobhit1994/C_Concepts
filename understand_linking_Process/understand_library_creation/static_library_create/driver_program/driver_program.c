//driver program that uses the libarithmath.a library
#include<stdio.h>
#include"mymath.h"
int main()
{
    double a,b;
    printf("Enter the two numbers: \n");
    scanf("%lf%lf",&a,&b);
    printf("%3.2lf + %3.2lf = %7.2lf\n",a,b,myadd(a,b));
    printf("%3.2lf - %3.2lf = %7.2lf\n",a,b,mysub(a,b));
    printf("%3.2lf * %3.2lf = %7.2lf\n",a,b,mymul(a,b));
    printf("%3.2lf / %3.2lf = %7.2lf\n",a,b,mydiv(a,b));
}