//main.c 
//  program to count blanks, tabs, and newlines.
#include <stdio.h>
enum chois {TAB='\t', BLA=' ', NEW='\n'};

int main(void){
	int c , nTab , nBLA , nNEW  ;
	printf("Entre Text For Exit Tabe CLRE + D\n");
	while((c=getchar())!=EOF){
		if(c == NEW ){
        ++nNEW;
		}else if(c == TAB ){
        ++nTab;
		}else if(c == TAB || c == BLA || c ==NEW ){
          ++nBLA;
		}
	}
    printf("Blanks : %d  TABS : %d NEWLines : %d\n",nBLA,nTab,nNEW );
	return 0;
}