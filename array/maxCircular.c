/*
	AUTHOR 	:	VISHAL KUMAR GOURAV
	PROBLEM	: 	FIND MAXIMUM CIRCULAR SUBARRAY SUM
*/
#include<stdio.h>
int kadane(int *a,int n){
	int max_so_far=0;
	int i,sum=0;
	for(i=0;i<n;i++){
		sum+=a[i];
		if(sum>max_so_far)
			max_so_far=sum;
		if(sum<0)
			sum=0;
	}
	return max_so_far;
}
int max(int a,int b){
	return a>b?a:b;
}
int maxCircular(int *a,int n){
	int kad=kadane(a,n);
	int cir=0;
	int i;
	for(i=0;i<n;i++){
		cir=a[i];
		a[i]=-a[i];
	}
	cir=cir-kadane(a,n);
	return max(cir,kad);
}
int main(){
	int a[]={-2,-3,4,-1,-2,1,5,-3};
	int n=sizeof(a)/sizeof(a[0]);
	int res=maxCircular(a,n);
	printf("\nMaximum circular sum=%d",res);
	printf("\n");
	return 0;
}
