/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MINIMUM NUMBER OF INSERTIONS REQUIRED TO MAKE IT A PALINDROME (RECURSIVE)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int findMin(char *str,int n){
	int **mat=(int**)malloc(sizeof(int*)*n);
	int i,l,j;
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		mat[i][i]=0;
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			if(l==2)
				mat[i][j]=(str[i]==str[j])?0:1;
			else
				mat[i][j]=(str[i]==str[j])?(mat[i+1][j-1]):(min(mat[i+1][j],mat[i][j-1])+1);
		}
	}
	return mat[0][n-1];
}
int main(){
	char *str="abcda";
	//char *str="aa";	
	//char *str="ab";
	int n=strlen(str);
	printf("\nMin insertions required are:%d",findMin(str,n));
	printf("\n");
	return 0;
}
