/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND TRALING ZEROS IN FACTORIAL OF A NUMBER
*/
#include<stdio.h>
#include<math.h>
int min(int a,int b){
	return a<b?a:b;
}
int zeros(int n){
	int res=0,i=5;
	while(n/i>0){
		res+=(n/i);
		i*=5;
	}
	return res;
}
int main(){
	int n,i;
	n=100;
	for(i=0;i<=n;i++)
	printf("\nNumber of 0's in %d!=%d",i,zeros(i));
	printf("\n");
	return 0;
}
