/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND INORDER SUCCESSOR IN A GIVEN BST
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
node *findSuccessor(node *root,int k){
	static node *prev=NULL;
	static flag=false;
	if(root==NULL)
		return;
	findSuccessor(root->left,k);
	if(prev && !flag){
		flag=true;
		prev=root;
		return prev;
	}
	if(root->data==k)
		prev=root;
	findSuccessor(root->right,k);
	if(flag)
		return prev;
	return NULL;
}
node *findSuccessor2(node *root,int k){
	static node *prev=NULL,*result=NULL;
	if(!root)
		return NULL;
	findSuccessor2(root->left,k);
	if(prev&&!result)
		result=root;
	if(root->data==k)
		prev=root;
	findSuccessor2(root->right,k);
	return result;
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
	int k=4;
	node *suc=findSuccessor2(root,k);
	if(suc)
		printf("\nSuccessor is:%d",suc->data);
	else
		printf("\nNo successor available");
	printf("\n");
	return 0;
}
