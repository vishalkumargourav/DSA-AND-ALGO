/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE TREE INPUTED IS BST OR NOT
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool isBst(node *root){
	static node *prev=NULL;
	if(NULL==root)
		return true;
	if(!isBst(root->left))	
		return false;
	if(prev&&prev->data>=root->data)
		return false;
	prev=root;
	return isBst(root->right);
}
bool isBstUtil(node *root,int min,int max){
	if(NULL==root)
		return true;
	if(!isBstUtil(root->left,min,root->data))
		return false;
	if(root->data<=min || root->data>=max)
		return false;
	if(!isBstUtil(root->right,root->data,max))
		return false;
	return true;
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root=NULL;
	for(i=0;i<n;i++)
		root=insert(root,a[i]);
	root->right->left=createNode(23);
	root->left->left->left=createNode(11);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nPreoder traversal of the tree is:");
	preorder(root);
	printf("\nPostorder traversal of the tree is:");
	postorder(root);
	if(isBstUtil(root,INT_MIN,INT_MAX))
		printf("\nYes the tree is bst");
	else
		printf("\nNo it is not a bst");
	printf("\n");
	return 0;
}
