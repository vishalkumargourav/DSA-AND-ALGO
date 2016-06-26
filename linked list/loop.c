/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FIND WHETHER THE GIVEN LINKED LIST CONTAINS LOOP
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
node *recurDelete(node *head){
	if(NULL==head)
		return NULL;
	head->next=recurDelete(head->next);
	printf("\nDeleted %d",head->data);
	free(head);
	return NULL;
}
node *getNthNode(node *head,int n){
	node *temp;
	temp=head;
	int i=1;
	while(temp){
		if(i==n)
			return  temp;
		temp=temp->next;
		i++;
	}
	return NULL;
}
node *delete(node *nod){
	node *temp;
	while(nod){
		temp=nod;
		printf("\nDeleting %d",temp->data);
		nod=nod->next;
		free(temp);
	}
	return NULL;
}
void printList(node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
node *reverse(node *head){
	node *prev,*curr,*next;
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	prev=NULL;
	curr=head;
	next=head->next;
	while(next){
		curr->next=prev;
		prev=curr;
		curr=next;
		next=next->next;
	}
	curr->next=prev;
	return curr;
}	
void recursive(node *curr,node *prev,node **head){
	if(curr->next==NULL){
		//if it is the last node then update *head
		curr->next=prev;
		*head=curr;
		return;
	}
	node *next=curr->next;
	curr->next=prev;
	recursive(next,curr,head);
}
void recurReverse(node **head){
	if(NULL==*head)
		return;
	recursive(*head,NULL,head);
}
bool containsLoop(node *head){
	node *slow,*fast;
	slow=fast=head;
	while(slow&&fast&&fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			return true;
	}
	return false;
}
int main(){
	node *head;
	int n;
	head=NULL;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(13);
	head->next->next->next=createNewNode(14);
	head->next->next->next->next=head->next;
	//1->2->3->4->5->NULL
	if(containsLoop(head))
		printf("\nYes this list contains the loop!!!!");
	else
		printf("\nNo the given linked list do not contains loop.");
	printf("\n");
	return 0;
}
