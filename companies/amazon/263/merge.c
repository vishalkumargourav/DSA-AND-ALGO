/*	
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MERGE TWO SORTED ARRAYS IN CONSTANT EXTRA SPACE
*/
#include<stdio.h>
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
void merge(int *a,int *b,int m,int n){
	int i,last,j;
	for(i=n-1;i>=0;i--){
		last=a[m-1];
		for(j=m-1;j>=0 && a[j]>b[i];j--){
			if(j!=0)
				a[j]=a[j-1];
		}
		if(j!=m-1){
			a[j+1]=b[i];
			b[i]=last;
		}
	}
}
int main(){
	int a[]={1,5,9,10,15,20};
	int b[]={2,3,8,13};
	int n=sizeof(b)/sizeof(b[0]);
	int m=sizeof(a)/sizeof(a[0]);
	merge(a,b,m,n);
	printf("\nArray a is:");
	printArr(a,m);
	printf("\nArray b is:");
	printArr(b,n);	
	printf("\n");
	return 0;
}
