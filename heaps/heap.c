/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	BASIC HEAP (BINARY)
*/
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct Heap{
	int *arr;
	int size;
	int capacity;
}Heap;
Heap *createHeap(int capacity){
	Heap *h=(Heap*)malloc(sizeof(Heap));
	h->capacity=capacity;
	h->size=0;
	h->arr=(int*)malloc(sizeof(int)*capacity);
	return h;
}
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
void swap(Heap *h,int i,int j){
	int temp=h->arr[i];
	h->arr[i]=h->arr[j];
	h->arr[j]=temp;
}
void heapify(Heap *h,int i){
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<h->capacity){
		if(h->arr[l]<h->arr[smallest])
			smallest=l;
	}
	if(r<h->capacity){
		if(h->arr[r]<h->arr[smallest])
			smallest=r;
	}
	if(smallest!=i){
		swap(h,i,smallest);
		heapify(h,smallest);
	}
}
int parent(int i){
	return (i-1)/2;
}
void insert(Heap *h,int data){
	if(h->size==h->capacity){
		printf("\nHeap overflow!!!!!!");
		return;
	}
	h->size+=1;
	int i=h->size-1;
	h->arr[i]=data;
	while(i!=0 && h->arr[parent(i)]>h->arr[i]){
		swap(h,i,parent(i));
		i=parent(i);
	}
}
void decrease(Heap *h,int i,int newValue){
	h->arr[i]=newValue;
	while(i!=0 && h->arr[parent(i)]>h->arr[i]){
		swap(h,i,parent(i));
		i=parent(i);
	}
}
int extractMin(Heap *h){
	if(h->size<=0)
		return INT_MAX;
	if(h->size==1){
		h->size--;
		return h->arr[0];
	}
	int root=h->arr[0];
	h->arr[0]=h->arr[h->size-1];
	h->size--;
	heapify(h,0);
	return root;
}
void deleteKey(Heap *h,int i){
	decrease(h,i,INT_MIN);
	extractMin(h);
}
int getMin(Heap *h){
	if(h->size>0)
		return h->arr[0];
	return INT_MAX;
}
int main(){
	int size=11;
	Heap *h=createHeap(size);
	insert(h,3);
	insert(h,2);
	deleteKey(h,1);
	insert(h,15);
	insert(h,5);
	insert(h,4);
	insert(h,45);
	printf("\nExtract min:%d",extractMin(h));
	printf("\nMin=%d",getMin(h));
	decrease(h,2,1);
	printf("\nMin=%d",getMin(h));
	return 0;
}
