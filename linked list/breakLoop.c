/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: GIVEN A LINKED LIST DETECT AND BREAK THAT LOOP
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
node *containsLoop(node *head){
	node *slow,*fast;
	slow=fast=head;
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			return slow;
	}
	return NULL;
}
int loopLength(node *head,node *n){
	int len=1;
	node *temp=n;
	while(temp->next!=n){
		len++;
		temp=temp->next;
	}
	return len;
}
void breakLoop(node *head,int len){
	node *prev=NULL,*ahead,*behind;
	int i;
	ahead=behind=head;
	for(i=0;i<len;i++)
		ahead=ahead->next;
	while(ahead!=behind){
		prev=ahead;
		ahead=ahead->next;
		behind=behind->next;
	}
	prev->next=NULL;
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
	//making a loop
	//head->next->next->next->next->next->next=head->next->next;
	head->next->next->next->next->next->next=head->next->next->next->next->next;
	//1->2->3->4->5->NULL
	int len;
	node *temp=NULL;
	temp=containsLoop(head);
	if(temp){
		printf("\nThe linked list contains the loop");
		len=loopLength(head,temp);
		printf("\nLoop length is:%d",len);
		if(len==1)
			temp->next=NULL;
		else
			breakLoop(head,len);
	}else
		printf("\nThe linked list does not contain any loop");
	printf("\nLinked list is:");
	printList(head);
	printf("\n");
	return 0;
}
