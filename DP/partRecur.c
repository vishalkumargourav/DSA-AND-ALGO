/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PARTITION PROBLEM (RECURSIVE)
*/
#include<stdio.h>
#include<stdbool.h> 
bool isPartition(int *a,int i,int sum){
	if(sum==0)
		return true;
	if(i<0 && sum!=0)
		return false;
	return isPartition(a,i-1,sum-a[i]) || isPartition(a,i-1,sum);
}
int main(){
	int a[]={1,5,11,5},i;
	int n=sizeof(a)/sizeof(a[0]);
	int sum=0;
	for(i=0;i<n;i++)
		sum+=a[i];
	if(sum%2==0){
		if(isPartition(a,n-1,sum/2))
			printf("\nYes it is possible");
		else
			printf("\nNot possible!!!!");
	}else
		printf("\nNot possible!!!!");
	printf("\n");
	return 0;
}
