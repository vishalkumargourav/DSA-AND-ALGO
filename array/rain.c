/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	TRAPPING THE RAINWATER PROBLEM
*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int maxWater(int *a,int n){
	int *right=(int*)malloc(sizeof(int)*n);
	int *left=(int*)malloc(sizeof(int)*n);
	int i;
	right[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
		right[i]=max(right[i+1],a[i]);
	left[0]=a[0];
	for(i=1;i<n;i++)
		left[i]=max(left[i-1],a[i]);
	int water=0;
	for(i=0;i<n;i++)
		water+=min(left[i],right[i])-a[i];
	return water;
}
int main(void){
	int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	int water=maxWater(a,n);
	printf("\nWater is:%d",water);
	printf("\n");
	return 0;
}
