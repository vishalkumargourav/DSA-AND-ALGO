/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE TREE HOLDS THE CHILD SUM PROPERTY
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *left,*right;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
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
bool holdsChildSum(node *root){
	if(NULL==root)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	int left,right;
	left=right=0;
	if(root->left)
		left=root->left->data;
	if(root->right)
		right=root->right->data;
	if(root->data!=(left+right))
		return false;
	return holdsChildSum(root->left)&&holdsChildSum(root->right);
}
int main(){
	node *root1=NULL;
	root1=createNode(10);
	root1->left=createNode(8);
	root1->right=createNode(2);
	root1->left->left=createNode(3);
	root1->left->right=createNode(5);
	root1->right->left=createNode(2);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	if(holdsChildSum(root1))
		printf("\nYes the tree holds the child sum property");
	else
		printf("\nNo the tree doesnt holds child sum property");
	printf("\n");
	return 0;
}
