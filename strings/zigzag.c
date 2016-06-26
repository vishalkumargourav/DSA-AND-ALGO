/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT A STRING IN ZIG ZAG MANNER
*/
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
void printZigZag(char *str,int len,int n){
	int i;
	int k;
	bool flag=false;
	for(k=0;k<n;k++){
		i=k;
		while(i<len){
			printf("%c",str[i]);
			if(k==0 || k==n-1)
				i+=((n-2)*2+2);
			else if(!flag)
				i+=(2*(n-k-2)+2);
			else
				i+=(k*2);
			flag=!flag;
		}
	}
}
int main(){
	char str[]="GEEKSFORGEEKS";
	int len=strlen(str);
	int n=3;
	printZigZag(str,len,n);
	printf("\n");
	return 0;
}
