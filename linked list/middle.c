/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FIND THE MIDDLE OF THE LINKED LIST
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
node *recurGetNthNode(node *head,int n,int i){
	if(i>n)
		return NULL;
	if(i==n)
		return head;
	return recurGetNthNode(head->next,n,i+1);
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
void delete(node **nod){
	//see if it is the end node
	if(NULL==*nod)
		return;
	node *temp=*nod,*temp1;
	if(temp->next==NULL){
		free(temp);
		*nod=NULL;
	}
	//else
	temp->data=temp->next->data;
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
}
void printList(node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
void printMiddle(node *head){
	node *slow,*fast;
	slow=fast=head;
	while(fast){
		fast=fast->next;
		if(fast){
			fast=fast->next;
			slow=slow->next;
		}
	}
	printf("\nMiddle=%d",slow->data);
}
int main(){
	node *head;
	int n;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(13);
	head->next->next->next=createNewNode(14);
	head->next->next->next->next=createNewNode(15);
	//head->next->next->next->next->next=createNewNode(16);
	//1->2->3->4->5->NULL
	printf("\nInitial list is:");
	printList(head);
	printMiddle(head);
	printf("\n");
	return 0;
}
