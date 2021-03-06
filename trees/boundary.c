/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	BOUNDARY ORDER TRAVERSAL OF THE TREE
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
void printLeftView(node *root,int l){
	static int max=INT_MIN;
	if(NULL==root || (root->left==NULL && root->right==NULL)){
		if(root){
			if(l>max)
				max=l;
		}
		return;
	}
	if(l>max){
		printf("%d ",root->data);
		max=l;
	}
	printLeftView(root->left,l+1);
	printLeftView(root->right,l+1);
}
void printLeaves(node *root){
	if(NULL==root)
		return;
	if(root->left==NULL && root->right==NULL)
		printf("%d ",root->data);
	printLeaves(root->left);
	printLeaves(root->right);
}
int max(int a,int b){
	return a>b?a:b;
}
int height(node *root){
	if(NULL==root)
		return 0;
	return max(height(root->left),height(root->right))+1;
}
void setArray(int *a,node *root,int *len,int i){
	if(NULL==root || (root->left==0 && root->right==NULL))
		return;
	setArray(a,root->left,len,i+1);
	a[i]=root->data;
	if(i>(*len))
		*len=i;
	setArray(a,root->right,len,i+1);
}
void printReverse(int *a,int len){
	int i;
	for(i=len;i>0;i--)
		printf("%d ",a[i]);
}
void printRightView(node *root){
	int h=height(root);
	int *a=(int*)malloc(sizeof(int)*h);
	int len=0;
	memset(a,0,sizeof(int)*h);
	setArray(a,root,&len,0);
	printReverse(a,len);
}
void boundaryTraversal(node *root){
	if(NULL==root)
		return;
	//printLeftView(root,0);
	//printLeaves(root);
	printRightView(root);
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={50,20,90,10,80,100,5,15,60,85,4,6,12,18,17,19};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\nBoundary order traversal of the treee is:");
	boundaryTraversal(root1);
	printf("\n");
	return 0;
}
