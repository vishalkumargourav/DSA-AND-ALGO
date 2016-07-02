/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A SORTED DICTIONARY OF ALIEN WORDS FIND THE CORRECT ORDER OF ALPHABETS
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#include<stack>
typedef struct Node{
	int dest;
	struct Node *next;
}Node;
typedef struct List{
	Node *head;
}List;
typedef struct Graph{
	int size;
	List *arr;
}Graph;
Node *createNode(int dest){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->dest=dest;
	temp->next=NULL;
	return temp;
}
Graph *createGraph(int size){
	Graph *g=(Graph*)malloc(sizeof(Graph));
	g->size=size;
	g->arr=(List*)malloc(sizeof(List)*size);
	int i;
	for(i=0;i<size;i++)
		g->arr[i].head=NULL;
	return g;
}
void addEdge(Graph *g,int src,int dest){
	Node *temp=createNode(dest);
	temp->next=g->arr[src].head;
	g->arr[src].head=temp;
}
void printGraph(Graph *g){
	int i;
	Node *temp;
	for(i=0;i<g->size;i++){
		temp=g->arr[i].head;
		printf("[%d]->",i);
		while(temp){
			printf("%d->",temp->dest);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
void topoUtil(Graph *g,int src,stack<int> &s,int *v){
	Node *temp=g->arr[src].head;
	v[src]=1;
	while(temp){
		if(v[temp->dest]==0)	
			topoUtil(g,temp->dest,s,v);
		temp=temp->next;
	}
	s.push(src);
}
void topologicalSort(Graph *g){
	int i;
	stack<int> s;
	int *v=(int*)calloc(sizeof(int),g->size);
	for(i=0;i<g->size;i++){
		if(v[i]==0)
			topoUtil(g,i,s,v);
	}
	while(!s.empty()){
		printf("%c ",'a'+s.top());
		s.pop();
	}
}
void printOrder(char *words[],int n,int k){
	int i=0,j,len1,len2;
	char *word1,*word2;
	Graph *g=createGraph(k);
	for(i=0;i<n-1;i++){
		word1=words[i];
		word2=words[i+1];
		j=0;
		len1=strlen(words[i]);
		len2=strlen(words[i+1]);
		while(j<len1 && j<len2 && word1[j]==word2[j])
			j++;
		if(j<len1&&j<len2)
			addEdge(g,word1[j]-'a',word2[j]-'a');
	}
//	printGraph(g);
	printf("\nOrignal order of alphabets is:");
	topologicalSort(g);
}
int main(){
	char *words[]={"baa","abcd","abca","cab","cad"};
	int n=sizeof(words)/sizeof(words[0]);
	printOrder(words,n,4);
	printf("\n");
	return 0;
}
