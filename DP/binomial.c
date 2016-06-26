/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	BINOMIAL COEFFICIENT CALCULATION
*/
#include<stdio.h>
#include<stdlib.h>
int combUtil(int n,int k,int *mat[]){
	if(n==0 || k==0 || n==k){
		mat[n][k]=1;
		return 1;
	}
	if(mat[n][k]!=0)
		return mat[n][k];
	if(mat[n-1][k-1]!=0 && mat[n-1][k]!=0)
		return mat[n-1][k-1]+mat[n-1][k];
	if(mat[n-1][k-1]!=0)
		return mat[n-1][k-1]+combUtil(n-1,k,(int**)mat);
	if(mat[n-1][k]!=0)
		return mat[n-1][k]+combUtil(n-1,k-1,(int**)mat);
	return combUtil(n-1,k-1,(int**)mat)+combUtil(n-1,k,(int**)mat);
}
int comb(int n,int k){
	int **mat=(int**)malloc(sizeof(int*)*(n+1));
	int i,j;
	for(i=0;i<=n;i++)
		mat[i]=(int*)malloc(sizeof(int)*(k+1));
	for(i=0;i<=n;i++)
		for(j=0;j<=k;j++)
			mat[i][j]=0;
	return combUtil(n,k,(int**)mat);
}
int main(){
	int n,k;
	n=5;
	k=2;
	printf("\nc(%d,%d)=%d",n,k,comb(n,k));
	printf("\n");
	return 0;
}
