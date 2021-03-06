/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND ALL THE PERMUTATIONS OF A STRING
*/
#include<stdio.h>
#include<string.h>
void swap(char *str,int i ,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
int permute(char *str,int s,int e,char *prev){
	static int count=0;
	if(s==e){
		if(strcmp(str,prev)!=0){
			printf("\n%s ",str);
			strcpy(prev,str);
			count++;
		}
		return;
	}
	int i;
	for(i=s;i<=e;i++){
		if(str[s]!=str[i])
			swap(str,s,i);
		permute(str,s+1,e,prev);
		if(str[s]!=str[i])
			swap(str,s,i);
	}
	return count;
}
int main(){
	char str[]="abbc";
	int n=sizeof(str)/sizeof(str[0]);
	n-=1;
	char prev[]="\0\0\0\0\0\0\0";
	int count=permute(str,0,n-1,prev);
	printf("\nCount : %d",count);
	printf("\n");
	return 0;
}
