/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: COPY A LINKED LIST WITH RANDOM POINTERS
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next,*rand;
}node;
node *createNewNode(int data){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=n->rand=NULL;
	return n;
}
void printList(node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
void printRandoms(node *head){
	while(head){
		printf("\n%d---rand---->%d",head->data,head->rand->data);
		head=head->next;
	}
}
node *copyList(node *head){
	//first make a new list
	node *head1,*prev,*curr,*cPrev,*temp;
	head1=NULL;
	prev=NULL;
	curr=head;
	while(curr){
		temp=createNewNode(curr->data);
		temp->rand=curr;
		if(NULL==prev)
			head1=temp;
		else
			prev->next=temp;
		prev=temp;
		cPrev=curr;
		curr=curr->next;
		cPrev->next=temp;
	}
	//start the second phase
	curr=head1;
	while(curr){
		curr->rand=curr->rand->rand->next;
		curr=curr->next;
	}
	return head1;
}
int main(){
	node *head;
	int n;
	head=NULL;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(13);
	head->next->next->next=createNewNode(14);
	head->next->next->next->next=createNewNode(15);
	//setting the random pointers
	head->rand=head->next->next;
	head->next->rand=head;
	head->rand->rand=head->next->next->next->next;
	head->next->next->next->rand=head->next->next;
	head->rand->rand->rand=head->next;
	//1->2->3->4->5->NULL
	printf("\nLinked list is:");
	printList(head);
	printf("\nRandom pointers are...\n");
	printRandoms(head);
	node *cHead=copyList(head);
	printf("\nNew linked list is:");
	printList(cHead);
	printf("\nRandom pointers are...\n");
	printRandoms(cHead);
	printf("\n");
	return 0;
}
