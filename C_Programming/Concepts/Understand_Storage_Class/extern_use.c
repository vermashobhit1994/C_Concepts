//file that uses the extern keyword to understand extern storage class

#include"header.h"

int global_var_init = 45;


int extern_func()
{

	var_global_init = 400;
	printf("inside extern_func var_global_init = %d\n",var_global_init);
	return var_global_init;
}
