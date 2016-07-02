/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MERGE K SORTED ARRAYS
*/
#include<queue>
#include<cstdio>
using namespace std;
#define K 3
#define N 4
typedef struct Node{
	int data;
	int i;
	int k;
	bool operator<(const Node &o) const{
		 return o.data<data;
	}
}Node;
void printMerged(int mat[K][N],int n,int k){
	priority_queue<Node,vector<Node>,less<Node> > pq;
	Node temp;
	int i;
	int cn;
	for(i=0;i<k;i++){
		temp.data=mat[i][0];
		temp.i=0;
		temp.k=i;
		pq.push(temp);
	}
	int t;
	printf("\nSorted order is:");
	while(!pq.empty()){
		t=pq.top().data;
		i=pq.top().i;
		cn=pq.top().k;
		pq.pop();
		printf("%d ",t);
		if(i+1<n){
			temp.data=mat[cn][i+1];
			temp.i=i+1;
			temp.k=cn;
			pq.push(temp);
		}
	}
}
int main(){
	int mat[K][N]={
			{1,3,5,7},
			{0,4,6,8},
			{2,9,10,11}	
		};
	printMerged(mat,N,K);
	printf("\n");
	return 0;
}
