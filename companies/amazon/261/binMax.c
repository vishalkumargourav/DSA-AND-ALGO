/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A ARRAY THAT IS FIRST INCREASING AND THEN DECREASING FIND MAXIMUM ELEMENT
*/
#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int maxEle(int *a,int s,int e){
	if(s>e)
		return -1;
	if(s==e)
		return a[s];
	if(s==e-1)
		return max(a[s],a[e]);
	if(a[e]>a[e-1])
		return a[e];
	if(a[s]>a[s+1])
		return a[s];
	int mid=(s+e)/2;
	if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
		return a[mid];
	if(a[mid]>a[mid-1])
		return maxEle(a,mid+1,e);
	return maxEle(a,s,mid-1);
}
int main(){
	int a[]={8,10,20,80,100,200,400,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum element is:%d",maxEle(a,0,n-1));
	printf("\n");
	return 0;
}
