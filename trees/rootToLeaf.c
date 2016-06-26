/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	DELETE THE TREE
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
node *mirror(node *root){
	if(NULL==root)
		return NULL;
	node *temp;
	root->left=mirror(root->left);
	root->right=mirror(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	return root;
}
int max(int a,int b){
	return a>b?a:b;
}
int height(node *root){
	if(NULL==root)
		return 0;
	return max(height(root->left),height(root->right))+1;
}
void printPath(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void paths(node *root,int *a,int i){
	if(NULL==root)
		return;
	a[i++]=root->data;
	if(root->left==NULL && root->right==NULL)
		printPath(a,i);
	paths(root->left,a,i);
	paths(root->right,a,i);
}
void rootToLeaf(node *root){
	if(NULL==root)
		return;
	int h=height(root);
	int *a=(int*)malloc(sizeof(int)*h);
	paths(root,a,0);
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root1=NULL;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\n");
	rootToLeaf(root1);
	printf("\n");
	return 0;
}
