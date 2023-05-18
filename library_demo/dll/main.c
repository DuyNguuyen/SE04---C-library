#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

//define function pointer type name math_f
typedef int (*math_f) (int, int);

int main() 
{
	void *handle;
	math_f add, sub, mul, divi;
	
	//Load library
	handle = dlopen ("libmath_dll.so", RTLD_NOW);

	//Search for function by symbol in loaded library
	add = (math_f) dlsym(handle, "add");
	sub = (math_f) dlsym(handle, "sub");
	mul = (math_f) dlsym(handle, "mul");
	divi = (math_f) dlsym(handle, "divi");
 	
 	int x, y;
  	printf("Enter two numbers\n");
	scanf("%d%d",&x,&y);
	 
  	printf("\n%d + %d = %d", x, y, add(x, y));
  	printf("\n%d - %d = %d", x, y, sub(x, y));
  	printf("\n%d * %d = %d", x, y, mul(x, y));

  	if(y==0){
    		printf("\nDenominator is zero so can't perform division\n");
      		exit(0);
  	}else{
      		printf("\n%d / %d = %d\n", x, y, divi(x, y));
	 	return 0;
  	}
	dlclose(handle);
	return 0;
}
