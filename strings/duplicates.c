/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REMOVE DUPLICATES FROM STRING
*/
#include<stdio.h>
#include<stdbool.h>
int removeDuplicates(char *str,int l){
	bool count[26]={0};
	int j=0,i;
	for(i=0;i<l;i++){
		if(count[str[i]-'a']==false){
			str[j++]=str[i];
			count[str[i]-'a']=true;
		}
	}
	return j;
}
int main(){
	char str[]="geeksforgeeks";
	int n=sizeof(str)/sizeof(str[0]);
	printf("\nLenght=%d",n);
	n=removeDuplicates(str,n-1);
	str[n]='\0';
	printf("\nString=%s",str);
	printf("\n");
	return 0;
}
