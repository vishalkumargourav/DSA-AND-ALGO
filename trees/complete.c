/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GENERATE COMPLETE BINARY TREE
*/
#include<iostream>
using namespace std;
#include<cstdio>
#include<queue>
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
node *createTree(int *a,int n){
	if(n<=0)
		return NULL;
	queue<node *> q;
	int i;
	node *temp,*temp1;
	node *root=createNode(a[0]);
	q.push(root);
	for(i=1;i<n;i++){
		temp1=createNode(a[i]);
		while(1){
			temp=q.front();
			if(temp->left && temp->right)
				q.pop();
			else{
				if(!temp->left){
					temp->left=temp1;
					q.push(temp1);	
					break;
				}else{
					temp->right=temp1;
					q.push(temp1);	
					break;
				}
			}
		}
	}
	return root;
}
int main(){
	node *root1=NULL;
	int a[]={50,20,90,10,80};
	int n=sizeof(a)/sizeof(a[0]);
	root1=createTree(a,n);
	printf("\nInorder traversal is:");
	inorder(root1);
	printf("\n");
	return 0;
}
