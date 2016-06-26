#include<stdio.h>
#include<limits.h>
int longestSubstr(char *str,int n,int k){
	int max=INT_MIN;
	int count=0;
	int start=-1,end=-1;
	int a[26]={0};
	int i=1,j=0;
	a[str[0]-'a']=1;
	count=1;
	while(i<n){
		if(count==k){
			for(;i<n && a[str[i]]!=0;i++);
			if(i-j+1 > max){
				max=i-j+1;
				start=j;
				end=i;
			}
		}
	}
}
int main(){
	char str[]="";
	int len=strlen(str);
	int k;
	int n=longestSubstr(str,len,k);
	printf("\nLongest substring is of %d length.",n);
	return 0;
}
