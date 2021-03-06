/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REMOVE ALL NODES FROM A BINARY TREE THAT DO NOT LIE ON A PATH WITH SUM >= K
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
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
int max(int a,int b){
	return a>b?a:b;
}
node *removeNodes(node *root,int *sum,int k){
	if(NULL==root)
		return NULL;
	int lsum=*sum+root->data;
	int rsum=lsum;
	root->left=removeNodes(root->left,&lsum,k);
	root->right=removeNodes(root->right,&rsum,k);
	*sum=max(lsum,rsum);
	if(*sum<k){
		free(root);
		root=NULL;
	}
	return root;
}

int main(){
	node *root1=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	root1->left->left->left=createNode(8);
	root1->left->left->right=createNode(9);
	root1->left->right->left=createNode(12);
	root1->left->left->right->left=createNode(13);
	root1->left->left->right->right=createNode(14);
	root1->left->left->right->right->left=createNode(15);
	root1->right->left=createNode(6);
	root1->right->right=createNode(7);
	root1->right->right->left=createNode(10);
	root1->right->right->left->right=createNode(11);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	int k=20;
	int sum=0;
	root1=removeNodes(root1,&sum,k);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\n");
	return 0;
}
