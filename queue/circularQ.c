/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT CIRCULAR QUEUE
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 100
typedef struct Queue{
	int front,rear;
	int size;
	int *array;
}Queue;
Queue *createQueue(int size){
	Queue *temp=(Queue*)malloc(sizeof(Queue));
	temp->front=temp->size=0;
	temp->rear=SIZE-1;
	temp->array=(int*)malloc(sizeof(int)*size);
	return temp;
}
bool isEmpty(Queue *q){
	return q->size==0;
}
bool isFull(Queue *q){
	return q->size==SIZE;
}
void enqueue(Queue *q,int data){
	if(isFull(q))
		return;
	q->rear=(q->rear+1)%SIZE;
	q->array[q->rear]=data;
	q->size=q->size+1;
}
int dequeue(Queue *q){
	if(isEmpty(q))
		return -1;
	int data=q->array[q->front];
	q->front=(q->front+1)%SIZE;
	q->size=q->size-1;
	return data;
}
int main(){
	Queue *q=createQueue(SIZE);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	
	printf("\n");
	return 0;
}
