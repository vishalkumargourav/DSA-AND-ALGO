/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	KADANE ALGO
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>	
void printSub(int *a,int i,int j){
	int k;
	for(k=i;k<=j;k++)
		printf("%d\t",a[k]);
}
int maxSubstr(int *a,int n){
	int max_so_far=INT_MIN;
	int max_curr=0;
	int start,end;
	start=end=0;
	int i;
	for(i=0;i<n;i++){
		max_curr=max_curr+a[i];
		if(max_curr<0){
			start=i+1;
			max_curr=0;
		}
		if(max_curr>max_so_far){
			max_so_far=max_curr;
			end=i;
		}
	}
	printf("\nMax sum substr:");
	printSub(a,start,end);
	return max_so_far;
}
int main(){
	int a[]={-2,-3,4,-1,-2,1,5,-3};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum sum substr is:%d",maxSubstr(a,n));
	printf("\n");
	return 0;
}
