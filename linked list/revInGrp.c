/*
  AUTHOR  : VISHAL KUMAR GOURAV
  PROBLEM : REVERSE A LINK LIST IN A GROUP  OF K
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
Node *reverse(Node *head,int k){
  if(NULL==head)
    return NULL;
  Node *curr,*prev,*next;
  prev=next=NULL;
  curr=head;
  int i=0;
  while(i<k&&curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    i++;
  }
  head->next=reverse(next,k);
  return prev;
}
void printLink(Node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
int main(){
  Node *head=createNode(1);
  head->next=createNode(2);
  head->next->next=createNode(3);
  head->next->next->next=createNode(4);
  head->next->next->next->next=createNode(5);
  head->next->next->next->next->next=createNode(6);
  head->next->next->next->next->next->next=createNode(7);
  head->next->next->next->next->next->next->next=createNode(8);
  //head->next->next->next->next->next->next->next->next=createNode(9);
  int k=3;
  printf("\nLink list is:");
  printLink(head);
  head=reverse(head,k);
  printf("\nLink list is:");
  printLink(head);
  printf("\n");
  return 0;
}
