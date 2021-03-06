/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: CONVERT A SORTED LINKED LIST INTO BALANCED BST
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct tnode{
	int data;
	struct tnode *left,*right;
}tnode;
tnode *createNewTNode(int data){
	tnode *temp;
	temp=(tnode*)malloc(sizeof(tnode));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(tnode *curr){
	if(!curr)
		return;
	inorder(curr->left);
	printf("%d ",curr->data);
	inorder(curr->right);
}
void preorder(tnode *curr){
	if(!curr)
		return;
	printf("%d ",curr->data);
	preorder(curr->left);
	preorder(curr->right);
}
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
int findLength(node *head){
	int i=0;
	while(head){
		i++;
		head=head->next;
	}
	return i;
}
tnode *createBSTUtil(node **head,int len){
	if(len<=0)
		return NULL;
	tnode *left=createBSTUtil(head,len/2);
	tnode *root=createNewTNode((*head)->data);
	*head=(*head)->next;
	root->left=left;
	root->right=createBSTUtil(head,len-len/2-1);
	return root;
}
tnode *createBST(node *head){
	int len=findLength(head);
	printf("\nLength=%d",len);
	return createBSTUtil(&head,len);
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
	tnode *root=createBST(head1);
	printf("\nInorder traversal of the tree is:");
	inorder(root);
	printf("\nPreorder traversal of the tree is:");
	preorder(root);
	printf("\nLinked lists are:\n");
	printList(head1);
	printf("\n");
	return 0;
}
