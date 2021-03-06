/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ITERATIVE POST ORDER TRAVERSAL
*/
#include<iostream>
using namespace std;
#include<cstdio>
#include<stack>
#include<cstdlib>
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
void iterPost(node *root){
	stack<node *> s1,s2;
	s1.push(root);
	node *temp;
	while(!s1.empty()){
		temp=s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}
	while(!s2.empty()){
		temp=s2.top();
		s2.pop();
		printf("%d ",temp->data);
	}
}
int main(){
	node *root1=NULL;
	int a[]={50,20,90,10,80};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal is:");
	inorder(root1);
	printf("\nPostorder traversal is:");
	postorder(root1);
	printf("\nPostorder traversal is:");
	iterPost(root1);
	printf("\n");
	return 0;
}
