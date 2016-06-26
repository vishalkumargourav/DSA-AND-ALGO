/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	POPULATE INORDER SUCCESSOR OF EVERY NODE
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
void populateInorder(node *root){
	if(NULL==root)
		return;
	static node *prev=NULL;
	populateInorder(root->left);
	if(NULL!=prev)
		prev->inOrder=root;
	prev=root;
	populateInorder(root->right);
}
void populateInorderP(node *root,node **prev){
	if(NULL==root)
		return;
	populateInorderP(root->left,prev);
	if(*prev)
		(*prev)->inOrder=root;
	*prev=root;
	populateInorderP(root->right,prev);
}
node *getLeftMost(node *root){
	if(NULL==root)
		return NULL;
	while(root->left)
		root=root->left;
	return root;
}
void printInorder(node *root){
	if(NULL==root)
		return;
	printf("%d ",root->data);
	printInorder(root->inOrder);
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	node *prev=NULL;
	populateInorderP(root1,&prev);
	printf("\nInorder traversal of the tree is:");
	node *root=root=getLeftMost(root1);
	printInorder(root);
	printf("\n");
	return 0;
}
