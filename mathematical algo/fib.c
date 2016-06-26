/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT Nth FIBONACCI NUMBER
*/
#include<stdio.h>
int multiply(int a[2][2],int b[2][2]){
	int t1=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int t2=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int t3=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int t4=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	a[0][0]=t1;
	a[0][1]=t2;
	a[1][0]=t3;
	a[1][1]=t4;
}
void power(int F[2][2],int n){
	if(n==0||n==1)
		return;
	int M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if(n%2!=0)
		multiply(F,M);
}
int fib(int n){
	if(n==0)
		return 0;
	int F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	return F[0][0];
}
int main(){
	int n=6;
	printf("\n%dth fib=%d",n,fib(n));
	printf("\n");
	return 0;
}
