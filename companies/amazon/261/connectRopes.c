/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONNECT ROPES WITH MINIMUM COST
*/
#include<cstdio>
using namespace std;
#include<cstdlib>
#include<stack>
int cmp(const void *a,const void *b){
	int f=*(int*)a;
	int s=*(int*)b;
	return s-f;
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int findMin(int *a,int n){
	stack<int> s;
	int i,t1,t2;
	int res=0;
	for(i=0;i<n;i++)
		s.push(a[i]);
	while(s.size()>1){
		t1=s.top();
		s.pop();
		t2=s.top();
		s.pop();
		t1+=t2;
		res+=t1;
		s.push(t1);
	}
	return res;
}
int main(){
	int a[]={4,3,2,6};
	int n=sizeof(a)/sizeof(a[0]);
	qsort(a,n,sizeof(int),cmp);
	printf("\nMin cost=%d",findMin(a,n));
	printf("\n");
	return 0;
}
