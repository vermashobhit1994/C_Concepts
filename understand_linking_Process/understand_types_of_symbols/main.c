//main.c file that used the swap.c and then swap the two values in global array
#include<stdio.h>

//swap function declaration
void swap();//external symbol

//global array
int buff[2] = {1,2};


int main()
{
    swap();
    printf("After swapping values are\n");
    printf("buff[0] = %d, buff[1] = %d\n",buff[0],buff[1]);
    return 0;
}