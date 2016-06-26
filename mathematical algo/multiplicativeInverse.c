/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MODULAR MULTIPLICATIVE INVERSE
*/
#include<stdio.h>
int findModularInverse(int a,int b,int *x,int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int gcd= findModularInverse(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}
int main(){
	int a=3,m=11;
	int x,y;
	int gcd=findModularInverse(a,m,&x,&y);
	if(gcd==1){
		x=(x%m+m)%m;
		printf("\nMultiplicative inverse of %dmod(%d)=%d",a,m,x);
	}else{
		printf("\nNo multiplicative inverse exsits as gcd of %d,%d=%d",a,m,gcd);
	}
	printf("\n");
	return 0;
}
