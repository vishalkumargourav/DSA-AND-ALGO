/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A SORTED ARRAY CONSTRUCT A BALANCED BST OUT OF IT
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
node *generateTree(int *a,int *i,int n){
	if(n<=0)
		return NULL;
	node *left=generateTree(a,i,n/2);
	node *root=createNode(a[*i]);
	root->left=left;
	*i=(*i)+1;
	root->right=generateTree(a,i,n-n/2-1);
	return root;
}
int main(){
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int i=0;
	node *root=generateTree(a,&i,n);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nPreorder traversal of the tree is:");
	preorder(root);
	printf("\n");
	return 0;
}
