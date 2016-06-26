/*
	AUTHOR : VISHAL KUMAR GOURAV
	PROBLEM: IMPLEMENT GENERIC LINKED LIST IN C
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	void *data;
	struct node *next;
}node;
void push(node **head_ref,void *new_data,size_t data_size){
	node *new_node=(node*)malloc(sizeof(node));
	new_node->data=malloc(data_size);
	new_node->next=(*head_ref);
	int i;
	for(i=0;i<data_size;i++)
		*(char*)(new_node->data+i)=*(char *)(new_data +i);
	(*head_ref)=new_node;
}
void printList(node *node,void (*fptr)(void*)){
	while(node){
		(*fptr)(node->data);
		node=node->next;
	}
}
void printInt(void *n){
	printf("%d ",*(int *)n);
}
void printFloat(void *f){
	printf("%f ",*(float *)f);
}
int main(){
	node *start=NULL;
	unsigned int_size=sizeof(int);
	int a[]={10,20,30,40,50},i;
	for(i=4;i>=0;i--)
		push(&start,&a[i],int_size);
	printf("\nCreated integer linked list is:");
	printList(start,printInt);
	return 0;
}
