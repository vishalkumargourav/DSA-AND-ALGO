/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT THREADED TREE FROM GIVEN BINARY TREE
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
	int data;
	bool threaded;
	struct node *left,*right;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->threaded=false;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node *root,int data){
	if(NULL==root)
		return createNode(data);
	if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void inorder(node *root){
	if(NULL==root)
		return;
	inorder(root->left);
	if(root->threaded)
		printf("%d(1) ",root->data);
	else
		printf("%d(0) ",root->data);
	inorder(root->right);
}
void preorder(node *root){
	if(NULL==root)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void toThreaded(node *root){
	static node *prev=NULL;
	if(NULL==root)
		return;
	toThreaded(root->left);
	if(prev){
		if(prev->right==NULL){
			prev->threaded=true;
			prev->right=root;
		}
	}
	prev=root;
	toThreaded(root->right);
}
node *getLeftMost(node *root){
	if(NULL==root)
		return NULL;
	while(root->left)
		root=root->left;
	return root;
}
void inOrder(node *root){
	if(NULL==root)
		return;
	root=getLeftMost(root);
	while(root){
		if(root->threaded)
			printf("%d(1) ",root->data);
		else
			printf("%d(0) ",root->data);
		if(root->threaded)
			root=root->right;
		else
			root=getLeftMost(root->right);
	}
}
int main(){
	node *root1=NULL,*root2=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	root1->left->right->left=createNode(7);
	root1->left->right->right=createNode(8);
	root1->right->left=createNode(6);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	toThreaded(root1);
	printf("\nInorder traversal of the tree is:");
	inOrder(root1);
	printf("\n");
	return 0;
}
