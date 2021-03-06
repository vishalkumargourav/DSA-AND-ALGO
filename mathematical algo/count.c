/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COUNT DISTINCT x and y THAT SATISFY x*x+y*y<n
*/
#include<stdio.h>
#include<math.h>
int count(int n){
	int i,j,c;
	c=0;
	for(i=0;i<=sqrt(n);i++){
		for(j=0;j*j+i*i<n;j++)
			c++;
	}
	return c;
}
int main(){
	int n=6;
	printf("\nDistinct numbers are:%d",count(n));
	printf("\n");
	return 0;
}
