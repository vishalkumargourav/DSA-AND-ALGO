/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	WRITE A log(y) TIME FUNCTION FOR pow(x,y)
*/
#include<stdio.h>
int power(int x,int y){
	int res=1;
	while(y>0){
		if(y&1)
			res*=x;
		x*=x;
		y=y>>1;
	}
	return res;
}
int main(){
	int x,y;
	x=2;
	y=5;
	printf("\npow(%d,%d)=%d",x,y,power(x,y));
	printf("\n");
	return 0;
}
