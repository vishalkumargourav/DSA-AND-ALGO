/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE BIANARY TREE IS SYMMETRIC THAT IS MIRROR IMAGE OF ITSELF
*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
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
void preorder(node *root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
bool countSameUtil(node *root,int *count,node *root1){
	if(NULL==root)
		return false;
	if(root->left==NULL && root->right==NULL){
		*count=(*count)+1;
		return true;
	}
	bool left=countSameUtil(root->left,count,root1);
	bool right=countSameUtil(root->right,count,root1);
	if(left && root!=root1){
		if(root->data==root->left->data)
			(*count)=(*count)+1;
	}
	if(right && root!=root1){
		if(root->data==root->right->data)
			(*count)=(*count)+1;
	}
	if(left && right && root!=root1){
		if(root->data==root->left->data && root->left->data==root->right->data )
			(*count)=(*count)+1;	
	}
}
int countSame(node *root){
	int count=0;
	countSameUtil(root,&count,root);
	return count;
}
int main(){
	node *root;
	root=createNode(5);
	root->left=createNode(4);
	root->right=createNode(5);
	root->left->left=createNode(4);
	root->left->right=createNode(4);
	root->right->right=createNode(5);
	int n=countSame(root);
	printf("\nNumber is:%d",n);
	printf("\n");
	return 0;
}









