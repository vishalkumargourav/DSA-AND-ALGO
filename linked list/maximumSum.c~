/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FIND MAXIMUM SUM LINKED LIST FROM TWO GIVEN LINKED LISTS
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
node *intersection(node *head1,node *head2){
	if(NULL==head1 || NULL==head2)
		return NULL;
	node *head=NULL,*prev=NULL;
	int p=-1;
	node *curr1=head1,*curr2=head2,*temp=NULL;
	while(curr1 && curr2){
		if(curr1->data==curr2->data){
			if(curr1->data!=p){
				p=curr1->data;
				temp=createNewNode(p);
				if(NULL==head)
					head=temp;
				else
					prev->next=temp;
				prev=temp;
			}
			curr1=curr1->next;
			curr2=curr2->next;
		}else{
			if(curr1->data<curr2->data)
				curr1=curr1->next;
			else
				curr2=curr2->next;
		}
	}
	return head;
}
node *recursive(node *curr1,node *curr2,int prev){
	if(NULL==curr1 || NULL==curr2)
		return NULL;
	if(curr1->data<curr2->data)
		return recursive(curr1->next,curr2,prev);
	if(curr2->data<curr1->data)
		return recursive(curr1,curr2->next,prev);
	if(prev!=curr1->data){
		node *temp=createNewNode(curr1->data);
		temp->next=recursive(curr1->next,curr2->next,temp->data);
		return temp;
	}else
		return recursive(curr1->next,curr2->next,prev);
}
node *maximumSum(node *head1,node *head2){
	node *curr1,*curr2;
	curr1=head1;
	curr2=head2;
	int sum1,sum2;
	sum1=sum2=0;
	node *head3=NULL;
	if(head1==NULL)	
		return head2;
	if(NULL==head2)
		return head1;
	while(curr1 && curr2 && curr1->data!=curr2->data){
		if(curr1->data<curr2->data){
			sum1+=curr1->data;
			curr1=curr1->next;
		}else{
			sum2+=curr2->data;
			curr2=curr2->next;
		}
	}
	
	if(curr1&&curr2){
		sum1+=curr1->data;
		sum2+=curr2->data;
		if(sum1>=sum2){
			head3=head1;
			curr1->next=maximumSum(curr1->next,curr2->next);
		}else{
			head3=head2;
			curr2->next=maximumSum(curr1->next,curr2->next);
		}
	}else{
		//one of them is over
		while(curr1 || curr2){
			if(curr1){
				sum1+=curr1->data;
				curr1=curr1->next;
			}else{
				sum2+=curr2->data;
				curr2=curr2->next;
			}
		}
		if(sum1>=sum2)
			head3=head1;
		else
			head3=head2;
	}
	return head3;
}
int main(){
	node *head1,*head2;
	int n;
	
	head1=NULL;
	head1=createNewNode(1);
	head1->next=createNewNode(3);
	head1->next->next=createNewNode(30);
	head1->next->next->next=createNewNode(90);
	head1->next->next->next->next=createNewNode(110);
	head1->next->next->next->next->next=createNewNode(120);
	
	head2=NULL;
	head2=createNewNode(0);
	head2->next=createNewNode(3);
	head2->next->next=createNewNode(12);
	head2->next->next->next=createNewNode(32);
	head2->next->next->next->next=createNewNode(90);
	head2->next->next->next->next->next=createNewNode(100);
	head2->next->next->next->next->next->next=createNewNode(120);
	head2->next->next->next->next->next->next->next=createNewNode(130);
	
	printf("\nLinked lists are:\n");
	printList(head1);
	printf("\n");
	printList(head2);
	node *head=maximumSum(head1,head2);
	printf("\nMaximum sum linked list is:");
	printList(head);
	printf("\n");
	return 0;
}
