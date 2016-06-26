#include<iostream>
#include<stack>
using namespace std;
#include<cstdio>
#include<cstdlib>
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
	stack<node*> s;
	int n=10,i;
	node *k;
	for(i=0;i<n;i++)
		s.push(createNode(i));
	while(!s.empty()){
		k=s.top();
		s.pop();
		printf("%d ",k->data);
	}
	printf("\n"); 	
	return 0;
}
