/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	0-1 KNAPSACK PROBLEM
*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
int knapSack(int *a,int *val,int n,int w){
	int **mat=(int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*(w+1));
	int j;
	for(i=0;i<n;i++){
		for(j=0;j<=w;j++){
			if(j==0)
				mat[i][j]=0;
			else{
				if(j>=a[i]){
					mat[i][j]=max(i-1>=0?(mat[i-1][j-a[i]]+val[i]):0,(i-1)>=0?mat[i-1][j]:0);
				}else
					mat[i][j]=(i-1)>=0?mat[i-1][j]:0;
			}
		}
	}
	return mat[n-1][w];
}
int main(){
	int a[]={10,20,30};
	int w=50;
	int val[]={60,100,120};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum profit is:%d",knapSack(a,val,n,w));
	printf("\n");
	return 0;
}
