/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT UNIQUE ROWS OF MATRIX
*/
#include<stdio.h>
#include<stdlib.h>
#define CHILD 2
#define R 4
#define C 5
typedef struct Node{
	struct Node *child[CHILD];
}Node;
typedef struct Trie{
	int size;
	Node *root;
}Trie;
Node *createNode(){
	Node *temp=(Node*)malloc(sizeof(Node));
	int i;
	for(i=0;i<CHILD;i++)
		temp->child[i]=NULL;
	return temp;
}
Trie *createTrie(){
	Trie *t=(Trie*)malloc(sizeof(Trie));
	t->size=0;
	t->root=createNode();
	return t;
}
void insertThisRow(Node *root,int mat[R][C],int r,int c,int ir,int ic){
	if(ic>=c)
		return;
	if(root->child[mat[ir][ic]]==NULL)
		root->child[mat[ir][ic]]=createNode();
	insertThisRow(root->child[mat[ir][ic]],mat,r,c,ir,ic+1);
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void printTrieUtil(Node *root,int *a,int n,int index){
	if(NULL==root||index==n){
		if(index==n){
			printf("\nRow is:");
			printArr(a,n);
		}
		return;
	}
	int i;
	for(i=0;i<CHILD;i++){
		if(root->child[i]!=NULL){
			a[index]=i;
			printTrieUtil(root->child[i],a,n,index+1);
		}
	}
}
void printTrie(Trie *t,int n){
	int *a=(int*)malloc(sizeof(int)*n);
	printTrieUtil(t->root,a,n,0);
}
void printUnique(int mat[R][C],int r,int c){
	Trie *t=createTrie();
	int i,j;
	for(i=0;i<R;i++)
		insertThisRow(t->root,mat,r,c,i,0);
	printTrie(t,c);
}
int main(){
	int mat[R][C]={
		{0,1,0,0,1},
		{1,0,1,1,0},
		{0,1,0,0,1},
		{1,1,1,0,0}
	};
	printf("\nUnique rows are...\n");
	printUnique(mat,R,C);
	printf("\n");
	return 0;
}
