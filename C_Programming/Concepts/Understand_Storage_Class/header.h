#include<stdio.h>
int extern_func(void);

//acts as weak symbol. If initialized then only cause "redefinition error".
extern int var_global_uninit ;
int var_global_init ;
/*** enum declaration ***/
enum day
{
	MON,
	TUE,
	WED,
	THR,
	FRI,
	SAT,
	SUN
};
