/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FLATTEN A SORTED LINKED LIST
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *right,*down;
}node;
node *createNewNode(int data){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=data;
	n->right=n->down=NULL;
	return n;
}
node *merge(node *head1,node *head2){
	if(NULL==head1)
		return head2;
	if(NULL==head2)
		return head1;
	node *curr;
	if(head1->data<head2->data){
		curr=head1;
		curr->down=merge(head1->down,head2);
	}else{
		curr=head2;
		curr->down=merge(head1,head2->down);
	}
	return curr;
}
node *flattenList(node *head){
	if(NULL==head || head->right==NULL)
		return head;
	return merge(head,flattenList(head->right));
}
void printList(node *head){
	if(NULL==head)
		return;
	while(head){
		printf("%d ",head->data);
		head=head->down;
	}
}
int main(){
	node *head;
	int n;
	head=createNewNode(5);
	head->down=createNewNode(7);
	head->down->down=createNewNode(8);
	head->down->down->down=createNewNode(30);
	head->right=createNewNode(10);
	head->right->down=createNewNode(20);
	head->right->right=createNewNode(19);
	head->right->right->down=createNewNode(22);
	head->right->right->down->down=createNewNode(50);
	head->right->right->right=createNewNode(28);
	head->right->right->right->down=createNewNode(35);
	head->right->right->right->down->down=createNewNode(40);
	head->right->right->right->down->down->down=createNewNode(45);
	head=flattenList(head);
	printf("\nFlattend list is:");
	printList(head);
	printf("\n");
	return 0;
}
