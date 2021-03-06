/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FIND WHETHER THE GIVEN LINKED LIST IS PALINDROME
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
void recursive(node *curr,node *prev,node **head){
	if(curr->next==NULL){
		*head=curr;
		curr->next=prev;
		return;
	}
	node *next=curr->next;
	curr->next=prev;
	recursive(next,curr,head);
}
void reverse(node **head){
	if(NULL==*head)
		return;
	recursive(*head,NULL,head);
}
int findLength(node *head){
	int i=0;
	while(head){
		i++;
		head=head->next;
	}
	return i;
}
bool isSame(node *head1,node *head2){
	while(head1&&head2){
		if(head1->data!=head2->data)
			return false;
		head1=head1->next;
		head2=head2->next;
	}
	if(head1 || head2)
		return false;
}
bool isPalin(node *head){
	if(NULL==head)
		return true;
	if(head->next==NULL)
		return true;
	int length=findLength(head);
	if(length%2==0){
		//even length
		node *head1,*head2;
		head1=head;
		int i;
		int flag=0;
		for(i=0;i<length/2-1;i++)
			head1=head1->next;
		head2=head1->next;
		reverse(&head2);
		if(isSame(head1,head2))
			flag=0;
		else
			flag=1;
		reverse(&head2);
		head1->next=head2;
		if(flag==0){
			return true;
		}else{
			return false;
		}
	}else{
		//odd length
		node *mid,*head1,*head2;
		head1=head;
		int i,flag=0;
		for(i=0;i<length/2-1;i++)
			head1=head1->next;
		mid=head1->next;
		head2=mid->next;
		reverse(&head2);
		if(isSame(head1,head2))
			flag=0;
		else
			flag=1;
		reverse(&head2);
		mid->next=head2;
		head1->next=mid;
		if(flag==0){
			return true;
		}else{
			return false;
		}
	}
}
bool recurPalin(node **left,node *right){
	if(NULL==right)
		return true;
	bool isp1=recurPalin(left,right->next);
	if(isp1==false)
		return false;
	bool isp2=((*left)->data==right->data);
	*left=(*left)->next;
	return isp2;
}
int main(){
	node *head;
	int n;
	head=NULL;
	head=createNewNode(11);
	head->next=createNewNode(12);
	head->next->next=createNewNode(12);
	head->next->next->next=createNewNode(11);
//	head->next->next->next->next=createNewNode(15);
	//1->2->3->4->5->NULL
	printf("\nLinked list is:");
	printList(head);
	reverse(&head);
	printf("\nLinked list is:");
	printList(head);
	int l=findLength(head);
	printf("\nLength=%d",l);
	if(recurPalin(&head,head)){
		printf("\nYes the given linked list is a plindrome.");
	}else
		printf("\nNo this list is not a palindrome.");
	printf("\n");
	return 0;
}
