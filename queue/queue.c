/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT QUEUE
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef struct Queue{
	Node *front,*rear;
	int size;
}Queue;
Queue *createQueue(){
	Queue *temp=(Queue*)malloc(sizeof(Queue));
	temp->size=0;
	temp->front=temp->rear=NULL;
	return temp;
}
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
void enqueue(Queue *q,int data){
	Node *temp=createNode(data);
	if(NULL==q->front){
		q->front=q->rear=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
}
void dequeue(Queue *q){
	if(q->front==NULL)
		return ;
	Node *temp=q->front;
	q->front=q->front->next;
	if(NULL==q->front)
		q->rear=NULL;
	free(temp);
}
int getFront(Queue *q){
	if(NULL==q->front)
		return -1;
	int data=q->front->data;
	return data;
}
void printQueue(Queue *q){
	Node *temp=q->front;
	while(temp){
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int i;
	Queue *q=createQueue();
	for(i=0;i<10;i++)
		enqueue(q,i);
	printf("\nQueue is:");
	printQueue(q);
	while(q->front){
		printf("\nFront is:%d",getFront(q));
		dequeue(q);
	}
	printf("\n");
	return 0;
}
