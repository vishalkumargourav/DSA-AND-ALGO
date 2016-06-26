/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	DETERMINE IF THE TREE IS HEIGHT BALANCED
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
int maximum(int a,int b,int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}
bool isHeightBalanced(node *root,int *h){
	if(NULL==root){
		*h=0;
		return true;
	}
	int lh,rh;
	lh=rh=0;
	bool left=isHeightBalanced(root->left,&lh);
	bool right=isHeightBalanced(root->right,&rh);
	*h=maximum(lh,rh,INT_MIN)+1;
	return (left&&right&&(abs(lh-rh)<=1));
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={2,1,3};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	int h=0;
	if(isHeightBalanced(root1,&h))
		printf("\nYes the tree is height balanced");
	else
		printf("\nNo the tree is not height balanced!!!!");
	printf("\n");
	return 0;
}
