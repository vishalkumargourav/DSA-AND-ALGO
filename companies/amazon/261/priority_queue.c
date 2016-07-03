/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRIORITY QUEUE (HEAP SORT USING PRIORITY QUEUE)
*/
#include<cstdio>
#include<queue>
using namespace std;
typedef struct Node{
	int data;
	int i;
	bool operator<(const Node &o)const{
		return o.data<data;
	}
}Node;
void constructHeap(int *a,int n){
	priority_queue<Node,vector<Node>,less<Node> > pq;
	int i;
	Node temp;
	for(i=0;i<n;i++){
		temp.data=a[i];
		temp.i=i;
		pq.push(temp);
	}
	while(!pq.empty()){
		printf("%d  ",pq.top().data);
		pq.pop();
	}
}
int main(){
	int a[]={6,5,7,8,3,2,1,8,4,9};
	int n=sizeof(a)/sizeof(a[0]);
	constructHeap(a,n);
	printf("\n");
	return 0;
}
