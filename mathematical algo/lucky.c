/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	LUCKY NUMBER
*/
#include<stdio.h>
#include<stdbool.h>
bool isLuckyNumber(int n){
	static int counter=2;
	int next_pos=n;
	if(counter>n)
		return true;
	if(n%counter==0)
		return false;
	next_pos-=next_pos/2;
	counter++;
	return isLuckyNumber(next_pos);
}
int main(){
	int n=19;
	if(isLuckyNumber(n))
		printf("\nYes %d is lucky number",n);
	else
		printf("\nNo %d is not lucky number",n);
	printf("\n");
	return 0;
}
