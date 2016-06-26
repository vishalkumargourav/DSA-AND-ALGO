/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL PERMUTATIONS OF GIVEN STRING
*/
#include<stdio.h>
#include<string.h>
void swap(char *str,int i,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void permute(char *str,int l,int r){
	if(l==r){
		printf("\n%s",str);
		return;
	}
	int i;
	for(i=l;i<=r;i++){
		swap(str,i,l);
		permute(str,l+1,r);
		swap(str,i,l);
	}
}
int main(){
	char str[]="abc";
	int len=strlen(str);
	permute(str,0,len-1);
	return 0;
}
