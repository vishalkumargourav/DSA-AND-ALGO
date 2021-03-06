/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM SUM i*a[i] with rotations
*/
#include<stdio.h>
#include<limits.h>
int rotate(int *a,int n){
	int arrSum=0;
	//int tsum;
	int max=INT_MIN;
	int i;
	for(i=0;i<n;i++)
		arrSum+=a[i];
	int sum=0;
	for(i=0;i<n;i++)
		sum+=(i*a[i]);
	int count=1;
	max=sum;
	for(i=n-1;i>=1;i--){
		sum=sum+arrSum-n*a[i];
		if(sum>max)
			max=sum;
	}
	return max;
}
int main(){
	//int a[]={1,20,2,10};
	int a[]={10,1,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum rotation sum=%d",rotate(a,n));
	printf("\n");
	return 0;
}
