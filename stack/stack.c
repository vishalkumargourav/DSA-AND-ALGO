/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT STACK
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
typedef struct Stack{
	Node *data;
	struct Stack *next;
}Stack;
Node *createNewNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
Stack *createStackNode(Node *data){
	Stack *temp=(Stack*)malloc(sizeof(Stack));
	temp->data=data;
	temp->next=NULL;
}
void push(Stack **top,Node *data){
	Stack *temp=createStackNode(data);
	if(NULL==*top){
		*top=temp;
		return;
	}
	temp->next=*top;
	*top=temp;
}
bool isEmpty(Stack *top){
	return NULL==top;
}
Node *getTop(Stack *top){
	if(NULL==top)
		return NULL;
	return top->data;
}
void pop(Stack **top){
	if(NULL==*top)
		return;
	Stack *temp=*top;
	*top=(*top)->next;
	free(temp);
}
int main(void){
	Stack *top=NULL;
	Node *temp;
	Node *n[10];
	int i;
	for(i=0;i<10;i++){
		n[i]=createNewNode(i);
		push(&top,n[i]);
	}
	while(!isEmpty(top)){
		temp=getTop(top);
		printf("\nTop is:%d",temp->data);
		pop(&top);
	}
	return 0;
}
