/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND ALL THE PERMUTATIONS OF A STRING
*/
#include<stdio.h>
void swap(char *str,int i ,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void permute(char *str,int s,int e){
	if(s==e){
		printf("\n%s ",str);
		return;
	}
	int i;
	for(i=s;i<=e;i++){
		swap(str,s,i);
		permute(str,s+1,e);
		swap(str,s,i);
	}
}
int main(){
	char str[]="abc";
	int n=sizeof(str)/sizeof(str[0]);
	n-=1;
	permute(str,0,n-1);
	printf("\n");
	return 0;
}
