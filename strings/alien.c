/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A SORTED DICTIONARY OF ALINE WORDS FIND THE CORRECT ALPHABETICAL ORDER
*/
#include<cstdio>
using namespace std;
#include<cstdlib>
#include<stack>
#include<cstring>
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
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->dest=dest;
	temp->next=NULL;
	return temp;
}
void addEdge(Graph *g,int src,int dest){
	Node *temp=createNode(dest);
	temp->next=g->arr[src].head;
	g->arr[src].head=temp;
}
int min(int a,int b){
	return a<b?a:b;
}
Graph *createGraph(int n){
	Graph *g=(Graph*)malloc(sizeof(Graph));
	g->size=n;
	g->arr=(List*)malloc(sizeof(List)*n);
	int i;
	for(i=0;i<n;i++)
		g->arr[i].head=NULL;
	return g;
}
void printGraph(Graph *g){
	int n=g->size;
	int i;
	for(i=0;i<n;i++){
		printf("\n[%c]->",i+'a');
		Node *temp=g->arr[i].head;
		while(temp){
			printf("(%c)->",temp->dest+'a');
			temp=temp->next;
		}
		printf("NULL");
	}
}
void topological(Graph *g,int src){
	stack<int> s1,s2;
	int *v;
	v=(int*)malloc(sizeof(int)*g->size);
	memset(v,0,sizeof(int)*g->size);
	s1.push(src);
	v[src]=1;
	Node *temp=NULL;
	int flag;
	int curr;
	while(!s1.empty()){
		curr=s1.top();
		flag=0;
		temp=g->arr[curr].head;
		while(temp && flag==0){
			if(v[temp->dest]==0){
				flag=1;
				s1.push(temp->dest);
				v[temp->dest]=1;
			}
			temp=temp->next;
		}
		if(flag==0){
			s1.pop();
			s2.push(curr);
		}
	}
	while(!s2.empty()){
		printf("%c ",s2.top()+'a');
		s2.pop();
	}
}
int main(){
	char words[][10]={"caa","aaa","aab"};
	int n=sizeof(words)/sizeof(words[0]);
	int i;
	int alpha=3;
	Graph *graph;
	graph=createGraph(3);
	for(i=0;i<n-1;i++){
		//for every adjacent words insert edges in graph
		char *word1=words[i];
		char *word2=words[i+1];
		int j=min(strlen(word1),strlen(word2));
		int k=0;
		while(k<j && word1[k]==word2[k])
			k++;
		if(k!=j){
			addEdge(graph,word1[k]-'a',word2[k]-'a');
		}
	}
	printf("\nGraph created is....");
	printGraph(graph);
	printf("\nAlien ordering is:");
	topological(graph,words[0][0]-'a');
	printf("\n");
	return 0;
}
