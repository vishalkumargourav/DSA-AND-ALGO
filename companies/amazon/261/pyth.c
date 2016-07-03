/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND PYTHAGOREAN TRIPLETS FROM GIVEN ARRAY
*/
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b){
	int f=*(int*)a;
	int s=*(int*)b;
	return f-s;
}
void printArr(int *a,int n){
	printf("\nArray is:");
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void printTriplet(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		a[i]*=a[i];
	qsort(a,n,sizeof(int),cmp);
	printArr(a,n);
	int s,e;
	for(i=n-1;i>1;i--){
		s=0;
		e=i-1;
		while(s<e){
			if(a[s]+a[e]==a[i]){
				printf("\n%d,%d,%d forms pythagorian triplet",(int)sqrt(a[s]),(int)sqrt(a[e]),(int)sqrt(a[i]));
				s++;
				e--;
			}else if(a[s]+a[e]>a[i])
				e--;
			else	
				s++;
		}
	}
}
int main(){
	int a[]={3,1,4,6,5};
	int n=sizeof(a)/sizeof(a[0]);
	printTriplet(a,n);
	printf("\n");
	return 0;
}
