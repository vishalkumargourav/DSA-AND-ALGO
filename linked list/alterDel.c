/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: DELETE ALTERNATE NODES OF THE LINKED LIST
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
node *alterDel(node *head){
	if(NULL==head || NULL==head->next)
		return head;
	node *curr,*temp=NULL;
	curr=head;
	while(curr && curr->next){
		temp=curr->next->next;
		free(curr->next);
		curr->next=temp;
		curr=temp;
	}
	return head;
}
node *recursive(node *curr){
	if(NULL==curr || NULL==curr->next)
		return curr;
	node *temp=curr->next->next;
	free(curr->next);
	curr->next=recursive(temp);
	return curr;
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
	printf("\nLinked lists are:\n");
	printList(head1);
	node *head=recursive(head1);
	printf("\nLinked list is:");
	printList(head);
	printf("\n");
	return 0;
}
