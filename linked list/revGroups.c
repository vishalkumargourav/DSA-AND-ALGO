/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: REVERSE IN GROUPS OF K
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
node *revInGroups(node *head,int k){
	if(k==1 || head==NULL || NULL==head->next)
		return head;
	int i;
	node *curr,*thead,*temp1,*temp2,*prev1,*prev2;
	prev1=NULL;
	prev2=NULL;
	bool flag=false;
	curr=head;
	while(curr){
		thead=curr;
		prev2=NULL;
		temp1=curr;
		for(i=0;i<k && temp1;i++){
			temp2=temp1->next;
			temp1->next=prev2;
			prev2=temp1;
			temp1=temp2;
		}
		if(NULL==prev1){
			head=prev2;
			thead->next=temp1;
		}else{
			prev1->next=prev2;
			thead->next=temp1;
		}
		prev1=thead;
		curr=temp1;
	}
	return head;
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
	head1=revInGroups(head1,2);
	printf("\nLinked lists are:\n");
	printList(head1);
	printf("\n");
	return 0;
}
