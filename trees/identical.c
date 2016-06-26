/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND SIZE OF TREE
*/
#include<stdio.h>
#include<stdlib.h>
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
bool identical(node *root1,node *root2){
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	if(root1->data!=root2->data)
		return false;
	return identical(root1->left,root2->left) && identical(root1->right,root2->right);
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root1=NULL,*root2=NULL;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	for(i=0;i<n;i++)
		root2=insert(root2,a[i]);
	//root1->left->left=createNode(19);
	printf("\nInorder traversals are...\n");
	inorder(root1);
	printf("\n");
	inorder(root2);
	if(identical(root1,root2))
		printf("\nYes the trees are identical");
	else
		printf("\nNo the trees are not identical!!!");
	printf("\n");
	return 0;
}
