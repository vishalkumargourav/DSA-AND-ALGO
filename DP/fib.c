/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CALCULATE FIBONACCI NUMBER
*/
#include<stdio.h>
#include<stdlib.h>
long long int fib(int n,long long int *f){
	if(n<=1)
		return n;
	if(f[n-1]==-1&&f[n-2]==-1){
		f[n-1]=fib(n-1,f);
		f[n-2]=fib(n-2,f);
	}else if(f[n-1]==-1)
		f[n-1]=fib(n-1,f);
	else if(f[n-2]==-1){
		f[n-2]=fib(n-2,f);
	}
	f[n]=f[n-1]+f[n-2];
	return f[n];
}
long long int fibRecur(int n){
	if(n<=1)
		return n;
	return fibRecur(n-1)+fibRecur(n-2);
}
long long int fibBottom(int n,long long int *f){
	int i;
	if(n<=1)
		return n;
	f[0]=0;
	f[1]=1;
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	return f[n];
}
int main(){
	int n=60;
	long long int *f=(long long int*)malloc(sizeof(long long int)*(n+1));
	int i;
	for(i=0;i<n+1;i++)
		f[i]=-1;
	//printf("\nFib of %d=%lld",n,fib(n,f));
	printf("\nFibBottom of %d=%d",n,fibBottom(n,f));
	//printf("\nRecur fib %d=%d",n,fibRecur(n));
	printf("\n");
	return 0;
}
