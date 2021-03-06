/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: REMOVE DUPLICATES FROM THE UNSORTED LINKED LIST
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
node *removeDuplicates(node *head){
	if(NULL==head)
		return NULL;
	node *curr,*prev,*next,*temp;
	curr=head;
	prev=NULL;
	while(curr){
		prev=curr;
		next=curr->next;
		while(next){
			if(next->data==curr->data){
				temp=next;
				prev->next=temp->next;
				next=next->next;
				free(temp);
			}else{
				next=next->next;
			}
		}
		curr=curr->next;
	}
	return head;
}
int main(){
	node *head;
	int n;
	head=NULL;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(11);
	head->next->next->next=createNewNode(12);
	head->next->next->next->next=createNewNode(12);
	head->next->next->next->next->next=createNewNode(13);
	printf("\nLinked list is:");
	printList(head);
	head=removeDuplicates(head);
	printf("\nLinked list is:");
	printList(head);
	printf("\n");
	return 0;
}
