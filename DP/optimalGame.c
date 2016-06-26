/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	OPTIMAL GAME , FIND MAX PROFIT WHEN YOU ARE ALLOWED TO PICK ELEMENTS FROM ENDS
*/	
#include<stdio.h>
#include<stdlib.h>
typedef struct DP{
	int a,b;
}DP;
int max(int a,int b){
	return a>b?a:b;
}
int maxProfit(int *a,int n){
	DP **dp=(DP**)malloc(sizeof(DP*)*n);
	int i,j,l,sum,k;
	for(i=0;i<n;i++)
		dp[i]=(DP*)malloc(sizeof(DP)*n);
	for(i=0;i<n;i++){
		dp[i][i].a=a[i];
		dp[i][i].b=0;
	}
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			sum=0;
			for(k=i;k<=j;k++)
				sum+=a[k];
			dp[i][j].a=max(dp[i+1][j].b+a[i],a[j]+dp[i][j-1].b);
			dp[i][j].b=sum-dp[i][j].a;
		}
	}
	return dp[0][n-1].a;
}
int main(){
	//int a[]={5,3,7,10};
	//int a[]={8,15,3,7};
	int a[]={20,30,2,2,2,10};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum profit that can be gained =%d",maxProfit(a,n));
	printf("\n");
	return 0;
}
