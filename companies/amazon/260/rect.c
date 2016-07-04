/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LARGEST RECTANGULAR AREA UNDER HISTOGRAM
*/
#include<cstdio>
#include<stack>
#include<cstdlib>
using namespace std;
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
int findMax(int *a,int n){
	stack<int> s;
	int *left=(int*)malloc(sizeof(int)*n);
	int *right=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		left[i]=-1;
	for(i=0;i<n;i++)
		right[i]=n;
	i=0;
	while(i<n){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			left[i]=s.top();
		s.push(i);
		i++;
	}
	printf("\nLeft array is:");
	printArr(left,n);
	i=n-1;
	while(!s.empty())
		s.pop();
	while(i>=0){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			right[i]=s.top();
		s.push(i);
		i--;
	}
	printf("\nRight array is:");
	printArr(right,n);
	int max=0,curr;
	for(i=0;i<n;i++){
		curr=(right[i]-left[i]-1)*a[i];
		if(curr>max)
			max=curr;
	}
	return max;
}
int main(){
	int a[]={6,2,5,4,5,1,6};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum rectangular area=%d",findMax(a,n));
	printf("\n");
	return 0;
}
