/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	QUICK SORT
*/
#include<stdio.h>
void swap(int *a,int i,int j){
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int partition(int *a,int s,int e){
	int p=s-1;
	int i=s;
	int pivot=a[e];
	while(i<e){
		if(a[i]<=pivot){
			p++;
			swap(a,p,i);
		}
		i++;
	}
	p++;
	swap(a,p,e);
	return p;
}
void quickSort(int *a,int s,int e){
	if(s>=e)
		return;
	int p=partition(a,s,e);
	quickSort(a,s,p-1);
	quickSort(a,p+1,e);
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(){
	int a[]={2,3,9,8,7,4,1,5,6,7,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	quickSort(a,0,n-1);
	printf("\nArray is:");
	printArr(a,n);
	return 0;
}
