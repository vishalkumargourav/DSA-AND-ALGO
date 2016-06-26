/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF A STRING IS INTERLEAVING OF THE OTHER TWO STRINGS
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool isInterleave(char *str1,int l1,char *str2,int l2,char *str,int l){
	int i,j;
	j=0;
	for(i=0;i<l;i++){
		if(j>=l1)
			break;
		if(str[i]==str1[j]){
			j++;
			str[i]=-str[i];
		}
	}
	if(j<l1)
		return false;
	j=0;
	for(i=0;i<l;i++){
		if(j>=l2)
			break;
		if(str[i]>0){
			if(str[i]==str2[j]){
				j++;
				str[i]=-str[i];
			}
		}
	}
	if(j<l2)
		return false;
	bool flag=true;
	for(i=0;i<l;i++){
		if(str[i]>0){
			flag=false;
			break;
		}
		str[i]=-str[i];
	}
	return flag;
}
bool isInterleave2(char *str1,int l1,char *str2,int l2,char *str,int l){
	int i,j,k;
	i=j=k=0;
	for(i=0;i<l;i++){
		if(j<l1 && str[i]==str1[j])
			j++;
		else if(k<l2 && str[i]==str2[k])
			k++;
		else return false;
	}
	return true;
}
int main(){
	char str1[]="xxy";
	char str2[]="xxz";
	int l1=strlen(str1);
	int l2=strlen(str2);
	char str[]="xxxxzy";
	int l=strlen(str);
	if(isInterleave2(str1,l1,str2,l2,str,l))
		printf("\nYes the string %s is interleave of %s and %s",str,str1,str2);
	else
		printf("\nNo the string %s is not interleave of %s and %s",str,str1,str2);
	printf("\n");
	return 0;
}
