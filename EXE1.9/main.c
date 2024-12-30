#include <stdio.h>

int main (){
	int c ;
	int  lastWasBlank = 0;
	int in_word = 0; int word_count = 0;
    printf("Enter text (Press Ctrl+D to end input):\n");
	while ((c=getchar())!=EOF){
         if (c == ' ' || c == '\t'  || c=='\n'){
         	if(!lastWasBlank){
         		putchar('\n');// End the current word and start a new line 
         		//putchar(c); // Print the character
         		lastWasBlank=1;
         		 if (in_word){
         		  in_word = 0;// End of a word
         		   word_count++;  // Increment word count
         		}
         	}
         }else{
         	 in_word = 1; // Inside a word
         	lastWasBlank = 0; 
         	putchar(c);  // Print the character
         }
	}
	// If the last character was part of a word, count the last word
	// if (in_word) { word_count++; } 
	 printf("Word count: %d\n",word_count);
}
