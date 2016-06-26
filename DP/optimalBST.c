/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT OPTIMAL BST
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int findOptimal(int *a,int *f,int n){
	int **mat=(int**)malloc(sizeof(int*)*n);
	int i,j,l,k,sum,x,y;
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		mat[i][i]=f[i];
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			sum=0;
			for(k=i;k<=j;k++)
				sum+=f[k];
			mat[i][j]=INT_MAX;
			for(k=i;k<=j;k++){
				x=(k>0)?mat[i][k-1]:0;
				y=(k<n-1)?mat[k+1][j]:0;
				mat[i][j]=min(mat[i][j],x+y+sum);
			}
		}
	}
	return mat[0][n-1];
}
int main(){
	int a[]={10,12,16};
	int f[]={34,8,50};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nResult is:%d",findOptimal(a,f,n));
	printf("\n");
	return 0;
}








