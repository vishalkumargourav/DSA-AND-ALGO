/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A MAXIMUM PATH LINKED LIST
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
void push(Node **head,int data){
	Node *temp=createNode(data);
	temp->next=*head;
	*head=temp;
}
Node *addToLast(Node *head,int data){
	Node *temp=head;
	if(NULL==temp)
		return createNode(data);
	while(temp->next)
		temp=temp->next;
	temp->next=createNode(data);
	return head;
}
void printList(Node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
Node *findMax(Node *head1,Node *head2){
	if(NULL==head1)
		return head2;
	if(NULL==head2)
		return head1;
	Node *start1,*start2,*end1,*end2;
	start1=end1=head1;
	start2=end2=head2;
	int sum1,sum2;
	sum1=sum2=0;
	Node *res=NULL,*end=NULL;
	while(end1&&end2){
		if(end1->data==end2->data){
			sum1+=head1->data;
			sum2+=head2->data;
			if(sum1>sum2){
				if(NULL==res){
					res=start1;
					end=start1;
				}else
					end->next=start1;
				end=end1;
				
			}else{
				if(NULL==res){
					res=start2;
					end=start2;
				}else
					end->next=start2;
				end=end2;
			}
			start1=end1=end1->next;
			end2=start2=end2->next;
			end->next=NULL;
			sum1=sum2=0;
		}else if(end1->data<end2->data){
			sum1+=end1->data;
			end1=end1->next;
		}else if(end1->data>end2->data){
			sum2+=end2->data;
			end2=end2->next;
		}	
	}
	while(end1){
		sum1+=end1->data;
		end1=end1->next;
	}
	while(end2){
		sum2+=end2->data;
		end2=end2->next;
	}
	if(sum1>sum2){
		if(NULL==res)
			res=start1;
		else
			end->next=start1;
	}else{
		if(NULL==res)
			res=start2;
		else
			end->next=start2;
	}
	return res;
}
int main(){
	int a1[]={2,3,7,10,12};
	int a2[]={1,5,7,8};
	
	//int a1[]={10,12};
	//int a2[]={5,7,9};
	
	//int a1[]={2,3,7,10,12,15,30,34};
	//int a2[]={1,5,7,8,10,15,16,19};
	int n1=sizeof(a1)/sizeof(a1[0]);
	int n2=sizeof(a2)/sizeof(a2[0]);
	Node *head1,*head2;
	head1=head2=NULL;
	Node *result=NULL;
	int i;
	for(i=0;i<n1;i++)
		head1=addToLast(head1,a1[i]);
	for(i=0;i<n2;i++)
		head2=addToLast(head2,a2[i]);	
	printf("\nList 1 is:");
	printList(head1);
	printf("\nList 2 is:");
	printList(head2);
	Node *res=findMax(head1,head2);
	printf("\nResult is:");
	printList(res);
	printf("\n");
	return 0;
}
