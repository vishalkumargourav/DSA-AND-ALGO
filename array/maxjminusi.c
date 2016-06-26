/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM j-i SUCH THAT a[j]>a[i]
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int findMax(int *a,int n){
	int *lMin,*rMax;
	int max_res=-1;
	lMin=(int*)malloc(sizeof(int)*n);
	rMax=(int*)malloc(sizeof(int)*n);
	int i;
	lMin[0]=a[0];
	for(i=1;i<n;i++)
		lMin[i]=min(a[i],lMin[i-1]);
	rMax[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
		rMax[i]=max(a[i],rMax[i+1]);
	int j;
	i=j=0;
	while(i<n&&j<n){
		if(lMin[i]<rMax[j]){
			if((j-i)>max_res)
				max_res=j-i;
			j++;
		}else
			i++;
	}
	return max_res;
}
int main(){
	int a[]={6,5,4,3,2,1};
	//int a[]={1,2,3,4,5,6};
	//int a[]={34,8,10,3,2,80,30,33,1};
	//int a[]={9,2,3,4,5,6,7,8,18,0};
	int n=sizeof(a)/sizeof(a[0]);
	int res=findMax(a,n);
	printf("\nAnswer is:%d",res);
	printf("\n");
	return 0;
}
