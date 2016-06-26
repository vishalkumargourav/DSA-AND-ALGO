/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND Nth CATALAN NUMBER
*/
#include<stdio.h>
#include<stdlib.h>
int catalan(int n){
	int *c=(int*)malloc(sizeof(int)*(n+1));
	c[0]=c[1]=1;
	int i,j;
	for(i=2;i<=n;i++){
		c[i]=0;
		for(j=0;j<i;j++)
			c[i]+=(c[j]*c[i-j-1]);
	}
	return c[n];
}
int comb(int n,int k){
	int res=1,j;
	if(k>n-k)
		k=n-k;
	for(j=0;j<k;j++){
		res*=(n-j);
		res/=(j+1);
	}
	return res;
}
int main(){
	int i;
	int n=10;
	for(i=0;i<=n;i++){
		printf("\n%dth catalan number=%d",i,catalan(i));
		printf("\n%dth catalan number=%d",i,comb(2*i,i)/(i+1));
	}
	printf("\n");
	return 0;
}
