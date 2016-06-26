/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN n and p FIND LARGEST x SUCH THAT p^x DIVIDES n!
*/
#include<stdio.h>
int findMax(int n,int p){
	int x=0;
	while(n){
		x+=(n/p);
		n/=p;
	}
	return x;
}
int main(){
	int n,p;
	n=10;
	p=3;
	printf("\nMaximum value of x=%d",findMax(n,p));
	printf("\n");
	return 0;
}
