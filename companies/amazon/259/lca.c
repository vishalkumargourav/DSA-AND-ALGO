/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	LOWEST COMMON ANCESTOR IN A BINARY TREE
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
Node *lcaUtil(Node *root,Node *n1,Node *n2){
	if(NULL==root)
		return NULL;
	if(root==n1||root==n2)
		return root;
	Node *l=lcaUtil(root->left,n1,n2);
	Node *r=lcaUtil(root->right,n1,n2);
	if(l&&r)
		return root;
	if(l)
		return l;
	return r;
}
bool isReachable(Node *root,Node *n){
	if(NULL==root)
		return false;
	if(root==n)
		return true;
	return isReachable(root->left,n)||isReachable(root->right,n);
}
Node *lca(Node *root,Node *n1,Node *n2){
	if(NULL==root)
		return NULL;
	Node *lcanode=lcaUtil(root,n1,n2);
	if(isReachable(lcanode,n1)&&isReachable(lcanode,n2))
		return lcanode;
	return NULL;
}
int main(){
	Node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->left->left->left=createNode(6);
	root->left->left->right=createNode(7);
	root->left->right->right=createNode(8);
	root->right->left=createNode(9);
	root->right->right=createNode(10);
	root->right->right->left=createNode(11);
	//Node *lcanode=lca(root,root->left->left->left,root->left->right->right);
	//Node *lcanode=lca(root,root->left->left->left,root->left->left->right);
	//Node *lcanode=lca(root,root->left->left->left,root->left);
	//Node *lcanode=lca(root,root->left->left,NULL);
	Node *lcanode=lca(root,root->left->left->right,root->right->right->left);
	if(lcanode)
		printf("\nlca is:%d",lcanode->data);
	else
		printf("\nNo lca exsists!!!!");
	printf("\n");
	return 0;
}
