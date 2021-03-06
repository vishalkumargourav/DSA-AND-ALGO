/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	SERIALIZE AND DE-SERIALIZE THE BIANRY TREE
*/
#include<stdlib.h>
#include<stdio.h>
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
node *createTree(int *pre,int *index,int n){
	if(*index>=n)
		return NULL;
	if(pre[*index]==-1){
		(*index)++;
		return NULL;
	}
	node *root=createNode(pre[*index]);
	(*index)++;
	root->left=createTree(pre,index,n);
	root->right=createTree(pre,index,n);
	return root;
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
int main(){
	int pre[]={20,8,4,-1,-1,12,10,-1,-1,14,-1,-1,-1};
	int n=sizeof(pre)/sizeof(pre[0]);
	int index=0;
	node *root=createTree(pre,&index,n);
	printf("\nPreorder traversal of the tree is:");
	preorder(root);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\n");
	return 0;
}
