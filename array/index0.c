/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A BINARY ARRAY FIND INDEX OF 0 TO BE REPLACED WITH 1 SO AS TO ACHIEVE LONGEST SUBARRAY OF ALL 1's
*/
#include<stdio.h>
int findIndex(int *a,int n){
	int curr=0;
	int index=-1;
	int max_len=1;
	int prev=-1,prev_prev=-1;
	while(curr<n){
		if(a[curr]==0){
			if(curr-prev_prev>max_len){
				index=prev;
				max_len=curr-prev_prev;
			}
			prev_prev=prev;
			prev=curr;
		}
		curr++;
	}
	if(n-prev_prev>max_len){
		max_len=n-prev_prev;
		index=prev;
	}
	return index;
}
int main(){
	int a[]={1,1,0,0,1,0,1,1,1,0,1,1,1};
	int n=sizeof(a)/sizeof(a[0]);
	int index=findIndex(a,n);
	printf("\nIndex = %d",index);
	printf("\n");
	return 0;
}
