/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	IMPLEMENTING IN BUILT QUICK SORT
*/
#include<stdio.h>
#include<string.h>
int compare(const void *a,const void *b){
	return (*(char *)a-*(char *)b);
}
int main(){
	char str[]="this is some random text message";
	int l=strlen(str);
	qsort(str,l,sizeof(char),compare);
	printf("\nSorted string is:%s",str);
	printf("\n");
	return 0;
}
