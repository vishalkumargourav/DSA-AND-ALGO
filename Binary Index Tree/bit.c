/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT A BIT
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getSum(int *bitTree,int index){
	int sum=0;
	index++;
	while(index>0){
		sum+=bitTree[index];
		index=index-(index&(-index));
	}
	return sum;
}
void update(int *bitTree,int n,int index,int val){
	index++;
	while(index<=n){
		bitTree[index]+=val;
		index=index+(index&(-index));
	}
}
int *constructBit(int *a,int n){
	int *bitTree=(int*)malloc(sizeof(int)*(n+1));
	memset(bitTree,0,sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		update(bitTree,n,i,a[i]);
	return bitTree;
}
int main(){
	int a[]={2,1,1,3,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	int *bitTree=constructBit(a,n);
	int k;
	for(k=0;k<n;k++)
		printf("\nSum(0,%d)=%d",k,getSum(bitTree,k));
	a[3]+=6;
	update(bitTree,n,3,6);
	for(k=0;k<n;k++)
		printf("\nSum(0,%d)=%d",k,getSum(bitTree,k));
	printf("\n");
	return 0;
}
