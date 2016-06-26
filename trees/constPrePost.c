/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT FULL BINARY TREE OUT OF GIVEN PRE AND POST ORDER TRAVERSAL
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
node *constructUtil(int *pre,int *post,int *index,int l,int h,int n){
	if(*index>=n || l>h || h>=n)
		return NULL;
	node *root=NULL;
	root=createNode(pre[*index]);
	int i;
	++*index;
	for(i=l;i<=h;i++){
		if(post[i]==pre[*index])
			break;
	}
	if(i<=h){
		root->left=constructUtil(pre,post,index,l,i,n);
		root->right=constructUtil(pre,post,index,i+1,h,n);
	}
	return root;
}
node *construct(int *pre,int *post,int n){
	int index=0;
	return constructUtil(pre,post,&index,0,n-1,n);
}
int main(){
	node *root1=NULL;
	int pre[]={1,2,4,8,9,5,3,6,7};
	int post[]={8,9,4,5,2,6,7,3,1};
	int n=sizeof(pre)/sizeof(pre[0]);
	root1=construct(pre,post,n);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	printf("\n");
	return 0;
}
