#include <stdlib.h>
#include <stdio.h>
#include <math_shared.h>

int main() 
{
 	int x, y;
  	printf("Enter two numbers\n");
	scanf("%d%d",&x,&y);
	 
  	printf("\n%d + %d = %d", x, y, add(x, y));
  	printf("\n%d - %d = %d", x, y, sub(x, y));
  	printf("\n%d * %d = %d", x, y, mul(x, y));

  	if(y==0){
    		printf("\nDenominator is zero so can't perform division\n");
      		return 0;
  	}else{
      		printf("\n%d / %d = %d\n", x, y, divi(x, y));
	 	return 0;
  	}
  	
	return 0;
}
