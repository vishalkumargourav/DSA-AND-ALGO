/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: PRINT THE REVERSE OF LINKED LIST USING RECURSSION
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
void reversePrint(node *head){
	if(NULL==head){
		printf("NULL<-");
		return;
	}
	reversePrint(head->next);
	printf("%d<-",head->data);
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
	head->next->next->next->next->next=createNewNode(17);
	printf("\nLinked list is:");
	printList(head);
	printf("\nReverse of the linked list is:");
	reversePrint(head);
	printf("\n");
	return 0;
}
