/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND ALL THE PERMUTATIONS OF A STRING WITH REPETITION
*/
#include<stdio.h>
#include<string.h>
void swap(char *str,int i ,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void permute(char *str,int s,int e,char *prev,int index){
	int i;
	for(i=s;i<=e;i++){
		prev[index]=str[i];
		if(index==e)
			printf("%s \n",prev);
		else
			permute(str,s,e,prev,index+1);	
	}
}
int main(){
	char str[]="ab";
	int n=sizeof(str)/sizeof(str[0]);
	n-=1;
	char prev[]="\0\0";
	permute(str,0,n-1,prev,0);
	printf("\n");
	return 0;
}
