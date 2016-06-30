/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A NXN MATRIX FIND SUM OF ALL KXK MATRICES
*/
#include<stdio.h>
#define N 5
void printKxK(int mat[N][N],int n,int k){
	int strip[N][N]={0};
	int i,j;
	for(i=0;i<n;i++){//columns
		for(j=0;j<k;j++){//rows
			if(j==0)
				strip[j][i]=mat[j][i];
			else
				strip[j][i]=strip[j-1][i]+mat[j][i];
		}
	}
	for(i=0;i<n;i++){//rows
		for(j=k;j<n;j++)//columns
			strip[j][i]=-mat[j-k][i]+mat[j][i]+strip[j-1][i];
	}
	printf("\nStrip matrix is...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",strip[i][j]);
		printf("\n");
	}
	int sum=0;
	printf("\nRequired result is...\n");
	for(j=k-1;j<n;j++){
		sum=0;
		for(i=0;i<k;i++)
			sum+=strip[j][i];
		for(i=k;i<n;i++){
			printf("%d\t",sum);
			sum=sum-strip[j][i-k]+strip[j][i];
		}
		printf("%d\t",sum);
		printf("\n");
	}
}
int main(){
	int mat[N][N]={
		{1,1,1,1,1},
		{2,2,2,2,2},
		{3,3,3,3,3},
		{4,4,4,4,4},
		{5,5,5,5,5}
	};
	int k=3;
	printKxK(mat,N,k);
	return 0;
}
