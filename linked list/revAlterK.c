/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: REVERSE IN GROUPS OF K ALTERNATE
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
node *revInGroups(node *head,int k,bool flag){
	if(NULL==head)
		return NULL;
	int i=0;
	node *curr,*next,*prev;
	curr=head;
	prev=next=NULL;
	if(flag){
		while(i<k && curr){
			i++;
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head->next=revInGroups(next,k,!flag);
		return prev;
	}else{
		node *thead=curr;
		while(i<k && curr){
			prev=curr;
			curr=curr->next;
			i++;
		}
		if(curr)
			prev->next=revInGroups(curr->next,k,!flag);
		return thead;
	}
	
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
	head1=revInGroups(head1,2,true);
	printf("\nLinked lists are:\n");
	printList(head1);
	printf("\n");
	return 0;
}
