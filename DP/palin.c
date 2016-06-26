/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MINIMUM NUMBER OF INSERTIONS REQUIRED TO MAKE IT A PALINDROME (RECURSIVE)
*/
#include<stdio.h>
#include<string.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int findMin(char *str,int s,int e){
	if(s>e) return INT_MAX;
	if(s==e) return 0;
	if(s==e-1) return str[s]==str[e]?0:1;
	return str[s]==str[e]?(findMin(str,s+1,e-1)):(min(findMin(str,s+1,e),findMin(str,s,e-1))+1);
}
int main(){
	char *str="geeks";
	//char *str="aa";	
	//char *str="ab";
	int n=strlen(str);
	printf("\nMin insertions required are:%d",findMin(str,0,n-1));
	printf("\n");
	return 0;
}
