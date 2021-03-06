/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: IMPLEMENT LRU CACHE
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next,*prev;
}node;
typedef struct queue{
	int maxSize,currSize;
	node *front,*rear;
}queue;
typedef struct hash{
	int size;
	node **pages;
}hash;
hash *createHash(int k){		//here k is hash size
	hash *h;
	h=(hash*)malloc(sizeof(hash));
	h->size=k;
	h->pages=(node**)malloc(sizeof(node*)*k);	//<-catch here the double pointer
	int i;
	for(i=0;i<k;i++)
		h->pages[i]=NULL;
	return h;
}
node *createNewNode(int data){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=data;
	n->next=n->prev=NULL;
	return n;
}
queue *createQueue(int k){		//here k is the cache size
	queue *temp;
	temp=(queue*)malloc(sizeof(queue));
	temp->maxSize=k;
	temp->currSize=0;
	temp->front=temp->rear=NULL;
	return temp;
}
void printQueue(queue *q){
	if(NULL==q)
		return;
	node *curr;
	curr=q->front;
	while(curr){
		printf("%d ",curr->data);
		curr=curr->next;
	}
	printf("\n");
}
void insertInQueue(int page,queue *q,hash *h){
	if(h->pages[page]){
		node *temp,*temp2;
		temp=h->pages[page];
		if(temp!=q->front){
			if(temp!=q->rear){
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				temp->prev=NULL;
				temp->next=q->front;
				q->front=temp;
			}else{
				printf("\nyeah this is rear!!!!");
				printf("\n--------------");
				temp2=q->rear->prev;
				temp=q->rear;
				temp2->next=NULL;
				/*temp->next=q->front;
				q->rear=temp2;
				q->front=temp;*/
			}
		}//else do nothing
	}else{
		node *temp=createNewNode(page);
		if(q->maxSize==q->currSize){
			int tpage=q->rear->data;
			temp->next=q->front;
			q->front->prev=temp;
			q->front=temp;
			node *tn=q->rear;
			q->rear=q->rear->prev;
			q->rear->next=NULL;
			free(tn);
			h->pages[tpage]=NULL;
			h->pages[q->front->data]=q->front;
		}else{
			q->currSize++;
			if(NULL==q->front){
				q->front=q->rear=temp;
			}else{
				temp->next=q->front;
				q->front->prev=temp;
				q->front=temp;
			}
		}
	}
}
void printHash(hash *h){
	int n=h->size;
	int i;
	for(i=0;i<n;i++){
		if(h->pages[i])
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
}
int main(){
	int i;
	int pages[]={0,1,2,0,3,4};
	int n=sizeof(pages)/sizeof(pages[0]);
	//pages referred will be 0,1,2,3,4
	hash *h=createHash(5);
	//let the cache size be 4
	queue *q=createQueue(4);
	for(i=0;i<n;i++){
		printf("\nReffering page=%d",pages[i]);
		printf("\n--------------\n");
		insertInQueue(pages[i],q,h);
		printf("\nQueue is:");
		printQueue(q);
		printf("\nHash is:");
		printHash(h);
	}
	printf("\n");
	return 0;
}
