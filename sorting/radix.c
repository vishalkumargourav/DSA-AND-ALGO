/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	RADIX SORT
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define RANGE 10	//for 0 to 9
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void countSort(int *a,int n,int exp){
	int count[RANGE]={0};
	int i;
	printf("\nExp=%d",exp);
	int *output=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		count[(a[i]/exp)%10]++;
	for(i=1;i<RANGE;i++)
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--){
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		a[i]=output[i];
	printf("\nArray t is:");
	printArr(output,n);
	free(output);
}
int findMax(int *a,int n){
	int max=INT_MIN;
	int i;
	for(i=0;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	return max;
}
void radixSort(int *a,int n){
	int exp=1;
	int max=findMax(a,n);
	printf("\nMax is:%d",max);
	for(exp=1;(max/exp)>0;exp*=10)
		countSort(a,n,exp);
}
int main(){
	int a[]={222,33,15,56,27,88,43,49,11,39};
	int n=sizeof(a)/sizeof(a[0]);
	radixSort(a,n);
	printf("\nArray is:");
	printArr(a,n);
	printf("\n");
	return 0;
}
