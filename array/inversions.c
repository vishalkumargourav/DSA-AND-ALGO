/*
	AUTHOR	: 	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND INVERSIONS IN A GIVEN ARRAY
*/
#include<bits/stdc++.h>
using namespace std;
int cmp(void *a,void *b){
	int f=*(int*)a;
	int s=*(int*)b;
	return f-s;
}
int getSum(int *BIT,int index){
	index++;
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index-=(index&(-index));
	}
	return sum;
}
void update(int *BIT,int n,int index,int val){
	index++;
	while(index<=n){
		BIT[index]+=val;
		index+=(index&(-index));
	}
}
int countInversions(int a[],int n){
	int *BIT=(int*)malloc(sizeof(int)*(n+1));
	int temp[n];
	int i;
	for(i=0;i<n;i++)
		temp[i]=a[i];
	sort(temp,temp+n);
	for(i=0;i<n;i++)
		a[i]=lower_bound(temp,temp+n,a[i])-temp+1;
	printf("\narray is:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	int inv=0;
	for(i=n-1;i>=0;i--){
		inv+=getSum(BIT,a[i]-1);
		update(BIT,n,a[i],1);
	}
	return inv;
}
int main(){
	int a[]={8,4,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nInversions=%d",countInversions(a,n));
	printf("\n");
	return 0;
}
