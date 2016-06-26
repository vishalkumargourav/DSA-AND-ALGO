/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MERGE TWO BALANCED BSTs INTO SINGLE ONE
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
node *findKthSmallest(node *root,int k){
	static int i=0;
	static node *result=NULL;
	if(result)
		return result;
	if(NULL==root)
		return NULL;
	findKthSmallest(root->left,k);
	i++;
	if(i==k)
		result=root;
	findKthSmallest(root->right,k);
	return result;
}

int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int b[]={30,15,45,10,20,40,90,80};
	int m=sizeof(b)/sizeof(b[0]);
	int i;
	node *root1=NULL,*root2=NULL;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	for(i=0;i<m;i++)
		root2=insert(root2,b[i]);
	printf("\nInorder traversal of the trees is:");
	inorder(root1);
	printf("\nInorder traversal of second tree is:");
	inorder(root2);
	printf("\nPreoder traversal of the tree is:");
	preorder(root1);
	printf("\nPreoder traversal of the second tree is:");
	preorder(root2);
	
	printf("\n");
	return 0;
}
