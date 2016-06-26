/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	LARGEST INDEPENDENT SET PROBLEM
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
int lis(Node *root,bool flag){
	if(NULL==root)
		return 0;
	if(!flag){
		return max(1+lis(root->left,true)+lis(root->right,true),lis(root->left,false)+lis(root->right,false));
	}else
		return lis(root->left,false)+lis(root->right,false);
}
int main(){
	Node *root=createNode(10);
	root->left=createNode(20);
	root->right=createNode(30);
	root->left->left=createNode(40);
	root->left->right=createNode(50);
	root->left->right->left=createNode(70);
	root->left->right->right=createNode(80);	
	root->right->right=createNode(60);
	printf("\nLIS=%d",lis(root,false));
	printf("\n");
	return 0;
}
