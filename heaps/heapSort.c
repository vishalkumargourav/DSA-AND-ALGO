/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	HEAP SORT
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Heap{
	int size,cap;
	int *arr;
}Heap;
Heap *createHeap(int cap){
	Heap *h=(Heap*)malloc(sizeof(Heap));
	h->size=0;
	h->cap=cap;
	h->arr=(int*)malloc(sizeof(int)*cap);
	return h;
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
void swap(Heap *h,int i,int j){
	int temp=h->arr[i];
	h->arr[i]=h->arr[j];
	h->arr[j]=temp;
}
void heapify(Heap *h,int i){
	int l=2*i+1;
	int r=2*i+2;
	int s=i;
	if(l<h->size){
		if(h->arr[l]<h->arr[s])
			s=l;
	}
	if(r<h->size){
		if(h->arr[r]<h->arr[s])
			s=r;
	}
	if(s!=i){
		swap(h,s,i);
		heapify(h,s);
	}
}
int extractMin(Heap *h){
	int data;
	if(h->size<=0)
		return INT_MAX;
	data=h->arr[0];
	if(h->size==1){
		h->size--;
		return data;
	}
	h->arr[0]=h->arr[h->size-1];
	h->size--;
	heapify(h,0);
	return data;
}
void heapSort(int *a,int n){
	int i=n/2;
	Heap *h=createHeap(n);
	h->size=n;
	for(i=0;i<n;i++)
		h->arr[i]=a[i];
	i=n/2;
	for(;i>=0;i--)
		heapify(h,i);
	i=0;
	while(h->size)
		a[i++]=extractMin(h);
}
int main(){
	int a[]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nSorted array is:");
	heapSort(a,n);
	printArr(a,n);
	return 0;
}
