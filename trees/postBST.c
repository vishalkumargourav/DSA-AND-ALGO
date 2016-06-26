/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A BST FROM GIVEN POST ORDER TRAVERSAL
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
node *construct(int *post,int *index,int min,int max,int n){
	if((*index)<0)
		return NULL;
	int key=post[*index];
	node *root=NULL;
	if(key<max && key>min){
		--*index;
		root=createNode(key);
		root->right=construct(post,index,key,max,n);
		root->left=construct(post,index,min,key,n);
	}
	return root;
}
int main(){
	node *root=NULL;
	int post[]={1,7,5,50,40,10};
	int size=sizeof(post)/sizeof(post[0]);
	int index=size-1;
	root=construct(post,&index,INT_MIN,INT_MAX,size);
	printf("\n Inorder traversal of the tree is:");
	inorder(root);
	printf("\n");
	return 0;
}
