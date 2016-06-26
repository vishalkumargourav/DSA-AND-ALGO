/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND C(n,k)
*/
#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
	return a<b?a:b;
}
int comb(int n,int k){
	int *C=(int*)calloc(sizeof(int),n+1);
	C[0]=1;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=min(i,k);j>0;j--)
			C[j]=C[j]+C[j-1];
	}
	return C[k];
}
int binomial(int n,int k){
	int res=1;
	int i;
	if(k>n-k)
		k=n-k;
	for(i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
int main(){
	int n,k;
	n=5;k=2;
	printf("\nC(%d,%d)=%d",n,k,comb(n,k));
	printf("\nC(%d,%d)=%d",n,k,binomial(n,k));
	n=10;k=4;
	printf("\nC(%d,%d)=%d",n,k,comb(n,k));
	printf("\nC(%d,%d)=%d",n,k,binomial(n,k));
	printf("\n");
	return 0;
}
