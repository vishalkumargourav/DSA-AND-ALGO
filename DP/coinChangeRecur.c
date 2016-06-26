/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COIN CHANGE PROBLEM
*/
#include<stdio.h>
int findWays(int *s,int m,int n){
	if(n==0)
		return 1;
	//if n<0 no solution exsists
	if(n<0)
		return 0;
	if(m<0 && n>=1)
		return 0;
	return findWays(s,m-1,n)+findWays(s,m,n-s[m]);
}
int main(){
	int s[]={1,2,3};
	int m=sizeof(s)/sizeof(s[0]);
	int n=4;
	printf("\nNumber of ways is:%d",findWays(s,m-1,n));
	return 0;
}
