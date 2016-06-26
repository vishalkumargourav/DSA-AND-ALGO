/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A LINKED LIST COVERT IT TO DLL
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
void setLeftPointers(node *root){
	static node *prev=NULL;
	if(NULL==root)
		return;
	setLeftPointers(root->left);
	if(prev)
		root->left=prev;
	prev=root;
	setLeftPointers(root->right);
}
node *findRightMost(node *root){
	if(NULL==root)
		return NULL;
	while(root->right)
		root=root->right;
	return root;
}
void setRightPointers(node *root){
	node *next=NULL;
	while(root){
		root->right=next;
		next=root;
		root=root->left;
	}
}
node *getLeftMost(node *root){
	if(NULL==root)
		return NULL;
	while(root->left)
		root=root->left;
	return root;
}
void convertToDll(node *root){
	if(NULL==root)
		return;
	setLeftPointers(root);
	node *right=findRightMost(root);
	setRightPointers(right);
}
void printDll(node *root){
	if(NULL==root)
		return;
	printf("\nIn forward direction:");
	while(root->right){
		printf("%d ",root->data);
		root=root->right;
	}
	printf("%d ",root->data);
	printf("\nIn backward direction:");
	while(root){
		printf("%d ",root->data);
		root=root->left;
	}
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	convertToDll(root1);
	root1=getLeftMost(root1);
	printDll(root1);
	printf("\n");
	return 0;
}
