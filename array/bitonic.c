/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE MAXIMUM LENGHT BITONIC SUBTONIC SUBARRAY
*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int bitonic(int *a,int n){
	int *left,*right;
	left=(int*)malloc(sizeof(int)*n);
	right=(int*)malloc(sizeof(int)*n);
	int i;
	left[0]=1;
	for(i=1;i<n;i++){
		if(a[i]>=a[i-1])
			left[i]=left[i-1]+1;
		else
			left[i]=1;
	}
	printf("\nLeft array is:");
	printArr(left,n);
	right[n-1]=1;
	for(i=n-2;i>=0;i--){
		if(a[i]>=a[i+1])
			right[i]=right[i+1]+1;
		else
			right[i]=1;
	}
	printf("\nRight array is:");
	printArr(right,n);
	int max_res=1;
	for(i=0;i<n;i++)
		max_res=max(max_res,left[i]+right[i]-1);
	return max_res;
}
int main(){
	int a[]={1,1,1,1};
	//int a[]={10,20,30,40};
	//int a[]={10};
	//int a[]={20,4,1,2,3,4,2,10};
	//int a[]={12,4,78,90,45,23};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum length bitonic subarray is:%d",bitonic(a,n));
	printf("\n");
	return 0;
}
