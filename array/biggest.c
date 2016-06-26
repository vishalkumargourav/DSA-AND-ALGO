/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN AN ARRAY ARRAGE IT TO FORM THE BIGGEST NUMBER
*/
#include<stdio.h>
#include<math.h>
int countDigits(int a){
	int count=0;
	while(a!=0){
		count++;
		a/=10;
	}
	return count;
}
int concat(int a,int b){
	int digits=countDigits(b);
	a*=pow(10,digits);
	a+=b;
	return a;
}
int compare(void *a,void *b){
	int first=*(int*)a;
	int second=*(int*)b;
	int f1=concat(first,second);
	int f2=concat(second,first);
	return f2-f1;
}
void findMax(int *a,int n){
	qsort(a,n,sizeof(int),compare);
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int main(){
	int a[]={1,34,3,98,9,76,45,4};
	int n=sizeof(a)/sizeof(a[0]);
	findMax(a,n);
	printf("\nMaximum number is:");
	printArr(a,n);
	printf("\n");
	return 0;
}
