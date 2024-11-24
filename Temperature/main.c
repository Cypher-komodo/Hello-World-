//Modify the temperature conversion program to print a heading above the table.
#include <stdio.h>
#define Cels(F)  5*((F) - 32)/9
//the formula oC=(5/9)(oF-32) 
int main(void){
	int F , F_ , FT;
	F =0;
	int Celsuis =Cels(F);
	// Print the heading for the table
	printf("Fahrenheit to Celsius Conversion Table\n");
   printf("---------------------------------------------------------------\n");
   while(F <= 300){
   	Celsuis = Cels(F);
    printf("|   Fahr : %3d       |      Celsuis : %3d     |\n", F , Celsuis);
   	F +=20;
   }
   printf("---------------------------------------------------------------\n");
   printf("Write a program to print the corresponding Celsius to Fahrenheit table. \n");
    printf("---------------------------------------------------------------\n");
    F_ = 0;
   while(F_ <= 100){
   	Celsuis = Cels(F_);
    printf("|   Fahr : %3d       |      Celsuis : %3d     |\n", F_ , Celsuis);
   	F_ +=10;
   }
   printf("---------------------------------------------------------------\n");	
//the temperature conversion 
printf(" the temperature conversion  \n");
printf("---------------------------------------------------------------\n");
FT =300;
   while(FT >= 0){
   	Celsuis = Cels(FT);
    printf("|   Fahr : %3d       |      Celsuis : %3d     |\n", FT , Celsuis);
   	FT -=20;
   }
   printf("---------------------------------------------------------------\n");
	return 0;
}