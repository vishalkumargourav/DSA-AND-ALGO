/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM PRODUCT SUBARRAY
*/
#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int findMax(int *a,int n){
	int max_ending_here=1;
	int min_ending_here=1;
	int max_so_far=1;
	int i;
	for(i=0;i<n;i++){
		if(a[i]>0){
			max_ending_here=max_ending_here*a[i];
			min_ending_here=min(min_ending_here*a[i],1);
		}
		else if (a[i]==0){
			max_ending_here=1;
			min_ending_here=1;
		}else{
			int temp=max_ending_here;
			max_ending_here=max(min_ending_here*a[i],1);
			min_ending_here=temp*a[i];
		}
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}
	return max_so_far;
}
int main(){
	int a[]={1,-2,-3,0,7,-8,-2};
	int n=sizeof(a)/sizeof(a[0]);
	int res=findMax(a,n);
	printf("\nResult is:%d",res);
	printf("\n");
	return 0;
}
