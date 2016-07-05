/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CREATE A GENERIC LINKED LIST
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	void *data;
	struct Node *next;
}Node;
void push(Node **head,void *data,size_t data_size){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=malloc(data_size);
	temp->next=*head;
	int i;
	for(i=0;i<data_size;i++)
		*(char*)(temp->data+i)=*(char*)(data+i);
	*head=temp;
}
void printInt(Node *head){
	while(head){
		printf("%d ",*(int*)head->data);
		head=head->next;
	}
}
void printFloat(Node *head){
	while(head){
		printf("%f ",*(float*)head->data);
		head=head->next;
	}
}
int main(){
	struct Node *start=NULL;
	int a[]={10,20,30,40,50},i,n;
	n=sizeof(a)/sizeof(a[0]);
	for(i=n-1;i>=0;i--)
		push(&start,&a[i],sizeof(int));
	printf("\nLinked list is:");
	printInt(start);
	
	start=NULL;
	float b[]={10.1,20.2,30.3,40,4,50,5};
	n=sizeof(b)/sizeof(b[0]);
	for(i=n-1;i>=0;i--)
		push(&start,&b[i],sizeof(float));
	printf("\nLinked list is:");
	printInt(start);
	printf("\n");
	return 0;
}
