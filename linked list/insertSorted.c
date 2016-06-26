/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: INSERT A NODE IN SORTED LINKED LIST
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
node *insertSorted(node *head,node *temp){
	if(NULL==head)
		return temp;
	if(head->data>temp->data){
		temp->next=head;
		return temp;
	}
	node *curr,*prev;
	curr=head;
	prev=NULL;
	while(curr && curr->data<temp->data){
		prev=curr;
		curr=curr->next;
	}
	prev->next=temp;
	temp->next=curr;
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
	//1->2->3->4->5->NULL
	printf("\nLinked list is:");
	printList(head);
	node *temp=createNewNode(17);
	head=insertSorted(head,temp);
	printf("\nLinked list is:");
	printList(head);
	printf("\n");
	return 0;
}
