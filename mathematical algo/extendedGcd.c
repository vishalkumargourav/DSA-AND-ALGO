/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT EXTENDED EUCLIDEAN ALGORITHM
*/
#include<stdio.h>
int extended(int a,int b,int *x,int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int gcd=extended(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}
int main(){
	int a=35,b=15,x,y;
	if(a>b){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	int gcd=extended(a,b,&x,&y);
	printf("\nGCD(%d,%d)=%d, and x=%d and y=%d",a,b,gcd,x,y);
	printf("\n");
	return 0;
}
