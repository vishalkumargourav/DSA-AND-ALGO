/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COUNT WORDS IN A GIVEN STRING OF CHARACTERS AND ' ' , '\n' , '\t'
*/
#include<stdio.h>
#include<string.h>

int countWords(char *str,int len){
	int count=0,i=0;
	while(i<len){
		while(i<len && (str[i]==' ' || str[i]=='\n' || str[i]=='\t'))
			i++;
		if(i<len)
			count++;
		if(i<len){
			printf("\nAnother word is:");
			while(i<len && str[i]!=' ' && str[i]!='\n' && str[i]!='\t'){
				printf("%c",str[i]);
				i++;
			}
		}
	}
	return count;
}
int main(void){
	 char string[]="this is  \t   some   random text \t \n this is more";
	 int n=countWords(string,strlen(string));
	 printf("\nNumber of words=%d",n);
	 printf("\n");
	 return 0;
}
