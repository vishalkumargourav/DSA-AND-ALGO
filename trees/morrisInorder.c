/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MORRIS INORDER TRAVERSAL
*/
#include<stdio.h>
#include<stdlib.h>
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
void morris(node *root){
	node *curr,*prev;
	curr=root;
	prev=NULL;
	if(NULL==root)
		return;
	while(curr){
		if(curr->left==NULL){
			printf("%d ",curr->data);
			curr=curr->right;
		}else{
			prev=curr->left;
			while(prev->right!=NULL && prev->right!=curr)
				prev=prev->right;
			if(prev->right==NULL){
				prev->right=curr;
				curr=curr->left;
			}else{
				prev->right=NULL;
				printf("%d ",curr->data);
				curr=curr->right;
			}
		}
	}
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\nInorder traversal of the tree is:");
	morris(root1);
	printf("\n");
	return 0;
}
