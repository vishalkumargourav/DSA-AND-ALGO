/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL THE INTERLEAVINGS OF TWO STRINGS
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void printAll(char *str1,int l1,char *str2,int l2,char *data,int i1,int i2,int i){
	if(i1>=l1){
		if(i2>=l2){
			printf("%s \n",data);
			return;
		}else{
			data[i]=str2[i2];
			printAll(str1,l1,str2,l2,data,i1,i2+1,i+1);
		}
	}else if(i2>=l2){
		data[i]=str1[i1];
		printAll(str1,l1,str2,l2,data,i1+1,i2,i+1);
	}else{
		data[i]=str1[i1];
		printAll(str1,l1,str2,l2,data,i1+1,i2,i+1);
		data[i]=str2[i2];
		printAll(str1,l1,str2,l2,data,i1,i2+1,i+1);
	}
}
int main(){
	char str1[]="ab";
	char str2[]="c";
	int l1=strlen(str1);
	int l2=strlen(str2);
	char *data=(char*)malloc(sizeof(char)*(l1+l2+1));
	data[l1+l2]='\0';
	printAll(str1,l1,str2,l2,data,0,0,0);
	return 0;
}
