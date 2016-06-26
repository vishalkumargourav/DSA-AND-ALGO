#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<queue>
typedef struct node{
	int data;
	struct node *next;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
int main(){
	int n=10;
	int i;
	node *k;
	queue<node*> q;
	for(i=0;i<n;i++)
		q.push(createNode(i));
	while(!q.empty()){
		k=q.front();
		q.pop();
		printf("%d ",k->data);
	}
	printf("\n");
	return 0;
}
