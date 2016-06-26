/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND IF A NUMBER IS MULTIPLE OF THREE
*/
#include<stdio.h>
#include<stdbool.h>
bool isMultiple(int n){
	if(n==0)
		return true;
	if(n==1)
		return false;
	int odd_count,even_count;
	odd_count=even_count=0;
	while(n>0){
		if(n&1)
			odd_count++;
		n>>=1;
		if(n&1)
			even_count++;
		n>>=1;
	}
	return isMultiple(abs(odd_count-even_count));
}
int main(){
	int n;
	for(n=0;n<=100;n++){
		if(isMultiple(n))
			printf("\n%d is multiple of three",n);
	}
	printf("\n");
	return 0;
}
