/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COIN CHANGE PROBLEM
*/
#include<stdio.h>
#include<stdlib.h>
int findWays(int *a,int m,int n){
	int i,j,x,y;
	int **mat=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
		mat[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<m;i++){
		for(j=0;j<=n;j++){
			if(j==0)
				mat[i][j]=1;
			else{
				x=(i-1>=0)?mat[i-1][j]:0;
				y=(j-a[i]>=0)?mat[i][j-a[i]]:0;
				mat[i][j]=x+y;
			}
		}
	}
	return mat[m-1][n];
}
int main(){
	int s[]={1,2,3};
	int m=sizeof(s)/sizeof(s[0]);
	int n=5;
	printf("\nTotal number of ways=%d",findWays(s,m,n));
	printf("\n");
	return 0;
}
