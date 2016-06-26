/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	: 	CONVERT IN PLACE A STRING SUCH THAT ALL THE EVEN POSITION ELEMENTS 
			ARE MOVED TO THE END OF THE STRING
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *str,int i,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void convert(char *str,int len){
	int i,j;
	if(len%2==0){
		j=len-1;
		i=j;
	}else{
		i=len-2;
		j=len-1;
	}
	while(i>=0){
		swap(str,i,j);
		i-=2;
		j--;
	}
}
int main(){
	char str[]="a1b2c3d4e5f6g7h";
	int len=strlen(str);
	convert(str,len);
	printf("\nTransformed string is:%s",str);
	printf("\n");
	return 0;
}
