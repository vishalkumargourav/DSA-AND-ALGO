/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A VERY LARGE BINARY NUMBER FIND THE REMAINDER WHEN IT IS DIVIDED BY ANY NUMBER K
*/
#include<stdio.h>
int remain(char *a,int n,int k){
	int prev=a[0]=='0'?0:1;
	int add;
	int i;
	for(i=1;i<n;i++){
		add=a[i]=='0'?0:1;
		prev=(2*prev+add)%k;
	}
	return prev;
}
int main(){
	//char a[]="101";
	char a[]="1010";
	int n=sizeof(a)/sizeof(a[0]);
	n--;
	int k=3;
	printf("\nRemainder when %s is divide by %d=%d",a,k,remain(a,n,k));
	printf("\n");
	return 0;
}
