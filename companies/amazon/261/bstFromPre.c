/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT BST OUT OF PREORDER TRAVERSAL
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *constructNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
Node *constructBst(int *pre,int n,int min,int max){
	static int i=0;
	if(i>=n)
		return NULL;
	if(pre[i]<min||pre[i]>max)
		return NULL;
	Node *temp=constructNode(pre[i++]);
	temp->left=constructBst(pre,n,min,temp->data);
	temp->right=constructBst(pre,n,temp->data,max);
	return temp;
}
void inorder(Node *root){
	if(NULL==root)
		return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
void preorder(Node *root){
	if(root){
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	int pre[]={10,5,2,3,7,6,15,25,20,30};
	int n=sizeof(pre)/sizeof(pre[0]);
	Node *root=constructBst(pre,n,INT_MIN,INT_MAX);
	printf("\nPreorder:");
	preorder(root);
	printf("\nInorder:");
	inorder(root);
	printf("\n");
	return 0;
}
