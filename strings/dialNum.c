/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ALL COMBINATIONS OF STRINGS THAT CAN BE USED TO DIAL A NUMBER
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *hash[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printAll(int *arr,int n,int index,char *buf){
	if(index==n){
		buf[index]='\0';
		printf("%s\n",buf);
		return;
	}
	int num=arr[index];
	int len=strlen(hash[num]);
	int i;
	for(i=0;i<len;i++){
		buf[index]=hash[num][i];
		printAll(arr,n,index+1,buf);
	}
}
int main(){
	int a[]={2,3};
	int n=sizeof(a)/sizeof(a[0]);
	char *buf=(char*)malloc(sizeof(char)*(n+1));
	printAll(a,n,0,buf);
	printf("\n");
	return 0;
}
