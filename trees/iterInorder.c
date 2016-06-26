/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ITERATIVE INORDER TRAVERSAL OF THE TREE
*/
#include<iostream>
using namespace std;
#include<cstdio>
#include<stack>
#include<cstdlib>
#include<climits>
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
void inorderIter(node *root){
	if(NULL==root)
		return;
	stack<node *> s;
	node *temp=root;
	while(!s.empty()||temp){
		while(temp){
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		printf("%d ",temp->data);
		if(temp->right)
			temp=temp->right;
		else
			temp=NULL;
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
	printf("\nIterative inorder traversal of the tree is:");
	inorderIter(root1);
	return 0;
}
