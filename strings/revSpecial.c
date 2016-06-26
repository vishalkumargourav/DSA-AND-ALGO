/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REVERSE A STRING WITH SPECIAL CHARACTER WIHOUT AFFECTING SPEICAL CHARACTERS
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isNotAlpha(char ch){
	return !((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'));
	
}
void swap(char *str,int i,int j){
	char temp;
	temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void reverse(char *str,int n){
	int i=0,j=n-1;
	while(i<n && isNotAlpha(str[i]))
		i++;
	while(j>=0 && isNotAlpha(str[j]))
		j--;
	while(i<j){
		swap(str,i,j);
		i++;
		j--;
		while(i<n && isNotAlpha(str[i]))
			i++;
		while(j>=0 && isNotAlpha(str[j]))
			j--;
	}
}
int main(){
	char str[]="a,b$c";
	int n=strlen(str);
	printf("\nOrignal string is:%s",str);
	reverse(str,n);
	printf("\nReversed string is:%s",str);
	printf("\n");
	return 0;
}
