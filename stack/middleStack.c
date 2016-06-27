/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	DESING A STACK DATASTRUCTURE TO GET OPERATIONS ON MIDDLE ELEMENT OF STACK
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int data;
	struct Stack *prev,*next;
}Stack;
Stack *createNode(int data){
	Stack *temp=(Stack*)malloc(sizeof(Stack));
	temp->data=data;
	temp->prev=temp->next=NULL;
	return temp;
}
void push(Stack **top,Stack **middle,int data){
	if(NULL==*top){
		*top=*middle=createNode(data);
		return;
	}
	Stack *temp=createNode(data);
	temp->next=*top;
	(*top)->prev=temp;
	*top=temp;
	*middle=(*middle)->prev;
}
int getTop(Stack **top,Stack **middle){
	if(NULL==top)
		return -1;
	int data=(*top)->data;
	return data;
}
void pop(Stack **top,Stack **middle){
	if(NULL==*top)
		return;
	Stack *temp=*top;
	*top=(*top)->next;
	temp->next=NULL;
	(*top)->prev=NULL;
	*middle=(*middle)->next;
	free(temp);
}
int getMiddle(Stack **top,Stack **middle){
	if(NULL==*top)
		return -1;
	int data=(*middle)->data;
	return data;
}
void deleteMiddle(Stack **top,Stack **middle){
	if(NULL==*top)
		return;
	if((*top)->prev==NULL && (*top)->next==NULL){
		free(*top);
		*top=*middle=NULL;
	}
	Stack *temp=*middle;
	(*middle)->prev->next=(*middle)->next;
	(*middle)->next->prev=(*middle)->prev;
	*middle=(*middle)->next;
	temp->prev=temp->next=NULL;
	free(temp);
}
int main(){
	Stack *top=NULL,*middle=NULL;
	int i;
	for(i=0;i<11;i++){
		push(&top,&middle,i);
		printf("\nTop=%d and middle=%d",top->data,middle->data);	
	}
	return 0;
}
