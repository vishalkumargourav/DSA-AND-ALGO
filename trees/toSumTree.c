/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONVERT A GIVEN TREE TO SUM TREE
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *left,*right,*inOrder;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=temp->inOrder=NULL;
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
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(node *root){
	if(NULL==root)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int toSumTree(node *root){
	if(NULL==root)
		return 0;
	int left,right,prev;
	left=toSumTree(root->left);
	right=toSumTree(root->right);
	prev=root->data;
	root->data=left+right;
	return left+right+prev;
}
int main(){
	node *root1=NULL;
	root1=createNode(10);
	root1->left=createNode(-2);
	root1->right=createNode(6);
	root1->right->left=createNode(7);
	root1->right->right=createNode(5);
	root1->left->left=createNode(8);
	root1->left->right=createNode(-4);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	toSumTree(root1);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\n");
	return 0;
}
