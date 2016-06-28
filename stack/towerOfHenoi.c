/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	TOWER OF HENOI
*/
#include<stdio.h>
void towerOfHenoi(int n,char from,char to,char aux){
	if(n==1){
		printf("\nMove disk from %c to %c",from,to);
		return;
	}
	towerOfHenoi(n-1,from,aux,to);
	printf("\nMove disk from %c to %c",from,to);
	towerOfHenoi(n-1,aux,to,from);
}
int main(){
	int n=4;
	towerOfHenoi(n,'A','C','B');
	return 0;
}
