/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	EUCLID ALGO WHEN / AND % IS COSTLY
*/
#include<stdio.h>
int gcd(int a,int b){
	if(b==0||a==b)
		return a;
	if(a==0)
		return b;
	if((a&1==0)&&(b&1==0))
		return gcd(a>>1,b>>1)<<1;
	if(a&1==0)
		return gcd(a>>1,b);
	if(b&1==0)
		return gcd(a,b>>1);
	return a>b?gcd(a-b,b):gcd(a,b-a);
}
int main(){
	int a,b;
	a=30;
	b=225;
	printf("\nGCD(%d,%d)=%d",a,b,gcd(a,b));
	printf("\n");
	return 0;
}
