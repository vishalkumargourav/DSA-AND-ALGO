/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM OF MININUM OF EVERY WINDOW SIZE
*/
#include<cstdio>
using namespace std;
#include<stack>
#include<cstdlib>
void maxMin(int *a,int n){
	int *left=(int*)malloc(sizeof(int)*n);
	int *right=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++){
		left[i]=-1;
		right[i]=n;
	}
	stack<int> s;
	s.push(0);
	i=1;
	while(i<n){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			left[i]=s.top();
		s.push(i);
		i++;
	}
	printf("\nLeft array is:");
	for(i=0;i<n;i++)
		printf("%d  ",left[i]);
	while(!s.empty())
		s.pop();
	s.push(n-1);
	i=n-2;
	while(i>=0){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			right[i]=s.top();
		s.push(i);
		i--;
	}
	printf("\nRight array is:");
	for(i=0;i<n;i++)
		printf("%d  ",right[i]);
	while(!s.empty())
		s.pop();
	int *ans=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=n;i++)
		ans[i]=0;
	for(i=0;i<n;i++){
		int len=right[i]-left[i]-1;
		ans[len]=max(ans[len],a[i]);
	}
	for(i=n-1;i>=1;i--)
		ans[i]=max(ans[i],ans[i+1]);
	printf("\nAnswer is:");
	for(i=1;i<=n;i++)
		printf("%d  ",ans[i]);
}
int main(){
	int a[]={10,20,30,50,10,70,30};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nResult is:");
	maxMin(a,n);
	printf("\n");
	return 0;
}
