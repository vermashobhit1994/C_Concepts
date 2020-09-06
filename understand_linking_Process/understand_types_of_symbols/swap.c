//file that swap the two values of global array taken from main.c
extern int buff[];//external symbol
//pointer to hold the address of global array
int *buffp0 = &buff[0];//global symbol to hold the first element of global array.
static int *buffp1 ;//local symbol to hold the second element of global array.
void swap()//global symbol
{
    int temp;//automatic variable
    buffp1 = &buff[0];
    temp = *buffp0;
    *buffp0 = *buffp1;
    *buffp1 = temp;
}
