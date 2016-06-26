/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LONGEST COMMON SUBSTRING
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
	return a>b?a:b;
}
int lcs(char *X,char *Y,int m,int n){
	int **mat=(int**)malloc(sizeof(int*)*(m+1));
	int i,res,j;
	res=-1;
	for(i=0;i<=m;i++)
		mat[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0)
				mat[i][j]=0;
			else if(X[i-1]==Y[j-1]){
				mat[i][j]=mat[i-1][j-1]+1;
				res=max(mat[i][j],res);
			}else
				mat[i][j]=0;
		}
	}
	return res;
}
int main(){
	char *X="OldSite:GeeksforGeeks.org";
	char *Y="NewSite:GeeksQuiz.com";
	int m=strlen(X);
	int n=strlen(Y);
	printf("\nLCS=%d",lcs(X,Y,m,n));
	printf("\n");
	return 0;
}
