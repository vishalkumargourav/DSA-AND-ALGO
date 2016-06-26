#include<stdio.h>
#include<stdlib.h>
void calculateHeight(int *dp,int *p,int n,int i){
	if(i>=n)
		return;
	if(dp[i]!=-1)
		return;
	if(p[i]==-1){
		dp[i]=0;
		return;
	}
	if(dp[p[i]]!=-1){
		dp[i]=dp[p[i]]+1;
		return;
	}
	calculateHeight(dp,p,n,p[i]);
	dp[i]=dp[p[i]]+1;
}
int main(){
	//int p[]={1,5,5,2,2,-1,3};
	int p[]={-1,0,0,1,1,3,5};
	int *dp;
	int n=sizeof(p)/sizeof(p[0]);
	dp=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		dp[i]=-1;
	for(i=0;i<n;i++)
		calculateHeight(dp,p,n,i);
	printf("\nDepth array is:");
	for(i=0;i<n;i++)
		printf("%d ",dp[i]);
	printf("\n");
	return 0;
}
