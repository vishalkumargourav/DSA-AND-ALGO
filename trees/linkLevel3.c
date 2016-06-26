/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONNECT NODES AT SAME LEVEL
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *left,*right,*next;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=temp->next=NULL;
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
node *getNext(node *root){
	if(NULL==root)
		return NULL;
	node *temp=root->next;
	while(temp){
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;
		temp=temp->next;
	}
	return NULL;
}
void connectLevel(node *root){
	if(NULL==root)
		return;
	if(root->next)
		connectLevel(root->next);
	if(root->left){
		if(root->right){
			root->left->next=root->right;
			root->right->next=getNext(root);
		}else
			root->left->next=getNext(root);
		connectLevel(root->left);
	}else if(root->right){
		root->right->next=getNext(root);
		connectLevel(root->right);
	}else
		connectLevel(getNext(root));
}
void printLevelWise(node *root,int i){
	static int max=INT_MIN;
	node *temp;
	if(NULL==root)
		return;
	if(i>max){
		max=i;
		temp=root;
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printLevelWise(root->left,i+1);
	printLevelWise(root->right,i+1);
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
	int h=0;
	connectLevel(root1);
	printf("\nLevel wise traversal is:");
	printLevelWise(root1,0);
	printf("\n");
	return 0;
}
