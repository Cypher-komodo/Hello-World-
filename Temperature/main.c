//Modify the temperature conversion program to print a heading above the table.
#include <stdio.h>
#define Cels(F)  5*((F) - 32)/9
//the formula oC=(5/9)(oF-32) 
int main(void){
	int F = 0;
	int Celsuis =Cels(F);
	// Print the heading for the table
	printf("Fahrenheit to Celsius Conversion Table\n");
	printf("Fahr : %6.2d   Celsuis : %6.2d\n", F , Celsuis);
   printf("---------------------------------------------------------------\n");
   while(F <= 300){
   	Celsuis = Cels(F);
    printf("|   Fahr : %3d       |      Celsuis : %3d     |\n", F , Celsuis);
   	F +=20;
   }
   printf("---------------------------------------------------------------\n");
	return 0;
}