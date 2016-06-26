/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: PAIRWISE SWAP THE ELEMENTS OF A LINKED LIST
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *createNewNode(int data){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	return n;
}
void printList(node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
node *pairwiseSwap(node *head){
	if(NULL==head || head->next==NULL)
		return head;
	node *prev,*curr,*next,*temp;
	curr=head;
	head=curr->next;
	prev=NULL;
	while(curr){
		next=curr->next;
		if(!next)
			break;
		temp=next->next;
		if(prev)
			prev->next=next;
		next->next=curr;
		curr->next=temp;
		prev=curr;
		curr=temp;
	}
	return head;
}
int main(){
	node *head;
	int n;
	head=NULL;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(14);
	head->next->next->next=createNewNode(15);
	head->next->next->next->next=createNewNode(16);
	//head->next->next->next->next->next=createNewNode(17);
	printf("\nLinked list is:");
	printList(head);
	head=pairwiseSwap(head);
	printf("\nLinked list is:");
	printList(head);
	printf("\n");
	return 0;
}
