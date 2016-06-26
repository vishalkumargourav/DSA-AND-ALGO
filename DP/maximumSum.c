/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MAXIMUM SUM RECTANGLE IN 2-D MATRIX
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
int max(int a,int b,int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}
bool allNegative(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		if(a[i]>=0)
			return false;
	return true;
}
int maximum(int *a,int n,int *start,int *end){
	int i;
	int max=INT_MIN;
	for(i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
			*start=*end=i;
		}
	}
	return max;
}
int kadane(int *a,int n,int *start,int *end){
	if(allNegative(a,n))
		return maximum(a,n,start,end);
	int max_so_far,max_curr;
	max_so_far=INT_MIN;
	max_curr=0;
	int i;
	for(i=0;i<n;i++){
		max_curr+=a[i];
		if(max_curr>max_so_far){
			*end=i;
			max_so_far=max_curr;
		}
		if(max_curr<0)
			max_curr=0;
	}
	//to find start index
	int sum=0;
	for(i=*end;i>=0;i--){
		sum+=a[i];
		*start=i;
		if(sum==max_so_far)
			break;
	}
	return max_so_far;
}
void printArr(int *a,int i,int j){
	int k;
	for(k=i;k<j;k++)
		printf("%d\t",a[k]);
	printf("\n");
}
int findMax(int mat[4][5],int R,int C){
	int ta[4]={0};
	int start,end;
	int max_left,max_right,max_top,max_bottom,max_so_far,max_curr;
	max_so_far=INT_MIN;
	max_left=max_right=max_top=max_bottom=0;
	int l,r,i,k,j;
	for(i=0;i<C;i++){
		l=i;
		for(j=i;j<C;j++){
			r=j;
			for(k=0;k<R;k++)
				ta[k]+=mat[k][r];
			start=end=0;
			max_curr=kadane(ta,R,&start,&end);
			//printf("\nArray ta[] for l=%d and r=%d is:\n",l,r);
			//printArr(ta,0,R);
			//printf("\nMax sum=%d and indices are %d-%d\n",max_curr,start,end);
			if(max_curr>max_so_far){
				//printf("\nUpdating maximum seen so far\n");
				max_so_far=max_curr;
				max_top=start;
				max_bottom=end;
				max_left=l;
				max_right=r;
			}
		}
		for(k=0;k<R;k++)
			ta[k]=0;
	}
	printf("\nMaximum matrix is..\n");
	for(i=max_top;i<=max_bottom;i++){
		for(j=max_left;j<=max_right;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
	return max_so_far;
}
int main(){
	int r=4,c=5;
	int mat[4][5]={
		{1	,2	,-1	,-4	,-20},
		{-8	,-3	,4	,2	,1},
		{3	,8	,10	,1	,3},
		{-4	,-1	,1	,7	,-6}
	};
	printf("\nMax sum=%d",findMax(mat,r,c));
	printf("\n");
	return 0;
}
