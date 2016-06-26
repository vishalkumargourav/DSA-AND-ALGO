/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REARRANGE STRING SO THAT ALL THE SAME CHARACTERS BECOME D-DISTANCE AWAY
*/
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
bool rearrange(char *str,int n,int d){
	int count[26]={0},i,max=INT_MIN;
	for(i=0;i<n;i++){
		count[str[i]-'a']++;
		if(str[i]-'a' > max)
			max=str[i]-'a';
		str[i]='\0';
	}
	/*for(i=0;i<256;i++){
		if(count[i]!=0)
			printf("\n%c = %d",i,count[i]);
	}*/
	int k=0,j;
	for(i=0;i<=max;i++){
		j=k;
		if(count[i]>1){
			while(j<n && count[i]!=0){
				str[j]=i+'a';
				j+=d;
				count[i]--;
			}
			for(;k<n && str[k]!='\0';k++);
			if(count[i]!=0)
				return false;
		}
	}
	for(j=0;j<n&& str[j]!='\0';j++);
	for(i=0;i<=max;i++){
		if(count[i]==1){
			if(j<n){
				str[j]=i+'a';
				count[i]--;
				for(;j<n && str[j]!='\0';j++);
			}
		}
		if(count[i]==1)
			return false;
	}
	return true;
}
int main(){
	char str[][20]={"abb","aacbbc","geeksforgeeks","aaa"};
	int d[]={2,3,3,2};
	int i;
	int n=sizeof(str)/sizeof(str[0]);
	for(i=0;i<n;i++){
		printf("\nFor orignal string:%s ",str[i]);
		if(rearrange(str[i],strlen(str[i]),d[i]))
			printf("Rearranged is:%s",str[i]);
		else
			printf("No rearrange is possible");
	}
	printf("\n");
	return 0;
}
