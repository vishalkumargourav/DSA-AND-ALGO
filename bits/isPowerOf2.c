#include<stdio.h>
int main(){
	int n,i;
	n=40;
	for(i=0;i<n;i++){
		if(i&&(!((i-1)&i)))
			printf("\n%d is power of 2",i);
		//else
			//printf("\n%d is not power of 2",i);
	}
	return 0;
}
