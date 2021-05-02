
//Program to understand how to call function before main function and after main function.
//Also difference between _exit() and exit()
//How exit is different from atexit()

#include<stdio.h>

#include<unistd.h>//for _exit()
#include<stdlib.h>//for atexit(), exit()

__attribute__( (constructor))  void before_main_func (void) 
{
    printf("Function called before main\n");
}


//function called after main function exits
__attribute__( (destructor)) void after_main_func(void) 
{
    printf("Function called after main \n");
}


void exit_func(void)
{
    printf("Function called at exit\n");
}

void exit_func_new(void)
{
    printf("Function new called at exit\n"); 
}


int main()
{
    printf("main function called\n");
    
    /* Here the function called in reverse order of their registration*/
    atexit(exit_func);
    atexit(exit_func_new);
    
    
    /* Difference between _exit and exit function */
    int status = 0;
    
    //used for abrupt exit or program without calling the other functions
    //Here exit_func, exit_func_new, after_main_func none gets called
    //_exit(status); 
    
    //used for normal exit of program  
    exit(status);
    
    
    
    
    
    
}
