/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND e^x
*/
#include<stdio.h>
#include<stdlib.h>
float expo(int x,int n){
	float sum=1.0f;
	int i;
	for(i=n-1;i>0;i--)
		sum=1+x*sum/i;
	return sum;
}
int main(){
	int x=1;
	int n=10;
	printf("\ne^%d=%f",x,expo(x,n));
	printf("\n");
	return 0;
}
