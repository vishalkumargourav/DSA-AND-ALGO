/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REARRANGE A GIVEN ARRAY ACCORDING TO GIVEN INDEX ARRAY
*/
#include<stdio.h>
void swap(int *a,int *index,int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	
	temp=index[i];
	index[i]=index[j];
	index[j]=temp;
}
void rearrangeUtil(int *a,int *index,int n,int i){
	int tempa,tempi;
	while(index[i]!=i){
		//printf("\nSwapping %d and %d",index[i],i);
		swap(a,index,index[i],i);
	}
}
void rearrange(int *a,int *i,int n){
	int j;
	for(j=0;j<n;j++)
		rearrangeUtil(a,i,n,j);
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int main(){
	int a[]={50,40,70,60,90};
	int i[]={3,0,4,1,2};
	//int a[]={10,11,12};
	//int i[]={1,0,2};
	int n=sizeof(a)/sizeof(a[0]);
	rearrange(a,i,n);
	printf("\nArray is:");
	printArr(a,n);
	printf("\nIndex is:");
	printArr(i,n);
	printf("\n");
	return 0;
}
