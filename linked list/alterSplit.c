/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: SPLIT THE LIST ALTERNATIVELY IN TWO SEPERATE LINKED LISTS
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
void alterSplit(node *head,node **head1,node **head2){
	if(NULL==head || head->next==NULL){
		*head1=head;
		return;
	}
	node *temp,*prev1,*prev2;
	prev1=prev2=NULL;
	int i=0;
	while(head){
		if(i%2==0){
			temp=head;
			head=head->next;
			temp->next=NULL;
			if(!*head1){
				*head1=temp;
				prev1=temp;
			}else{
				prev1->next=temp;
				prev1=temp;
			}
		}else{
			temp=head;
			head=head->next;
			temp->next=NULL;
			if(!*head2){
				*head2=temp;
				prev2=temp;
			}else{
				prev2->next=temp;
				prev2=temp;
			}
		}
		i++;
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
	//head1->next->next->next->next->next=createNewNode(16);
	printf("\nLinked lists are:\n");
	printList(head1);
	node *head2,*head3;
	head2=head3=NULL;
	alterSplit(head1,&head2,&head3);
	printf("\nFirst list is:");
	printList(head2);
	printf("\nSecond list is:");
	printList(head3);	
	printf("\n");
	return 0;
}
