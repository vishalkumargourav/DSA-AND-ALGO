/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: IN PLACE CONVERSION OF SORTED DLL TO BST
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next,*prev;
}node;
node *createNewNode(int data){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=n->prev=NULL;
	return n;
}
void printDLL(node *head){
	node *prev=NULL;
	printf("\nList in forward direction is:");
	while(head){
		prev=head;
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
	printf("\nList in backward direction is:");
	while(prev){
		printf("%d->",prev->data);
		prev=prev->prev;
	}
	printf("NULL");
}
node *insertInDll(node *head,int data){
	if(NULL==head)
		return createNewNode(data);
	node *temp;
	temp=createNewNode(data);
	node *curr=head;
	while(curr->next)
		curr=curr->next;
	curr->next=temp;
	temp->prev=curr;
	return head;
}
int findLength(node *head){
	int i=0;
	while(head){
		head=head->next;
		i++;
	}
	return i;
}
node *sortedToBSTUtil(node **head,int n){
	if(n<=0)
		return NULL;
	node *left=sortedToBSTUtil(head,n/2);
	node *root=*head;
	root->prev=left;
	*head=(*head)->next;
	root->next=sortedToBSTUtil(head,n-n/2-1);
	return root;
}
node *sortedToBST(node *head){
	int len=findLength(head);
	return sortedToBSTUtil(&head,len);
}
void inorder(node *root){
	if(root){
		inorder(root->prev);
		printf("%d ",root->data);
		inorder(root->next);
	}
}
int main(){
	node *head;
	int n;
	head=NULL;
	int i;
	for(i=11;i<=18;i++)
		head=insertInDll(head,i);
	printDLL(head);
	//head=reverseList(head);
	//printDLL(head);
	node *root=sortedToBST(head);
	printf("\nInorder traversal is:");
	inorder(root);
	printf("\n");
	return 0;
}
