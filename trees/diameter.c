/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE DIAMETER OF THE BINARY TREE
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
int diameter(node *root,int *h){
	if(NULL==root){
		*h=0;
		return 0;
	}
	int left_height,right_height;
	//left_height=right_height=*h;
	int left_dia,right_dia;
	left_dia=right_dia=0;
	left_dia=diameter(root->left,&left_height);
	right_dia=diameter(root->right,&right_height);
	(*h)=maximum(left_height,right_height,INT_MIN)+1;
	return maximum(left_dia,right_dia,left_height+right_height+1);
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
	int h=0;
	printf("\nDiameter of the tree is:%d",diameter(root1,&h));
	printf("\n");
	return 0;
}
