/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LOWEST COMMON ANCESTOR IN BST
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
node *lcaUtil(node *root,int a,int b){
	if(NULL==root)
		return NULL;
	if((a<root->data && b>root->data) || (a>root->data && b<root->data) || a==root->data || b==root->data)
		return root;
	if(a<root->data&&b<root->data)
		return lcaUtil(root->left,a,b);
	else
		return lcaUtil(root->right,a,b);
}
bool present(node *root,int data){
	if(NULL==root)
		return false;
	if(root->data==data)
		return true;
	return (present(root->left,data)||present(root->right,data));
}
node *lca(node *root,int a,int b){
	if(NULL==root)
		return NULL;
	node *temp=lcaUtil(root,a,b);
	if(present(temp,a)&&present(temp,b))
		return temp;
	return NULL;
}
int main(){
	int a[]={20,8,22,4,12,10,14};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	node *root1=NULL;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	int a1,b;
	a1=8;
	b=23;
	node *temp=lca(root1,a1,b);
	if(temp)
		printf("\nYes the lca is present and it is=%d",temp->data);
	else
		printf("\nNo the lca is not present!!!!!");
	printf("\n");
	return 0;
}
