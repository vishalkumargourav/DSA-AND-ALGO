/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	LONGEST INCREASING SUBSEQUENCE
*/
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
int lis(int *a,int n){
	if(n<=0)
		return 0;
	int *len=(int*)malloc(sizeof(int)*n);
	len[0]=1;
	int i,j;
	for(i=1;i<n;i++){
		len[i]=INT_MIN;
		for(j=0;j<i;j++){
			if(a[i]>a[j] && len[j]+1>len[i])
				len[i]=len[j]+1;
		}
	}
	int max_len=1;
	printf("\nLis array is:");
	for(i=1;i<n;i++)
		printf("%d\t",len[i]);
	for(i=1;i<n;i++)
		max_len=max(max_len,len[i]);
	return max_len;
}
int main(){
	int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nLIS=%d",lis(a,n));
	printf("\n");
	return 0;
}
