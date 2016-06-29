/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	USE OF PRIORITY QUEUE VIA STL
*/
#include<cstdio>
using namespace std;
#include<queue>
int main(){
	int t;
	int a[]={4,5,6,3,4,1,2,8,9,7};
	int n=sizeof(a)/sizeof(a[0]);
	priority_queue<int,vector<int> > pq(a,a+n);
//	priority_queue<int,vector<int>,greater<int> > pq(a,a+n);
	while(pq.size()){
		t=pq.top();
		pq.pop();
		printf("\nPopped element is:%d",t);
	}
	printf("\n");
	return 0;
}
