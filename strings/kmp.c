/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	KMP PATTERN SEARCHING
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void buildPrefix(char *pat,int n,int *pre){
	int i,j;
	i=1;
	j=0;
	while(i<n){
		if(pat[i]==pat[j]){
			pre[i]=j+1;
			j++;
			i++;
		}else{
			if(j!=0)
				j=pre[j-1];
			else{
				pre[i]=0;
				i++;
			}
		}
	}
}
void printArr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void kmpMatch(char *pat,int m,char *str,int n){
	int *pre=(int*)malloc(sizeof(int)*m);
	buildPrefix(pat,m,pre);
	printf("\nPrefix array build is:");
	printArr(pre,m);
}
int main(){
	//char pat[]="aabaabaaa";
	char pat[]="aaacaaaaac";
	char str[]="";
	kmpMatch(pat,strlen(pat),str,strlen(str));
	printf("\n");
	return 0;
}








