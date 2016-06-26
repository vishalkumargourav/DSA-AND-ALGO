/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE BIANARY TREE IS SYMMETRIC THAT IS MIRROR IMAGE OF ITSELF
*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
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
void preorder(node *root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
bool isSymmetricUtil(node *root1,node *root2){
	if(NULL==root1 && root2==NULL)
		return true;
	if(NULL==root1 || NULL==root2)
		return false;
	if(root1->data!=root2->data)
		return false;
	return isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right,root2->left);
}
bool isSymmetric(node *root){
	if(NULL==root)
		return true;
	return isSymmetricUtil(root->left,root->right);
}
int main(){
	node *root;
	root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);
	root->right->right=createNode(3);
	root->right->left=createNode(4);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	if(isSymmetric(root))
		printf("\nYes the given tree is symmetric");
	else
		printf("\nNo the given tree is not symmetric");
	printf("\n");
	return 0;
}
