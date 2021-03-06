/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND NUMBER OF WAYS IN WHICH SUM x CAN BE OBTAINED FROM n DICES EACH OF m FACES
*/
#include<stdio.h>
#include<stdlib.h>
int findWays(int m,int n,int x){
	int **mat=(int**)malloc(sizeof(int*)*(n+1));
	int i,j,k;
	for(i=0;i<=n;i++)
		mat[i]=(int*)malloc(sizeof(int)*(x+1));
	for(i=0;i<=n;i++){
		for(j=0;j<=x;j++)
			mat[i][j]=0;
	}
	for(j=1;j<=m && j<=x;j++)
		mat[1][j]=1;
	for(i=2;i<=n;i++){
		for(j=1;j<=x;j++){
			for(k=1;k<=m && k<j;k++)
				mat[i][j]+=mat[i-1][j-k];
		}
	}
	return mat[n][x];
}
int main(){
	int m,n,x;
	//m=4;n=2;x=1;
	//m=2;n=2;x=3;
	//m=6;n=3;x=8;
	//m=4;n=2;x=5;
	m=4;n=3;x=5;
	printf("\nNumber of ways=%d",findWays(m,n,x));
	printf("\n");
	return 0;
}
