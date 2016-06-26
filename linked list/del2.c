/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: DELETE COMPLETE LINKED LIST
*/
#include<stdio.h>
#include<stdlib.h>
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
int main(){
	node *head;
	int n;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(13);
	head->next->next->next=createNewNode(14);
	head->next->next->next->next=createNewNode(15);
	//1->2->3->4->5->NULL
	printf("\nInitial list is:");
	printList(head);
	head=recurDelete(head);
	printf("\nList after deletion is:");
	printList(head);
	printf("\n");
	return 0;
}
