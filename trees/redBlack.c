/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE GIVEN TREE IS HEIGHT BALANCED LIKE RED BLACK TREE
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
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
bool isRedBlackTree(node *root,int *h_min,int *h_max){
	if(NULL==root){
		*h_min=*h_max=0;
		return true;
	}
	int left_h_min,right_h_min,left_h_max,right_h_max;
	bool isLeft=isRedBlackTree(root->left,&left_h_min,&left_h_max);
	if(!isLeft)
		return false;
	bool isRight=isRedBlackTree(root->right,&right_h_min,&right_h_max);
	if(!isRight)
		return false;
	*h_min=min(left_h_min,right_h_min)+1;
	*h_max=max(left_h_max,right_h_max)+1;
	return ((*h_max)<=2*(*h_min));
}
int main(){
	node *root1=NULL;
	root1=createNode(6);
	//root1->left=createNode(3);
	root1->right=createNode(5);
	//root1->left->left=createNode(2);
	//root1->left->right=createNode(5);
	//root1->left->right->left=createNode(7);
	//root1->left->right->right=createNode(4);
	root1->right->right=createNode(4);
	//root1->right->right->right=createNode(5);
	int h_min=1,h_max=1;
	if(isRedBlackTree(root1,&h_min,&h_max))
		printf("\nYes this tree is red black tree.");
	else
		printf("\nNo this tree is not a red black tree!!!!");
	printf("\n");
	return 0;
}
