// main.c 
 /********************************************************************
  *  Verification the expression getchar() != EOF is 0 or 1.   *
  * ******************************************************************/
#include <stdio.h>

int main(){
	printf("Verification the expression getchar() != EOF is 0 or 1.\n" );
	printf("---------------------------------------------------------------------------\n");
	printf("the expression (getchar() != EOF) = %d \n",(getchar() != EOF) );
	printf("---------------------------------------------------------------------------\n");
	printf("the value of EOF  = %d .\n",EOF);
	return 0;
}