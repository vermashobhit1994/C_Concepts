Q1. Why we use storage Class?
It is used to find out the visibility/scope, lifetime of variable/function to trace that variable/function during runtime of program.

Visibility/scope : Part of program in which variable name can be used. There are four types of Scope :
1. Function - Only label is having function scope. This label name must be unique within function. 

2. File - Variable declared outside the block and can be access by anyone within file. Here variable called as external/global.
The scope of a global variable begins at the point of its definition or declaration and terminates at the end of the file.

3. Block - Here the variable declared inside the function block or in list of formal parameters in function definition. Scope is limited to block and 
nested block(if any). These are generally name as local variables.

4. Function Prototype - Variable declared in parameter in function prototype. Here the variables parameters list musn't contain in the Function declaration.
Scope terminates at end of fuction declaration.

Lifetime : Part of program where the memory is allocated to variable and destroyed .


Q2. What are different storage classes in C?

Storage class          Storage            Initial Value        Scope                      Lifetime
auto                   Stack              Garbage              Within function/Block      Within Function/block
register               CPU Register       Garbage              Within Function/block      Within Function/Block
static - local         data section       0                    Within file                Till Program 
       - Global        data section       0                    Within File                till Program 
extern                 data section       0                    throughout program         throughout program.


Note1: Here in data section comes (initialized(.data) and uninitialized(.bss) section). Here if variable are local static , global , global static uninit
then goes to bss section. If init then goes to .data section.(See global_var.jpg)

Note2 : There can be multiple declarations of same global variable but there is only one definition.(See Case VII)

Note3 : The initializer element for static variable(local or global) must be literal constants(Numbers(decimal, binary,float,hexadecimal), characters,
        enum, result of sizeof operator).
        Check Case X 
        
Note4 : array of local register variables is possible.

Note5 : const structure member must be initialized at time of creation of structure variable creation. See Case XII 

Note6: function definition as well as function declaration can be done inside another function.

Q3. What is difference between function prototype and function declaration?
Ans Declaration : Tells the function return type and function name.
    Prototype : Tells the function return type, function name and its arguments type and number.
    Check Case VIII 


Q3. Why we can't access global variable declared with static storage class inside a block using extern if variable with same name exists in local block 
as well?
Ans check case I 

Q4. Why can't we take the address of register variable?
Ans Since register are stored inside CPU so, no address for register 
since it's not a memory location whose address can be taken.
See register_address_error.jpg

Q5. Why register storage class can't be used as function defintion return type but can be used as function parameter type in function prototype?
Ans If use auto storage class as function return type in function definition then gives warning as below picture.
    Check auto_func_warning.jpg. 
    
    If use register storage class as function return type in function definition then gives error as below picture.
    check register_func_warning.jpg
    Also if use typedef as function return type in function definition then gives error as below picture.
    typedef_func_error.jpg
    
    But since initially the actual arguments are stored on registers after that it goes to stack so, register storage class is allowed as function 
    formal parameters return type as well as function prototype arguments return type. Other than register no storage class i.e auto, static, extern,
    typedef are allowed.
    Check Case IX
     


Q6. How compiler resolves the static global and static local variables with same name?
Ans Here the local static variables are changed to variablename.number. See global_var.jpg and Case V

Q7. How extern is used ?
Ans See extern_use.c



Q8. How to initialize the global variable multiple times outside all the functions?
Ans Can't do that.

Q9. Why C allows multiple global declarations with same name but not multiple local declarations with same name?
Ans Check Case VII

    C mainly has three types of global declarations:
    1. Declarations that aren't definitions: extern int x;
    2. Declarations that are also definitions : int a = 3; extern int a = 56;
    3. Tentative definitions : int a;
    
    Multiple declarations of type 1 and 3 are allowed but atmost type2 is allowed.
    For using same global variable and functions in multiple files C provides the linkage but for local variables there is no linkage so, there is name collision problem.
    
Q10. Why structure member can't be declared with extern, static, register,auto, typedef storage class?
Ans Below is error image if use auto structure member:
    structure_member_error.jpg
    
    since in strucuture variable resides in contiguous memory allocation so, no storage class can be used.
    
    Only extern and static storage class are allowed with structure declaration. below is error if use register , auto storage class.
    check auto_error.jpg, register_error.jpg
    
    but since whole structure can be static or extern
    Also, we can have whole structure as constant also.(check structure)
    
Q11. Why extern with initialization of element is allowed for global variable but not for local variable ?
Ans Check Case XIV

******* check Case XIII also check const_var.jpg
1. auto const variables stored in stack section and using pointers we can modify them. 
2. uninit global const can be modified via pointer since stored in .bss section but uninit static global const  or uninit static local const can't be modified since stored in  .rodata section. If try to change then segmentation fault.

3. Initialized global const or static global const or static local const variable can't be modified via pointer since stored in .rodata section.

4. String literal also stored in .rodata section but pointer pointing to is stored in stack. 
check string.jpg
    
 

