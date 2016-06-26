/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A SORTED ARRAY FIND FIRST OCCURENCE OF GIVEN ELEMENT
*/
#include<stdio.h>
#include<stdbool.h>
int findIndex(int *a,int s,int e,int x){
	if(s>e)
		return -1;
	if(s==e){
		if(a[s]==x)
			return s;
		return -1;
	}
	int mid=(s+e)/2;
	if((mid==0 || a[mid-1]<x) && a[mid]==x)
		return mid;
	if(a[mid]<x)
		return findIndex(a,mid+1,e,x);
	return findIndex(a,s,mid-1,x);
}
bool isMajority(int *a,int n,int x){
	int index=findIndex(a,0,n-1,x);
	printf("\nStarting index for %d is %d",x,index);
	return index!=-1 && (index+n/2)<n && a[index+n/2]==x;
}
int main(){
	int a[]={1,2,3,3,3,3,10};
	int n=sizeof(a)/sizeof(a[0]);
	int x=3;
	if(isMajority(a,n,x))
		printf("\nYes %d is majority element",x);
	else
		printf("\nNo %d is not majority element",x);
	printf("\n");
	return 0;
}
