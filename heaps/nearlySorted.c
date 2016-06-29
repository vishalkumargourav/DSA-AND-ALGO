/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	SORT A NEARLY SORTED ARRAY
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
	if(l<h->size&&h->arr[l]<h->arr[s])
		s=l;
	if(r<h->size&&h->arr[r]<h->arr[s])
		s=r;
	if(s!=i){
		swap(h,i,s);
		heapify(h,s);
	}
}
void insert(Heap *h,int data){
	if(h->size==h->cap){
		printf("\nHeap overflow!!!!!");
		return;
	}
	h->arr[h->size]=data;
	h->size=h->size+1;
	int i=h->size-1;
	while(i>0&&h->arr[(i-1)/2]>h->arr[i]){
		swap(h,i,(i-1)/2);
		i=(i-1)/2;
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
void sortIt(int *a,int n,int k){
	Heap *h=createHeap(k+1);
	int i;
	for(i=0;i<=k;i++)
		insert(h,a[i]);
	printf("\nInitial heap is:");
	for(i=0;i<=k;i++)
		printf("%d  ",h->arr[i]);
	for(i=0;i<n;i++){
		a[i]=extractMin(h);
		if(i+k+1<n)
			insert(h,a[i+k+1]);
	}
	printf("\n");
}
int main(){
	int a[]={2,6,3,12,56,8};
	int n=sizeof(a)/sizeof(a[0]);
	int k=3;
	sortIt(a,n,k);
	printf("\nSorted array is:");
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
	return 0;
}
