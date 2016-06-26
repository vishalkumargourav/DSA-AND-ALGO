/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENT A TRIE FOR DICTIONARY	
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define M 26
#define START 'a'
typedef struct Node{
	bool isEnd;
	struct Node *child[M];
}Node;
typedef struct{
	int n;
	Node *root;
}Trie;
Node *createNode(){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	int i;
	temp->isEnd=false;
	for(i=0;i<M;i++)
		temp->child[i]=NULL;
	return temp;
}
Trie *createTrie(){
	Trie *trie=(Trie*)malloc(sizeof(Trie));
	trie->n=0;
	trie->root=createNode();
	return trie;
}
void insertWord(Trie *trie,char *word,int len){
	int i;
	Node *root=trie->root;
	for(i=0;i<len;i++){
		if(root->child[word[i]-START]==NULL)
			root->child[word[i]-START]=createNode();
		root=root->child[word[i]-START];
	}
	root->isEnd=true;
}
bool isPresent(Trie *trie,char *word,int len){
	int i;
	Node *root=trie->root;
	for(i=0;i<len;i++){
		if(NULL==root->child[word[i]-START])
			return false;
		root=root->child[word[i]-START];
	}
	return root->isEnd;
}
void printTrie(Node *root,char *word,int index){
	if(NULL==root)
		return;
	if(root->isEnd==true){
		word[index]='\0';
		printf("%s \n",word);
	}
	int i;
	for(i=0;i<M;i++){
		if(root->child[i]!=NULL){
			word[index]=i+START;
		}
		printTrie(root->child[i],word,index+1);
	}
}
int main(void){
	Trie *trie=createTrie();
	char *words[]={"cat","act","god","tac","dog","cater"};
	int n=sizeof(words)/sizeof(words[0]);
	int i;
	for(i=0;i<n;i++)
		insertWord(trie,words[i],strlen(words[i]));
	char word[M];
	printTrie(trie->root,word,0);
	return 0;
}
