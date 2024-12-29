#include <stdio.h>
enum COUNT{blanks = ' ', tab = '\t', newline = '\n'};
int main (){
	int statu = 0;
	int  onca =0;
	int  c , nc ,nw, nl ;
	nc = nw = nl = 0;
	printf("press CTRL + D to Exit \n");
	while((c =getchar()) != EOF ){	
	++nc ;
	if (c == blanks){
		++nw;
	}else if (c==newline){
		++nl;
	}
	}
   printf("nc : %d nw : %d nl : %d\n",nc ,nw ,nl  );

	return statu;
}