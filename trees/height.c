/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE HEIGHT OF THE TREE
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
int max(int a,int b){
	return a>b?a:b;
}
int height(node *root){
	if(NULL==root)
		return 0;
	return max(height(root->left),height(root->right))+1;
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root1=NULL;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nHeight of the tree is:%d",height(root1));
	printf("\n");
	return 0;
}
