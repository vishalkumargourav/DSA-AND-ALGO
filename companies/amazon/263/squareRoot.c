/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND SQUARE ROOT OF A NUMBER
*/
#include<stdio.h>
int squareRoot(int n){
	if(n==0||n==1)
		return n;
	int i=1,temp;
	while(i<n){
		temp=i*i;
		if(temp==n)
			return i;
		i++;
	}
	return -1;
}
int binSquareRoot(int s,int e,int n){
	int mid=(s+e)/2;
	if(s>e)
		return -1;
	if(s==e){
		if(s*s==n)
			return s;
		return -1;
	}
	if(mid*mid==n)
		return mid;
	if(mid*mid<n)
		return binSquareRoot(mid+1,e,n);
	return binSquareRoot(s,mid-1,n);
}
int main(){
	int n;
	for(n=1;n<=100;n++){
		//printf("\nSquare root of %d=%d",n,squareRoot(n));
		printf("\nSquare root of %d=%d",n,binSquareRoot(0,n,n));
	}
	printf("\n");
	return 0;
}
