/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A TREE FROM GIVEN PARENT ARRAY REPRESENTATION
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
bool isSymmetricUtil(node *root1,node *root2){
	if(NULL==root1 && root2==NULL)
		return true;
	if(NULL==root1 || NULL==root2)
		return false;
	if(root1->data!=root2->data)
		return false;
	return isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right,root2->left);
}
bool isSymmetric(node *root){
	if(NULL==root)
		return true;
	return isSymmetricUtil(root->left,root->right);
}
void constructUtil(int *p,int i,node **root,node **nodes){
	if(nodes[i]!=NULL)
		return;
	nodes[i]=createNode(i);
	if(p[i]==-1){
		*root=nodes[i];
		return;
	}
	if(nodes[p[i]]==NULL)
		constructUtil(p,p[i],root,nodes);
	if(p[i]!=-1){
		if(nodes[p[i]]->left==NULL)
			nodes[p[i]]->left=nodes[i];
		else
			nodes[p[i]]->right=nodes[i];
	}
}
node *construct(int *p,int n){
	int i;
	node *root;
	node **nodes=(node**)malloc(sizeof(node*)*n);
	for(i=0;i<n;i++)
		nodes[i]=NULL;
	for(i=0;i<n;i++)
		constructUtil(p,i,&root,nodes);
	return root;
}
int main(){
	node *root;
	int parent[]={-1,0,0,1,1,3,5};
	int n=sizeof(parent)/sizeof(parent[0]);
	root=construct(parent,n);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\n");
	return 0;
}
