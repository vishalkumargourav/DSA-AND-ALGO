/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL THE COMBINATIONS WITH STRINGS
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
void printThis(char *str,int len,int n,int k){
	int index=0;
	while(index<len){
		printf("%c",str[index]);
		if((k>>(index+1))&n)
			printf(" ");
		index++;
	}
	printf("\n");
}
int main(){
	char str[]="ABCD";
	int len=strlen(str);
	int n=pow(2,len-1);
	int i;
	for(i=0;i<n;i++)
		printThis(str,len,i,n);
	return 0;
}
