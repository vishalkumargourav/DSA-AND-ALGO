/*
	AUTHOR :	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE MAXIMUM HISTOGRAM AREA
*/
#include<cstdio>
using namespace std;
#include<stack>
#include<cstdlib>
int max(int a,int b){
	return a>b?a:b;
}
int maxArea(int *a,int n){
	stack<int> s;
	int *left=(int*)malloc(sizeof(int)*n);
	int i=0;
	for(i=0;i<n;i++)
		left[i]=-1;
	i=0;
	while(i<n){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			left[i]=s.top();
		else
			left[i]=-1;
		s.push(i);
		i++;
	}
	printf("\nLeft array is:");
	for(i=0;i<n;i++)
		printf("%d  ",left[i]);
	int *right=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		right[i]=n;
	i=n-1;
	while(!s.empty())
		s.pop();
	while(i>=0){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			right[i]=s.top();
		else
			right[i]=n;
		s.push(i);
		i--;
	}
	printf("\nRight array is:");
	for(i=0;i<n;i++)
		printf("%d  ",right[i]);
	//finding maximum
	int res=-1;
	for(i=0;i<n;i++)
		res=max(res,a[i]*(right[i]-left[i]-1));
	return res;
}
int main(){
	int a[]={6,2,5,4,5,1,6};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum area=%d",maxArea(a,n));
	printf("\n");
	return 0;
}
