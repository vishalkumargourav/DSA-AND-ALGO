/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONVERT A BINARY TREE TO A TREE THAT HOLDS CHILD SUM PROPERTY
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
void increment(node *root,int diff){
	if(NULL==root||(root->left==NULL && root->right==NULL))
		return;
	if(root->left){
		root->left->data+=diff;
		increment(root->left,diff);
	}else if(root->right){
		root->right->data+=diff;
		increment(root->right,diff);
	}
}
void convert(node *root){
	if(NULL==root || (root->left==NULL && root->right==NULL))
		return;
	int left,right;
	convert(root->left);
	convert(root->right);
	left=right=0;
	if(root->left)
		left=root->left->data;
	if(root->right)
		right=root->right->data;
	int diff=root->data-(left+right);
	if(diff!=0){
		if(diff<0)
			root->data-=diff;
		else
			increment(root,diff);
	}
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,45,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	convert(root1);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\n");
	return 0;
}
