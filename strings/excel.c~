/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND EXCEL COLUMN NAME FOR GIVEN COLUMN NUMBER
*/
#include<stdio.h>
void printColumn(int n){
	if(n<26 && n>=0){
		printf("%c",'A'+n);
		return;
	}
	int q=n/26;
	int rem=n%26;
	printColumn(q-1);
	printf("%c",'A'+rem);
}
int main(){
	int a[]={26,51,52,80,676,702,705};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<n;i++){
		printf("\nColumn name for %d:",a[i]);
		printColumn(a[i]-1);
	}
	printf("\n");
	return 0;
}
