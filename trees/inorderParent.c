/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	DO INORDER TRAVERSAL OF BINARY TREE WITH PARENT POINTERS
*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *left,*right,*parent;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=temp->parent=NULL;
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
void inorderParent(node *root){
	bool leftdone=false;
	while(root){
		if(!leftdone){
			while(root->left)
				root=root->left;
		}
		leftdone=true;
		printf("%d ",root->data);
		if(root->right){
			root=root->right;
			leftdone=false;
		}else if(root->parent){
			while(root->parent && root==root->parent->right)
				root=root->parent;
			if(!root->parent)
				break;
			root=root->parent;
		}else 
			break;
	}
}
int main(){
	node *root;
	root=createNode(1);
	root->left=createNode(2);
	root->left->parent=root;
	root->right=createNode(2);
	root->right->parent=root;
	root->left->left=createNode(3);
	root->left->left->parent=root->left;
	root->left->right=createNode(4);
	root->left->right->parent=root->left;
	root->right->right=createNode(3);
	root->right->right->parent=root->right;
	root->right->left=createNode(4);
	root->right->left->parent=root->right;
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nInorder traversal is:");
	inorderParent(root);
	printf("\n");
	return 0;
}
