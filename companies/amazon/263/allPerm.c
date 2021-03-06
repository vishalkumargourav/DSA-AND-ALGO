/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND ALL PERMUTATIONS OF GIVEN STRING
*/
#include<stdio.h>
#include<string.h>
void swap(char *str,int i,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void printAll(char *str,int s,int e){
	if(s>e)
		return;
	if(s==e){
		printf("%s \n",str);
		return ;
	}
	int i;
	for(i=s;i<=e;i++){
		swap(str,s,i);
		printAll(str,s+1,e);
		swap(str,s,i);
	}
}
int main(){
	char str[]="abc";
	int n=strlen(str);
	printf("\nAll permutations are...\n");
	printAll(str,0,n-1);
	printf("\n");
	return 0;
}
