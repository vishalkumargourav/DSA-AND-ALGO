/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A SPEICAL BIANRY TREE FROM TWO ARRAYS NODES AND LEAF 
			EVERY NODE CAN EITHER HAVE TWO CHILDREN OR NO CHILDREN DEPENDING 
			ON VALUE STORED IN LEAF
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
node *construct(int *pre,int *index,bool *leaf,int n){
	int ind=*index;
	if((*index)>=n)
		return NULL;
	node *root=createNode(pre[ind]);
	(*index)++;
	if(!leaf[ind]){
		root->left=construct(pre,index,leaf,n);
		root->right=construct(pre,index,leaf,n);
	}
	return root;
}
int main(){
	int pre[]={10,30,20,5,15};
	int n=sizeof(pre)/sizeof(pre[0]);
	bool leaf[]={false,false,true,true,true};
	int index=0;
	node *root=construct(pre,&index,leaf,n);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\n");
	return 0;
}
