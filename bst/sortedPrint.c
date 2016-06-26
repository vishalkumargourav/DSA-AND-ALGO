/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN AN ARRAY THAT REPRESENTS A BST , PRINT IT IN SORTED ORDER
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
void inorder(int *a,int i,int n){
	if(i>=n)
		return;
	inorder(a,i*2+1,n);
	printf("%d ",a[i]);
	inorder(a,i*2+2,n);	
}
int main(){
	int a[]={4,2,5,1,3};
	int n=sizeof(a)/sizeof(a[0]);
	inorder(a,0,n);
	printf("\n");
	return 0;
}
