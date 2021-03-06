/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A ARRAY OF WORDS PRINT ALL THE ANAGRAMS TOGETHER
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char *str;
	int index;
}Word;
typedef struct{
	int size;
	Word *arr;
}List;
int cmpWords(const void *a,const void *b){
	Word *str1=(Word *)a;
	Word *str2=(Word *)b;
	return strcmp(str1->str,str2->str);
}
int cmpChar(const void *a,const void *b){
	return *(char *)a-*(char*)b;
}
void printTogether(char *words[],int n){
	List *list=(List*)malloc(sizeof(List));
	list->size=n;
	list->arr=(Word*)malloc(sizeof(Word)*n);
	int i;
	for(i=0;i<n;i++){
		list->arr[i].str=(char*)malloc(sizeof(char)*strlen(words[i]));
		strcpy(list->arr[i].str,words[i]);
		list->arr[i].index=i;
	}
	printf("\nDuplicate list generated is....\n");
	for(i=0;i<n;i++)
		printf("%s(%d) ",list->arr[i].str,list->arr[i].index);
	for(i=0;i<n;i++)
		qsort(list->arr[i].str,strlen(list->arr[i].str),sizeof(char),cmpChar);
	qsort(list->arr,n,sizeof(Word),cmpWords);
	printf("\nDuplicate sorted list generated is....\n");
	for(i=0;i<n;i++)
		printf("%s(%d) ",list->arr[i].str,list->arr[i].index);
	printf("\nOutput as per question is:");
	for(i=0;i<n;i++)
		printf("%s ",words[list->arr[i].index]);
}
int main(){
	char *words[]={"cat","dog","tac","god","act"};
	int n=sizeof(words)/sizeof(words[0]);
	printf("\nNumber of elements:%d",n);
	printTogether(words,n);
	printf("\n");
	return 0;
}
