/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: ROTATE A LINKED LIST
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
int findLength(node *head){
	int i=0;
	while(head){
		i++;
		head=head->next;
	}
	return i;
}
node *counterClockWise(node *head,int k){
	int len=findLength(head);
	int i;
	i=0;
	if(k>=len||k<=0)
		return head;
	node *thead,*temp,*curr;
	thead=temp=NULL;
	curr=head;
	while(curr && i<k){
		i++;
		thead=curr;
		curr=curr->next;
	}
	if(curr){
		while(curr->next)
			curr=curr->next;
		temp=thead;
		thead=thead->next;
		temp->next=NULL;
		curr->next=head;
		return thead;
	}
	return head;
}
int main(){
	node *head1;
	int n;
	head1=NULL;
	head1=createNewNode(11);
	head1->next=createNewNode(12);
	head1->next->next=createNewNode(13);
	head1->next->next->next=createNewNode(14);
	head1->next->next->next->next=createNewNode(15);
	head1->next->next->next->next->next=createNewNode(16);
	printf("\nLinked list is:\n");
	printList(head1);
	head1=counterClockWise(head1,5);
	printf("\nLinked list is:\n");
	printList(head1);
	printf("\n");
	return 0;
}
