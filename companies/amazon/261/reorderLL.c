/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REARRANGE A SORTED LINKED LIST SO AS TO GET ALTERNATE INCREASING AND DECRESING ORDER
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
void printList(Node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
Node *findMid(Node *head){
	Node *slow,*fast;
	slow=fast=head;
	while(slow&&slow->next&&fast&&fast->next){
		fast=fast->next->next;
		if(fast)
			slow=slow->next;
	}
	return slow;
}
Node *reverse(Node *head){
	Node *temp1,*temp2,*temp3;
	if(NULL==head || head->next==NULL)
		return;
	temp1=NULL;
	temp2=head;
	temp3=head->next;
	while(temp3){
		temp2->next=temp1;
		temp1=temp2;
		temp2=temp3;
		temp3=temp3->next;
	}
	temp2->next=temp1;
	return temp2;
}
Node *merge(Node *thead1,Node *thead2){
	Node *head=thead1,*temp;
	if(NULL==thead1)
		return thead2;
	if(NULL==thead2)
		return thead1;
	thead1=thead1->next;
	head->next=NULL;
	temp=head;
	while(thead1&&thead2){
		temp->next=thead2;
		thead2=thead2->next;
		temp->next->next=NULL;
		temp=temp->next;
		temp->next=thead1;
		thead1=thead1->next;
		temp=temp->next;
		temp->next=NULL;
	}
	if(thead1)
		temp->next=thead1;
	if(thead2)
		temp->next=thead2;
	return head;
}
Node *reorder(Node *head){
	if(NULL==head || head->next==NULL || head->next->next==NULL)
		return;
	Node *mid=findMid(head);
	printf("mid=%d",mid->data);
	Node *thead1=head;
	Node *thead2=mid->next;
	mid->next=NULL;
	thead2=reverse(thead2);
	printf("\nReversed list is:");
	printList(thead2);
	printf("\nFirst half is:");
	printList(thead1);
	head=merge(thead1,thead2);
	return head;
}
int main(){
	int i,n;
	n=11;
	Node *head=NULL,*temp;
	for(i=n;i>=0;i--){
		temp=createNode(i);
		temp->next=head;
		head=temp;
	}
	printList(head);
	head=reorder(head);
	printList(head);
	printf("\n");
	return 0;
}
