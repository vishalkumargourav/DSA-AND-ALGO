//PRACTICE
//BIT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void update(int *BIT,int n,int index,int val){
	index++;
	
	while(index<=n){
		BIT[index]+=val;
		index+=(index&(-index));
	}
}
int getSum(int *BIT,int n,int index){
	index++;
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index-=(index&(-index));
	}
	return sum;
}
int *constructBIT(int *a,int n){
	int i;
	int *BIT=(int*)malloc(sizeof(int)*(n+1));
	memset(BIT,0,sizeof(int)*(n+1));
	for(i=0;i<n;i++)
		update(BIT,n,i,a[i]);
	return BIT;
}
int main(){
	int a[]={2,1,1,3,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	int *BIT=constructBIT(a,n);
	int k;
	for(k=0;k<n;k++)
		printf("\ngetSum(0,%d)=%d",k,getSum(BIT,n,k));
	printf("\n");
	return 0;
}
