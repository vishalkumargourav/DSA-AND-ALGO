/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	WORD WRAP PROBLEM	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int minCost(char *words[],int n,int max_words){
	int **mat=(int**)malloc(sizeof(int*)*n);
	int i,j,k,count;
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=INT_MAX;
	for(i=0;i<n;i++){
		mat[i][i]=INT_MAX;
		for(j=i;j<n;j++){
			count=0;
			for(k=i;k<=j;k++){
				if(k!=i)
					count++;//for the space
				count+=strlen(words[k]);
			}
			count=max_words-count;
			if(count>=0)
				mat[i][j]=min(mat[i][j],count*count);
		}
	}
	printf("\nMatrix generated is...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]!=INT_MAX)
				printf("%d\t",mat[i][j]);
			else
				printf("INF\t");
		}
		printf("\n");
	}
	int *cost=(int*)malloc(sizeof(int)*n);
	int *pos=(int*)malloc(sizeof(int)*n);
	int tempCost;
	for(i=n-1;i>=0;i--){
		cost[i]=INT_MAX;
		for(j=n;j>i;j--){
			if(mat[i][j-1]!=INT_MAX){
				tempCost=(j==n)?(mat[i][j-1]):(mat[i][j-1]+cost[j]);
				cost[i]=min(cost[i],tempCost);
			}
		}
	}
	printf("\nCost mat is:");
	for(j=0;j<n;j++){
		if(cost[j]!=INT_MAX)
			printf("%d\t",cost[j]);
		else
			printf("INF");
	}return cost[0];
}
int main(){
	char *words[]={"tushar","roy","loves","to","code"};
	int n=sizeof(words)/sizeof(words[0]);
	int max_words=10;
	printf("\nMin cost is:%d",minCost(words,n,max_words));
	printf("\n");
	return 0;
}
