/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: GIVEN LINKED LIST REPRESENTS LINES DELETE THE MIDDLE POINTS ON THE LINE
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x,y;
	struct node *next;
}node;
node *createNewNode(int x,int y){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->x=x;
	n->y=y;
	n->next=NULL;
	return n;
}
void printList(node *head){
	while(head){
		printf("(%d,%d)->",head->x,head->y);
		head=head->next;
	}
	printf("NULL");
}
void removeMiddle(node *head){
	if(NULL==head||NULL==head->next||NULL==head->next->next)
		return;
	node *curr,*start,*next;
	curr=head->next;
	start=head;
	node *temp;
	next=curr->next;
	while(next){
		if((start->x==curr->x&&curr->x==next->x)||(start->y==curr->y&&curr->y==next->y)){	//x or y coordinates are same
			temp=curr;
			start->next=next;
			free(temp);
			curr=next;
			next=next->next;
		}else{
			start=curr;
			next=next->next;
			curr=curr->next;
		}
	}
}
int main(){
	node *head;
	int n;
	head=createNewNode(0,10);
	head->next=createNewNode(1,10);
	head->next->next=createNewNode(5,10);
	head->next->next->next=createNewNode(7,10);
	head->next->next->next->next=createNewNode(7,5);
	head->next->next->next->next->next=createNewNode(40,5);
	//head->next->next->next->next->next->next=createNewNode(40,5);
	//1->2->3->4->5->NULL
	printf("\nBefore removing middle elements:");
	printList(head);
	removeMiddle(head);
	printf("\nAfter removing middle elements:");
	printList(head);
	printf("\n");
	return 0;
}
