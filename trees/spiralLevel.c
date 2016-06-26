/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	SPIRAL LEVEL ORDER TRAVERSAL IN TREE
*/
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<stack>
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
void printSpiral(node *root){
	if(NULL==root)
		return;
	stack<node*> s1,s2;
	node *temp;
	s1.push(root);
	while(!s1.empty()||!s2.empty()){
		while(!s1.empty()){
			temp=s1.top();
			s1.pop();
			printf("%d ",temp->data);
			if(temp->left)
				s2.push(temp->left);
			if(temp->right)
				s2.push(temp->right);
		}
		while(!s2.empty()){
			temp=s2.top();
			s2.pop();
			printf("%d ",temp->data);
			if(temp->right)
				s1.push(temp->right);
			if(temp->left)
				s1.push(temp->left);
		}
	}
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
	printf("\nSpiral order traversal of the tree is:");
	printSpiral(root1);
	printf("\n");
	return 0;
}
