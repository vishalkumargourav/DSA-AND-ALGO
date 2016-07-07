/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND PEAK ELEMENT FROM ARRAY OF ELEMENTS
*/
#include<stdio.h>
int peak(int *a,int s,int e){
	if(s>e)
		return -1;
	if(s==e)
		return a[s];
	int mid=(s+e)/2;
	if((mid==s||a[mid-1]<=a[mid])&&(mid==e||a[mid+1]<=a[mid]))
		return a[mid];
	if(mid>=0 && a[mid-1]>a[mid])
		return peak(a,s,mid-1);
	return peak(a,mid+1,e);
}
int main(){
	//int a[]={20,1,3,4,1,0};
	//int a[]={3,3,3,3};
	//int a[]={10,8,4,2,1};
	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nPeak element is:%d",peak(a,0,n-1));
	printf("\n");
	return 0;
}
