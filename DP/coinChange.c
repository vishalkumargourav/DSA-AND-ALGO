/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COIN CHANGE PROBLEM
*/
#include<stdio.h>
int findWays(int *a,int m,int n){
	int i,j;
	int **s=(int**)malloc(sizeof(int*)*(n+1));
	for(i=0;i<=n;i++)
		s=(int*)malloc(sizeof(int)*(m));
	for(i=0;i<m;i++)
		s[0][i]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			x=i-a[j]>=0?
		}
	}
}
int main(){
	int s[]={};
	int m=sizeof(s)/sizeof(s[0]);
	int n=4;
	printf("\nTotal number of ways=%d",findWays(s,m-1,n));
	printf("\n");
	return 0;
}
