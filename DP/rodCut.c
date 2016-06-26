/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CUT THE ROD TO MAXIMIZE THE PROFIT
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max(int a,int b){
	return a>b?a:b;
}
int maxProfit(int *p,int n){
	int *r=(int*)malloc(sizeof(int)*(n+1));
	int i,j;
	r[0]=0;
	for(i=1;i<=n;i++){
		r[i]=INT_MIN;
		for(j=0;j<i;j++)
			r[i]=max(r[i],p[j]+r[i-j-1]);
	}
	return r[n];
}
int main(){
	int a[]={1,5,8,9,10,17,17,20};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum profit that can be obtained =%d",maxProfit(a,n));
	printf("\n");
	return 0;
}
