/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: REVERSE A DLL
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
node *reverseList(node *head){
	if(NULL==head)
		return NULL;
	node *curr=head,*prev=NULL,*temp;
	while(curr){
		temp=curr->next;
		curr->next=prev;
		curr->prev=temp;
		prev=curr;
		curr=temp;
	}
	return prev;
}
int main(){
	node *head;
	int n;
	head=NULL;
	int i;
	for(i=11;i<=15;i++)
		head=insertInDll(head,i);
	printDLL(head);
	head=reverseList(head);
	printDLL(head);
	printf("\n");
	return 0;
}
