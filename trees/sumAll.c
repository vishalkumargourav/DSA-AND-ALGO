/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	SUM OF ALL THE NUMBERS THAT ARE FORMED FROM ROOT TO LEAVES
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
void sumAll(node *root,int *sum,int tSum){
	if(NULL==root)
		return;
	tSum+=root->data;
	if(root->left==NULL && root->right==NULL){
		printf("\nAdding:%d",tSum);
		*sum=(*sum)+tSum;
		return;
	}
	sumAll(root->left,sum,tSum*10);
	sumAll(root->right,sum,tSum*10);
}
int main(){
	node *root1=NULL;
	root1=createNode(6);
	root1->left=createNode(3);
	root1->right=createNode(5);
	root1->left->left=createNode(2);
	root1->left->right=createNode(5);
	//root1->left->left->left=createNode(8);
	//root1->left->left->right=createNode(9);
	//root1->left->right->left=createNode(12);
	//root1->left->left->right->left=createNode(13);
	//root1->left->left->right->right=createNode(14);
	//root1->left->left->right->right->left=createNode(15);
	root1->left->right->left=createNode(7);
	root1->left->right->right=createNode(4);
	root1->right->right=createNode(4);
	int sum=0;
	sumAll(root1,&sum,0);
	printf("\nsum=%d",sum);
	printf("\n");
	return 0;
}
