/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAXIMUM DIFFERENCE B/W A NODE AND ITS ANCESTOR
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
void inorder(Node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int maximum(int a,int b){
	return a>b?a:b;
}
void maxDiffUtil(Node *root,int max,int *dif){
	if(NULL==root)
		return;
	if(max-root->data>*dif)
		*dif=max-root->data;
	maxDiffUtil(root->left,maximum(max,root->data),dif);
	maxDiffUtil(root->right,maximum(max,root->data),dif);
}
int maxDiff(Node *root){
	int max=root->data;
	int dif=INT_MIN;
	maxDiffUtil(root->left,root->data,&dif);
	maxDiffUtil(root->right,root->data,&dif);
	return dif;
}
int main(){
	Node *root=createNode(8);
	root->left=createNode(3);
	root->right=createNode(10);
	root->left->left=createNode(1);
	root->left->right=createNode(6);
	root->left->right->left=createNode(4);
	root->left->right->right=createNode(7);
	root->right->right=createNode(14);
	root->right->right->left=createNode(13);
	printf("\nINORDER:");
	inorder(root);
	printf("\nMaximum difference is:%d",maxDiff(root));
	printf("\n");
	return 0;
}
