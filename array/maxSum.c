/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM SUM FROM AN ARRAY SO THAT NO TWO ELEMENTS ARE ADJACENT
*/
#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int findMax(int *a,int n){
	int incl,excl;
	incl=a[0];
	excl=0;
	int i;
	int texcl;
	for(i=1;i<n;i++){
		texcl=max(incl,excl);
		incl=excl+a[i];
		excl=texcl;
	}
	return max(incl,excl);
}
int main(){
	int a[]={5,5,10,100,10,5};
	int res=findMax(a,sizeof(a)/sizeof(a[0]));
	printf("\nMaximum sum is:%d",res);
	printf("\n");
	return 0;
}
