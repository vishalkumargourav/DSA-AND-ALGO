/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE EDIT DISTANCE B/W TWO STRINGS
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
int findEditDist(char *str1,char *str2,int m,int n){
	int i,j;
	int **dp=(int**)malloc(sizeof(int*)*(1+m));
	for(i=0;i<=m;i++)
		dp[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else 	
				dp[i][j]=1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);		
		}
	}
	//PRINTING THE DP MATRIX
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",dp[i][j]);
		printf("\n");
	}
	return dp[m-1][n-1];
}
int main(){
	char *str1="sunday";
	char *str2="saturday";
	int m=strlen(str1);
	int n=strlen(str2);
	int res=findEditDist(str1,str2,m,n);
	printf("\nEdit distance=%d",res);
	printf("\n");
	return 0;
}
