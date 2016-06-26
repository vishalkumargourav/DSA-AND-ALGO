/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL WAYS IN WHICH YOU CAN GET n FROM 1,2,and 3
*/
#include<stdio.h>
#include<stdlib.h>
int allWays(int n,int x){
	int **dp=(int**)malloc(sizeof(int*)*(x+1));
	int i,k,j;
	for(i=0;i<x+1;i++)
		dp[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=x;i++)
		dp[i][0]=1;
	for(i=0;i<=n;i++)
		dp[0][i]=1;
	for(i=1;i<=x;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=x && k<=j;k++)
				dp[i][j]+=dp[i-1][j-k];
		}
	}
	printf("\nMatrix is...\n");
	for(i=0;i<=x;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",dp[i][j]);
		printf("\n");
	}
	return dp[x][n];
}
int main(){
	int n=4;
	int x=3;//here it would be 3
	printf("\nNumber of ways=%d",allWays(n,x));
	printf("\n");
	return 0;
}
