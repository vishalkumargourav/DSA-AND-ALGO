/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND SIZE OF TREE
*/
#include<stdio.h>
#include<stdlib.h>
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
int size(node *root){
	if(NULL==root)
		return 0;
	return size(root->left)+size(root->right)+1;
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root=NULL;
	for(i=0;i<n;i++)
		root=insert(root,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nPreoder traversal of the tree is:");
	preorder(root);
	printf("\nPostorder traversal of the tree is:");
	postorder(root);
	printf("\nSize of the tree is:%d",size(root));
	printf("\n");
	return 0;
}
