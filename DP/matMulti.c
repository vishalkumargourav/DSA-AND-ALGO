/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MATRIX CHAIN MULTIPLICATION
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
void printParen(int i,int s,int e,int *s[]){

}
int minCost(int *p,int n){
	//HERE n IS LENGTH OF P i.e. ONE GREATER THAN THE NUMBER 
	//OF MATRICES
	int temp;
	int i;
	int **s=(int**)malloc(sizeof(int*)*n);
	int **mat=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		mat[i]=(int*)malloc(sizeof(int)*n);
		s[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=1;i<n;i++){
		s[i][i]=-1;
		mat[i][i]=0;
	}
	int l,j,k;
	for(l=2;l<n;l++){
		for(i=1;i<n-l+1;i++){ 		//i denotes starting point of group of matrices
			j=i+l-1;		//j denotes ending point of that group
			mat[i][j]=INT_MAX;
			for(k=i;k<j;k++){	//making a cut at kth position
				temp=min(mat[i][j],mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j]);
				if(temp!=mat[i][j]){
					mat[i][j]=temp;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\nMatrix generated is....\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printParen(0,0,n-1,(int**)s);
	return mat[1][n-1];
}
int main(){
	int p[]={30,35,15,5,10,20,25};
	int n=sizeof(p)/sizeof(p[0]);
	printf("\nMin cost=%d",minCost(p,n));
	printf("\n");
	return 0;
}
