#include<math.h>
#include<stdio.h>
int main(){
	int n=20;
	int i;
	for(i=0;i<n;i++)
		printf("\nFor %d required number is %lf",i,pow(2,ceil(log2(i))));
	printf("\n");
	return 0;
}
