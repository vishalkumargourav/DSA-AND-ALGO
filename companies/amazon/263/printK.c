/*
	AUTHOR 	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT NODES AT DIST k FROM A GIVEN NODE
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void printKDistDown(Node *root,int k){
	if(NULL==root)
		return;
	if(k<0)
		return;
	if(k==0)
		printf("%d\n",root->data);
	printKDistDown(root->left,k-1);
	printKDistDown(root->right,k-1);
}
int printK(Node *root,Node *target,int k){
	if(NULL==root)
		return -1;
	if(root==target){
		printKDistDown(root,k);
		return 0;
	}
	int dl=printK(root->left,target,k);
	if(dl!=-1){
		if(dl+1==k)
			printf("%d\n",root->data);
		else
			printKDistDown(root->right,k-dl-2);
		return 1+dl;
	}
	int dr=printK(root->right,target,k);
	if(dr!=-1){
		if(dl+1==k)
			printf("%d\n",root->data);
		else
			printKDistDown(root->left,k-dr-2);
		return 1+dr;
	}
	return -1;
}
int main(){
	Node *root=createNode(20);
	root->left=createNode(8);
	root->right=createNode(22);
	root->left->left=createNode(4);
	root->left->right=createNode(12);
	root->left->right->left=createNode(10);
	root->left->right->right=createNode(14);
	Node *target=root->left->right;
	printK(root,target,2);
	printf("\n");
	return 0;
}
