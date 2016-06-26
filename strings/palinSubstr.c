/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LONGEST PALINDROMIC SUBSTRING
*/
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define M 100
void findLongestUtil(char *str,int l,bool **a,int *len,int *index){
	
}
void printSubstr(char *str,int index,int len){
	int i;
	for(i=index;i<index+len;i++)
		printf("%c",str[i]);
}
int findLongest(char *str,int l){
	bool a[M][M]={0};
	int i;
//	a[0][0]=false;
	int len=1,index=0;
	printf("\nl=%d and str=%s",l,str);
	
	int j,k;
	for(i=0;i<l;i++)
		a[i][i]=true;
	//for length of 2
	for(i=0;i<l-1;i++){
		if(str[i]==str[i+1]){
			a[i][i+1]=true;
			index=i;
			len=2;	
		}
	}
	//for length 3 and more
	for(k=3;k<=l;k++){
		for(i=0;i<=l-k;i++){
			j=i+k-1;
			if(str[i]==str[j] && a[i+1][j-1]==true){
				a[i][j]=true;
				index=i;
				len=k;
			}
		}
	}
	
	printf("\nLongest palindromic substring is:");
	printSubstr(str,index,len);
	return len;
}
int main(){
	char str[]="FORGEEKSSKEEGFOR";
	int l=strlen(str);
	printf("\nLength of longest palindrmic substring is:%d",findLongest(str,l));
	printf("\n");
	return 0;
}
