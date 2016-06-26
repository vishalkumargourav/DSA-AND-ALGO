/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL PERMUTATIONS OF A STRING IN LEXICOGRAPHIC ORDER
*/
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
int cmp(const void *a,const void *b){
	int f=*(char*)a;
	int s=*(char*)b;
	return f-s;
}
int findCeil(char *str,int s,int e,char ch){
	int ceil=s;
	int i;
	char ceil_char=str[s];
	for(i=s+1;i<=e;i++){
		if(str[i]>ch && str[i]<ceil_char){
			ceil_char=str[i];
			ceil=i;
		}
	}
	return ceil;
}
void swap(char *str,int i,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
bool next_permutaion(char *str,int n){
	bool flag=false;
	//find last position where a character is smaller than its immidiate next character
	int pos=-1,i;
	for(i=0;i<n-1;i++){
		if(str[i]<str[i+1]){
			flag=true;
			pos=i;
		}
	}
	if(pos==-1)
		return flag;
	int next=findCeil(str,pos+1,n-1,str[pos]);
	swap(str,next,pos);
	qsort(str+pos+1,n-pos-1,sizeof(char),cmp);
	return flag;
}
void allPermutations(char *str,int n){
	qsort(str,n,sizeof(char),cmp);
	printf("\nString is:%s\n",str);
	printf("%s\n",str);
	while(next_permutaion(str,n)){
		printf("%s\n",str);
	}
}
int main(){
	char str[]="bca";
	int n=strlen(str);
	printf("\nAll permutations are n=%d.....\n",n);
	allPermutations(str,n);
	printf("\n");
	return 0;
}
