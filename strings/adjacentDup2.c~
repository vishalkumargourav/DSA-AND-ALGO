/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REMOVE ADJACENT DUPLICATES FROM STRING	
*/
#include<stdio.h>
#include<string.h>
int removeD(char *str,int i,int j,int n){
	if(n<=i-1)
		return j;
	if(i!=j && str[j]==str[i])
		return removeD(str,i+2,j,n);
	str[j]=str[i];
	return removeD(str,i+1,j+1,n);
}
int main(void){
	//char str[]="geekkkksssssssssffforgeeeeeks";
	char str[]="azxxzy";
	int j=removeD(str,0,0,strlen(str));
	str[j]='\0';
	printf("\nFinal string would be:%s",str);
	printf("\n");
	return 0;
}
