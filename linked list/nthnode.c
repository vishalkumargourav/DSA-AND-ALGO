/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FIND NTH NODE IN LINKED LIST
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
int main(){
	node *head;
	int n;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(13);
	head->next->next->next=createNewNode(14);
	head->next->next->next->next=createNewNode(15);
	//1->2->3->4->5->NULL
	printf("\nEnter the value of n:");
	scanf("%d",&n);
	node *temp=recurGetNthNode(head,n,1);
	if(NULL==temp){
		printf("\n%dth node is not present in the linked list!!!!",n);
	}else{
		printf("\nValue of %dth node of linked list is:%d",n,temp->data);
	}
	printf("\n");
	return 0;
}
