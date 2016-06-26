/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK WHETHTER THE GIVEN TWO TREES ARE ISOMER
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
bool isIsomer(node *root1,node *root2){
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || NULL==root2)
		return false;
	if(root1->data!=root2->data)
		return false;
	return ((isIsomer(root1->left,root2->left)&&isIsomer(root1->right,root2->right))||(isIsomer(root1->left,root2->right)&&isIsomer(root1->right,root2->left)));
}
int main(){
	node *root1=NULL,*root2=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	root1->left->right->left=createNode(7);
	root1->left->right->right=createNode(8);
	root1->right->left=createNode(6);
	
	root2=createNode(1);
	root2->left=createNode(3);
	root2->left->right=createNode(6);
	root2->right=createNode(2);
	root2->right->left=createNode(4);
	root2->right->right=createNode(5);
	root2->right->right->left=createNode(8);
	root2->right->right->right=createNode(7);
	
	if(isIsomer(root1,root2))
		printf("\nYes the two trees are isomer");
	else
		printf("\nNo the two trees are not isomer");
	printf("\n");
	return 0;
}
