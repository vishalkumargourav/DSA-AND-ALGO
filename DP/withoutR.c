/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LONGEST SUBARRAY WITHOUR REPETITION OF CHARACTERS
*/
#include<stdio.h>
#include<string.h>
int findLongestSub(char *str,int n,int *c){
	int i,j,start=0,max=1,max_s=0,max_e=0,len;
	for(i=0;i<n;i++){
		c[str[i]-'a']++;
		while(c[str[i]-'a']>1){	
			c[str[start]-'a']--;
			start++;
		}
		len=i-start+1;
		if(len>max){
			max=len;
			max_s=start;
			max_e=i;
		}
	}
	printf("\nMax str is:");
	for(i=max_s;i<=max_e;i++)
		printf("%c",str[i]);
	return max;
}
int main(){
	int c[26]={0};
	char *str="abdefgabef";
	int res=findLongestSub(str,strlen(str),c);
	printf("\n");
	return 0;
}
