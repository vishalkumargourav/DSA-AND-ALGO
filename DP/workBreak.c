/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A DICTIONARY AND A STRING FIND IF THE STRING COULD BE BROKEN DOWN INTO WORDS
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_T 100
bool isSame(char *dict,char *sub,int n2,int n1){
	int i;
	if(n1!=n2)
		return false;
	for(i=0;i<n1;i++)
		if(dict[i]!=sub[i])
			return false;
	return true;
}
bool isPresent(char *sub,char *dict[],int len,int n){
	int i,tn;
	for(i=0;i<n;i++){
		tn=strlen(dict[i]);
		if(isSame(dict[i],sub,len,tn))
			return true;
	}
	return false;
}
void printArr(char *str,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%c",str[i]);
	printf("\n");
}
bool isPossible(char str[],int len,char *dict[],int n){
	bool **dp=(bool**)malloc(sizeof(bool*)*len);
	int i,j,k,l,t;
	char sub[MAX_T];
	for(i=0;i<len;i++)
		dp[i]=(bool*)malloc(sizeof(bool)*len);
	for(i=0;i<len;i++){
		//sub=(char*)memcpy(sub,&str[i],1);
		for(j=i;j<i+1 && j<len;j++)
			sub[j-i]=str[j];
		if(isPresent(sub,dict,1,n))
			dp[i][i]=true;
		else
			dp[i][i]=false;
	}
	for(l=2;l<=len;l++){
		for(i=0;i<len-l+1;i++){
			j=i+l-1;
			for(k=i;k<=j;k++)
				sub[k-i]=str[k];
			if(isPresent(sub,dict,l,n)){
				//printf("\nAssgining true for:");
				//printArr(sub,l);
				dp[i][j]=true;
			}else{
				dp[i][j]=false;
				for(k=i;k<j;k++){
					if(dp[i][k] && dp[k+1][j])
						dp[i][j]=true;
				}
			}
		}
	}
	/*printf("\nMatrix generated is...\n");
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			if(dp[i][j])
				printf("t ");
			else
				printf("f ");
		}
		printf("\n");
	}*/
	return dp[0][len-1];
}
int main(){
	char *dict[]={"i","sam","like","samsung","mobile","and","ice","cream","icecream","man","go","mango"};
	int n=sizeof(dict)/sizeof(dict[0]);
	char *str[]={"ilike","ilikesamsung","iiiiii","ilikelikeimangoiii",
	"samsungandmango","samsungandmangok"};
	int tn=sizeof(str)/sizeof(str[0]);
	int i,len;
	for(i=0;i<tn;i++){
		len=strlen(str[i]);
		if(isPossible(str[i],len,dict,n))
			printf("\nYes it is possible for %s",str[i]);
		else
			printf("\nNo it is not possible for %s",str[i]);
	}
	printf("\n");
	return 0;
}
