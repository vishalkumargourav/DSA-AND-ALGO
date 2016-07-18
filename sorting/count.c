/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COUNTING SORT
*/
#include<stdio.h>
#include<stdlib.h>
#define RANGE 10	//for 0 to 9
void countSort(int *a,int n){
	int count[RANGE]={0};
	int i;
	int *output=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		count[a[i]]++;
	for(i=1;i<RANGE;i++)
		count[i]+=count[i-1];
	for(i=0;a[i];i++){
		output[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for(i=0;i<n;i++)
		a[i]=output[i];
	free(output);
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int main(){
	int a[]={2,3,5,6,7,8,3,4,1,9};
	int n=sizeof(a)/sizeof(a[0]);
	countSort(a,n);
	printf("\nArray is:");
	printArr(a,n);
	printf("\n");
	return 0;
}
