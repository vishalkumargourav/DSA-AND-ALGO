/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE WIDTH OF THE BINARY TREE
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
int maximum(int a,int b){
	return a>b?a:b;
}
int findHeight(node *root){
	if(NULL==root)
		return 0;
	return maximum(findHeight(root->left),findHeight(root->right))+1;
}
void diameterUtil(node *root,int *a,int *max,int i){
	if(NULL==root)
		return;
	a[i]++;
	if(a[i]>*max)
		*max=a[i];
	diameterUtil(root->left,a,max,i+1);
	diameterUtil(root->right,a,max,i+1);
}
int diameter(node *root){
	if(NULL==root)
		return 0;
	int h=findHeight(root);
	int *a=(int*)malloc(sizeof(int)*h);
	int max=INT_MIN;
	memset(a,0,sizeof(int)*h);
	diameterUtil(root,a,&max,0);
	free(a);
	return max;
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\nDiameter of the tree is:%d",diameter(root1));
	printf("\n");
	return 0;
}
