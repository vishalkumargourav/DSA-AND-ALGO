/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: FLATTEN A MULTILEVEL LINKED LIST
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
node *flattenList(node *head){
	if(NULL==head)
		return head;
	node *curr,*temp,*end;
	curr=head;
	end=head;
	while(end->right)
		end=end->right;
	while(curr){
		if(curr->down){
			temp=curr->down;
			while(temp->right)
				temp=temp->right;
			end->right=curr->down;
			curr->down=NULL;
			end=temp;
		}
		curr=curr->right;
	}
	return head;
}
void printList(node *head){
	if(NULL==head)
		return;
	while(head){
		printf("%d ",head->data);
		head=head->right;
	}
}
int main(){
	node *head;
	int n;
	head=createNewNode(10);
	head->down=createNewNode(4);
	head->down->right=createNewNode(20);
	head->down->right->right=createNewNode(13);
	head->down->right->down=createNewNode(2);
	head->down->right->right->down=createNewNode(16);
	head->down->right->right->down->down=createNewNode(3);
	head->right=createNewNode(5);
	head->right->right=createNewNode(12);
	head->right->right->right=createNewNode(7);
	head->right->right->right->down=createNewNode(17);
	head->right->right->right->down->right=createNewNode(6);
	head->right->right->right->down->down=createNewNode(9);
	head->right->right->right->down->down->right=createNewNode(8);
	head->right->right->right->down->down=createNewNode(19);
	head->right->right->right->down->down->right=createNewNode(15);
	head->right->right->right->right=createNewNode(11);
	head=flattenList(head);
	printf("\nFlattend list is:");
	printList(head);
	printf("\n");
	return 0;
}
