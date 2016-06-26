#include<stdio.h>
int square(int n){
	if(n==0)
		return 0;
	if(n&1)
		return (square(n>>1)<<2)+1+((n>>1)<<2);
	return (square(n>>1)<<2);
}
int main(){
	int i;
	for(i=0;i<20;i++)
		printf("\nsquare(%d)=%d",i,square(i));
	printf("\n");
	return 0;
}
