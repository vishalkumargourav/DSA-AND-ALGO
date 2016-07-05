/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ADD TWO NUMBERS REPRESENTED BY LINKED LISTS
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
int size(Node *head){
	int i=0;
	while(head){
		i++;
		head=head->next;
	}
	return i;
}
void push(Node **head,int data){
	Node *temp=createNode(data);
	temp->next=*head;
	*head=temp;
}
Node *addToLast(Node *head,int data){
	Node *temp=head;
	if(NULL==temp)
		return createNode(data);
	while(temp->next)
		temp=temp->next;
	temp->next=createNode(data);
	return head;
}
void printList(Node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
void swap(Node **head1,Node **head2){
	Node *temp=*head1;
	*head1=*head2;
	*head2=temp;
}
#define TEMP_DATA 0
Node *addSameSize(Node *head1,Node *head2,int *carry){
	if(NULL==head1)
		return NULL;
	int sum;
	Node *result=createNode(TEMP_DATA);
	result->next=addSameSize(head1->next,head2->next,carry);
	sum=head1->data+head2->data+*carry;
	*carry=sum/10;
	sum=sum%10;
	result->data=sum;
	return result;
}
void addCarryToRemaining(Node *head1,Node *curr,int *carry,Node **result){
	int sum;
	if(head1!=curr){
		addCarryToRemaining(head1->next,curr,carry,result);
		sum=head1->data+*carry;
		*carry=sum/10;
		sum%=10;
		push(result,sum);
	}
}
void add(Node *head1,Node *head2,Node **result){
	if(NULL==head1){
		*result=head2;
		return;
	}
	if(NULL==head2){
		*result=head1;
		return;
	}
	int l1=size(head1);
	int l2=size(head2);
	Node *curr;
	int carry=0,i;
	if(l1==l2){
		*result=addSameSize(head1,head2,&carry);
	}else{
		int diff=abs(l1-l2);
		if(l1<l2)
			swap(&head1,&head2);
		for(curr=head1;diff--;curr=curr->next);
		
		*result=addSameSize(curr,head2,&carry);
		
		addCarryToRemaining(head1,curr,&carry,result);
	}
	if(carry)
		push(result,carry);
}
int main(){
	Node *head1,*head2,*result;
	head1=head2=result=NULL;
	int a1[]={9,9,9};
	int a2[]={1,8};
	int n1,n2,i;
	n1=sizeof(a1)/sizeof(a1[0]);
	n2=sizeof(a2)/sizeof(a2[0]);
	for(i=0;i<n1;i++)
		head1=addToLast(head1,a1[i]);
	for(i=0;i<n2;i++)
		head2=addToLast(head2,a2[i]);
	printf("\nList 1 is:");
	printList(head1);
	printf("\nList 2 is:");
	printList(head2);
	add(head1,head2,&result);
	printf("\nResult is:");
	printList(result);
	printf("\n");
	return 0;	
}
