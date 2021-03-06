/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND A SUBARRAY WITH GIVEN SUM
*/
#include<stdio.h>
void findSubarray(int *a,int n,int sum){
	int res=0,i=0;
	res=a[0];
	int start=0;
	for(i=1;i<n;i++){
		while(res>sum && start<i-1){
			res-=a[start];
			start++;
		}
		if(sum==res){
			printf("\nIndex %d to %d has sum=%d",start,i-1,sum);
			return;
		}
		if(i<n)
			res+=a[i];
	}
}
int main(){
	int a[]={15,2,4,8,9,5,10,23};
	int n=sizeof(a)/sizeof(a[0]);
	int sum=23;
	findSubarray(a,n,sum);
	printf("\n");
	return 0;
}
