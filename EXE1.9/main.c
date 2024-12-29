#include <stdio.h>

int main (){
	int c ;
	int  lastWasBlank = 0;
	while ((c=getchar())!=EOF){
         if (c == ' ' || c == '\t'){
         	if(!lastWasBlank){
         		putchar(c);
         		lastWasBlank=1;
         	}
         }else{
         	lastWasBlank = 0;
         	putchar(c);
         }
	}
}