/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LEXICOGRAPHIC RANK OF A STRING (NON-DUPLICATES)
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int countSmaller(int *count,char ch){
	int i,sum=0;
	for(i=0;i<ch;i++)
		sum+=count[i];
	return sum;
}
int factorialUtil(int n,int *fact){
	if(n==0)
		return 1;
	if(fact[n]!=-1)
		return fact[n];
	fact[n]=factorialUtil(n-1,fact)*n;
	return fact[n];
}
int factorial(int n){
	int *fact=(int*)malloc(sizeof(int)*(n+1));
	int i;
	for(i=0;i<=n;i++)
		fact[i]=-1;
	return factorialUtil(n,fact);
}
int divideByDuplicates(int rank,int *count){
	int i;
	for(i=0;i<256;i++)
		rank/=factorial(count[i]);
}
int rank(char *str,int l){
	int count[256]={0};
	int rank=1;
	int i,smaller;
	for(i=0;i<l;i++)
		count[str[i]]++;
	for(i=0;i<l;i++){
		smaller=countSmaller(count,str[i]);
		count[str[i]]--;
		rank+=(smaller*(factorial(l-i-1)));
	}
	rank=divideByDuplicates(rank,count);
	return rank;
}
int main(){
	char str[]="STRING";
	int l=strlen(str);
	printf("\nRank of %s is %d.",str,rank(str,l));
	printf("\n");
	return 0;
}
