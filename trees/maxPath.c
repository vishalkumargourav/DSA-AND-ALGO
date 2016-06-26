/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MAXIMUM PATH SUM IN A BINARY TREE
*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
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
int max(int a,int b){
	return a>b?a:b;
}
int maximumPathUtil(node *root,int *res){
	if(NULL==root)
		return 0;
	int l=maximumPathUtil(root->left,res);
	int r=maximumPathUtil(root->right,res);
	int max_single=max(max(l,r)+root->data,root->data);
	int max_top=max(l+r+root->data,max_single);
	*res=max(*res,max_top);
	return max_single;
}
int maximumPath(node *root){
	if(NULL==root)
		return 0;
	int res=INT_MIN;
	maximumPathUtil(root,&res);
	return res;
}
int main(){
	node *root;
	root=createNode(10);
	root->left=createNode(2);
	root->right=createNode(10);
	root->left->left=createNode(20);
	root->left->right=createNode(1);
	root->right->right=createNode(-25);
	root->right->right->left=createNode(3);
	root->right->right->right=createNode(4);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nMaximum path util is:%d",maximumPath(root));
	printf("\n");
	return 0;
}
