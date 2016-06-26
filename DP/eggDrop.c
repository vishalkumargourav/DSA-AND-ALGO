/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	EGG-DROPPING PROBLEM
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
int minDrops(int n,int k){
	int **mat=(int**)malloc(sizeof(int*)*(k+1));
	int i,j,l;
	for(i=0;i<=k;i++)
		mat[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=k;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0)
				mat[i][j]=0;
			else{
				if(i==1)
					mat[i][j]=j;
				else{
					mat[i][j]=INT_MAX;
					//printf("\nEggs=%d and floors=%d",i,j);
					for(l=1;l<=j;l++){
						//printf("\nfor %dth floor If egg breaks mat[%d][%d]=%d else mat[%d][%d]=%d",l,i-1,l-1,mat[i-1][l-1],mat[i][j-l],i,j-l);
						mat[i][j]=min(mat[i][j],max(mat[i-1][l-1],mat[i][j-l])+1);
					}
				}
			}
		}
	}
	printf("\nMatrix is..\n");
	for(i=0;i<=k;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
	return mat[k][n];
}
int main(){
	int n,k;
	n=6;
	k=2;
	printf("\nMin drops required are:%d",minDrops(n,k));
	printf("\n");
	return 0;
}
