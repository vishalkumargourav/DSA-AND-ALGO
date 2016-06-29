/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	Kth smallest ELEMENT
*/
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Heap{
	int size,cap;
	int *arr;
}Heap;
Heap *createHeap(int cap){
	Heap *h=(Heap*)malloc(sizeof(Heap));
	h->cap=cap;
	h->size=0;
	h->arr=(int*)malloc(sizeof(int)*cap);
	return h;
}
void swap(Heap *h,int i,int j){
	int t=h->arr[i];
	h->arr[i]=h->arr[j];
	h->arr[j]=t;
}
void heapify(Heap *h,int i){
	int l=2*i+1;
	int r=2*i+2;
	int s=i;
	if(l<h->size && h->arr[l]<h->arr[s])
		s=l;
	if(r<h->size && h->arr[r]<h->arr[s])
		s=r;
	if(s!=i){
		swap(h,s,i);
		heapify(h,s);
	}
}
int extractMin(Heap *h){
	if(h->size<=0)
		return INT_MAX;
	int root=h->arr[0];
	if(h->size==1){
		h->size--;
		return root;
	}
	h->arr[0]=h->arr[h->size-1];
	h->size--;
	heapify(h,0);
	return root;
}
int kthsmallest(int *a,int n,int k){
	Heap *h=createHeap(n);
	int i,t;
	for(i=0;i<n;i++)
		h->arr[i]=a[i];
	h->size=n;
	for(i=n/2;i>=0;i--)
		heapify(h,i);
	printf("\nHeap is:");
	for(i=0;i<n;i++)
		printf("%d  ",h->arr[i]);
	printf("\n");
	for(i=0;i<n&&i<k;i++){
		t=extractMin(h);
		if(i==k-1)
			return t;
	}
	printf("\n%dth smallest element not present",k);
	return -1;
}
int main(){
	int a[]={5,6,7,1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	int k=0;
	printf("\n%dth smallest element is:%d",k,kthsmallest(a,n,k));
	printf("\n");
	return 0;
}
