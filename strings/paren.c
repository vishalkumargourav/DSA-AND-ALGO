/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL WAYS TO PRINT STRING IN BRAKET FORM
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
void printAll(char *str,int i,int n,char *buf,int j,bool flag){
	if(i>=n){
		if(flag){
			buf[j]=')';
			buf[j+1]='\0';
		}else
			buf[j]='\0';
		printf("%s\n",buf);
		return;
	}
	if(flag){
		//close previous ( here
		buf[j]=')';
		printAll(str,i,n,buf,j+1,false);
		//do not close previous ( here
		buf[j]=str[i];
		printAll(str,i+1,n,buf,j+1,true);
	}else{
		//start a ( here
		buf[j]='(';
		buf[j+1]=str[i];
		printAll(str,i+1,n,buf,j+2,true);
	}
}
int main(){
	char str[]="abc";
	int len=strlen(str);
	char *buf=(char*)malloc(sizeof(char)*(len+2*len+1));
	printAll(str,0,len,buf,0,false);
	printf("\n");
	return 0;
}
