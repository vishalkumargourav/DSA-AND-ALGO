/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL THE COMBINATIONS WITH STRINGS RECURSSION
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void recursion(char *str,char *buf,int i,int j,int len,int n){
	if(i==len){
		buf[j]='\0';
		printf("\n%s",buf);
		return;
	}
	//place space
	buf[j]=' ';
	buf[j+1]=str[i];
	recursion(str,buf,i+1,j+2,len,n);
	//no space
	buf[j]=str[i];
	recursion(str,buf,i+1,j+1,len,n);
}
int main(){
	char str[]="ABCD";
	int len=strlen(str);
	int n=2*len;
	char *buf=(char*)malloc(sizeof(char)*n);
	buf[0]=str[0];
	recursion(str,buf,1,1,len,n);
	return 0;
}
