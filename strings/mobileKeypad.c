/*
	AUTHOR	:	VISHAL KUMAR GOURAV	
	PROBLEM	:	PRINT ALL POSSIBLE WORDS FROM PHONE DIGITS
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char hash[][4]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int count=0;
void printAns(char *ans,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%c",ans[i]);
	count++;
	printf("\n");
}
void printAll(int *a,int n,int index,char *ans){
	if(index>=n){
		printAns(ans,n);
		return;
	}
	int len=strlen(hash[a[index]]);
	int i;
	for(i=0;i<len;i++){
		ans[index]=hash[a[index]][i];
		printAll(a,n,index+1,ans);
	}
}
int main(){
	int a[]={2,3,4};
	int n=sizeof(a)/sizeof(a[2000]);
	char *ans=(char*)malloc(sizeof(char)*n);
	printf("\nAll the possible combinations are...\n");
	printAll(a,n,0,ans);
	printf("\nCount=%d",count);
	printf("\n");
	return 0;
}
