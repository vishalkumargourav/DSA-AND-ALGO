/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REVERSE WORDS IN GIVEN STRING
*/
#include<stdio.h>
int removeSpaces(char *str,int n){
	int i=0;
	while(str[i]==' ')
		i++;
	int k=0,j;
	for(j=i;j<=n;j++){
		if(str[j]==' '){
			str[k++]=' ';
			while(j<=n && str[j]==' ')
				j++;
		}
		if(j<=n)
			str[k++]=str[j];
	}
	for(j=i;j<n;j++)
		str[j-i]=str[j];
	return j-i;
}
void reverseWord(char *str,int s,int e){
	if(s<e){
		char temp=str[s];
		str[s]=str[e];
		str[e]=temp;
		reverseWord(str,s+1,e-1);
	}
}
void reverseWordsUtil(char *str,int n){
	int s,e;
	s=e=0;
	while(e<n){
		while(e<=n && str[e]!=' ' && str[e]!='\0')
			e++;
		if(str[e]==' '||str[e]=='\0'){
			e--;
			reverseWord(str,s,e);
			s=e+2;
			e=s;
		}else{
			reverseWord(str,s,e);
			e++;
		}
	}
}
void reverseWords(char *str,int n){
	n=removeSpaces(str,n);
	str[n+1]='\0';
	reverseWordsUtil(str,n);
	reverseWord(str,0,n);
	printf("\nString is:%s",str);
}
int main(){
	char str[]="test          this thing";
	int n=sizeof(str)/sizeof(str[0]);
	n-=2;
	reverseWords(str,n);
	printf("\n");
	return 0;
}
