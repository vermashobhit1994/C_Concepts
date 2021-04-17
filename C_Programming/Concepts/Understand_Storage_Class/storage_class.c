//Program to understand different storage classes in c
#include"header.h"


/* Here the scope is block scope so, give File-scope declaration error 
auto int global_var_auto_init = 10;
auto int global_var_auto_uninit ;
 
register int global_var_register_init = 20;
register int global_var_register_uninit;
*/

//Case XI
//register int global_var_arr[78];


/******* global static variables ************************/
int initval = 1236;
//Case X:
static int global_var_static_init = 1236;//goes to .data section
/* 
 * static int global_var_static_init = initval;
 *  Initializer element must be constant literal.
 */
static int global_var_static_uninit;//goes to .bss section

/****** Case V: global static variable with same name as local static variable ******/
static int var_static_init =4565;
//Case VII :Multiple declarations of same global static variable
static int var_static_uninit;
static int var_static_uninit;

/****** global variables ********/
//int var_global_init=520;//goes to .data section
/******* Case VII: Multiple declarations of same global variable****/
int var_global_uninit;//goes to .bss section
int var_global_uninit;
int var_global_uninit;


//Function prototyping 
//register int func(int y); //Can't have return type as register
//auto int func(int y);//can't have return type as auto in function 
static int func(register int y);
extern int func( int x);

/**** Case VIII:Function prototype vs function declaration**/
int func();//function declaration
int func(int);//function prototype


//Case IX:auto int func(auto int x) //-> can't have auto, extern,static, typedef as function formal paramters return type
//typedef int func(int x)
int func(int x)
{
    printf("IN function\n");
//    test_func_local();//couldn't able to call it from here since define in main() locally and causes the linker error since no definition.
    return x;
}

//auto struct test
//register struct test
static const struct test
{
	int x;
	//auto int r;
        //static int y;
	//register int z;
	//extern int s;
	//typedef int i;
	int q;
	const int c;
	//extern int m;
}t = {.x=23,.q = 56,.c = 565};//Designated Initialization
//Case XII: In above the constant variable i.e c is initialized as soon as structure member is declared. 


//Case XIII
static const int global_var_static_const_init = 45678;
static const int global_var_static_const_uninit ;
const int global_var_const_init = 1269;
const int global_var_const_uninit ;

int *global_ptr = NULL;

//Case XIV
//Here the extern with initializer in global variable is allowed.
extern int const extern_var_init = 589;


//Case IV: Can't use the register storage class return type in function definition
//Can only use static ,extern ,auto storage class only.
//for auto storage class warning "function definition declared ‘auto’"
#if defined ERROR
register int func(register int x)
#endif
//Case V: Only register storage class can be specified inside the function formal parameters. No auto, extern, static, typedef storage class can be used.
//If used then Error:"storage class specified for parameter ‘y’" 
auto int test_func( int y)
{
    printf("in global scope of test_func\n");
    return y;
}


int main(void)
{
    /*typedef is considered as storage class but only syntactically so, error of multiple storage class
    typedef static int x;
    */

    auto int local_var_auto_init = 100;
    auto int local_var_auto_uinit ;
    register int local_var_register_uinit;
    register int local_var_register_init = 200;

    //Case XI
    register int local_var_arr[45];
    local_var_arr[0] = 78;
    //printf("Address of local_var_arr[0] = %d\n",&local_var_arr[0]);
    

    /****** Case V: local static variable with same name as global static variable*/
    static int var_static_init = 203;//goes to .data section as mention in symbol table
    static int var_static_uninit ;
    /*** Case VII: ***/
   // int var_local_uninit ;
    //int var_local_uninit;
    
    

    printf("Before extern var_static_uninit = %d\n",var_static_uninit);
    
    {
    /* Case I:
     * If declare the global static variables then can't access it via extern keyword
     * since the scope is limited to that file only.
    extern int var_static_init;
    extern int var_static_uninit;
    */

//    extern int var_global_init;//for global variables it would work.
    printf("var_static_init = %d, var_static_uinit = %d\n",var_static_init , var_static_uninit);
    }
    /*Case II:
    printf("address of local_var_register_init = %p\n",&local_var_register_init);
    */ 


    
    struct test t1 = {20,82,245};
    t1.x = 45;
    //t1.c = 23;-> can't able the change the readonly variable c
    //t.x = 108;-> can't able the assign value to readonly struct variable
    printf("struct test t1 values , x = %d, q = %d, c = %d\n",t1.x,t1.q,t1.c);
    printf("struct test t values , x = %d, q = %d, c = %d\n",t.x,t.q,t.c);   
    

    printf("Function return value = %d\n",func(456) );

    //Putting the braces prevent calling of local test_func
    {
    /* Case III: Declaring a function defination inside another function */
    auto int test_func(int y)
    {
        printf("in test function\n");
        return y;	
    }

    auto void test_func_local()
    {
	    printf("inside test func local\n");
    }

    
    printf("Test Function Return value = %d\n",test_func(256) );
    }
    

    printf("Global Test Function return value = %d\n",test_func(2056));

    //Case VI:extern use

    int retval = 0;
   retval = extern_func();
    printf("Return val from extern_func = %d\n",retval);
    printf("After calling var_global_init = %d\n",var_global_init);

    //Access the local variable with same name as global varibale


    extern int var_global_init;//to access global variable
    {
    int var_global_init = 800;
    printf("local var with same name as global var = %d\n",var_global_init);
    }
    printf("global variable = %d\n",var_global_init);
    var_global_uninit = 52;
    printf("global variable uninit = %d\n",var_global_uninit);
    
     //Case XIV
    //Here the extern with initializer in local variable isn't allowed. 
    //extern int extern_var_init = 589;
    
    //Case XIII
    auto const int local_var_const = 89;
    int *ptr_local_var = (int*) &local_var_const;//typecast to int* to avoid warning "assignment discards ‘const’ qualifier from pointer target type"
    printf("before modification local_var_const = %d, ptr_local_var = %d\n",local_var_const,*ptr_local_var);
    *ptr_local_var = 123;
    printf("After modification local_var_const = %d, ptr_local_var = %d\n",local_var_const, *ptr_local_var);
    
    global_ptr = (int*)&global_var_static_const_uninit;//typecast to int* to avoid warning "assignment discards ‘const’ qualifier from pointer target type"
   // *global_ptr = 89523;//segmentation fault
    
    
    global_ptr = (int*)&global_var_const_uninit;//typecast to int* to avoid warning "assignment discards ‘const’ qualifier from pointer target type"
    *global_ptr = 589;
    printf("global var after modification = %d, %d \n",global_var_const_uninit, *global_ptr);
    
    static int const local_const_var_init = 782;
    static int const local_const_var_uninit ;
    
   
    //changing the local initialized and uninitialized static const variable.
    ptr_local_var = (int*)&local_const_var_uninit ;//typecast to int* to avoid warning "assignment discards ‘const’ qualifier from pointer target type"
    //*ptr_local_var = 1230;//segmentation fault
    //ptr_local_var = (static int*)&local_const_var_init;//can't typecast to static int
    ptr_local_var = &local_const_var_init;
    //*ptr_local_var = 1235;
    
    ptr_local_var = &global_var_const_init;
    //*ptr_local_var = 1235;
    
    ptr_local_var = &global_var_static_const_init;
    //*ptr_local_var = 1235;
    
    char *ptr = "hello world";
    
    
    

}













