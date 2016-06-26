/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REMOVE ALL "b" AND "ac" FROM STRING
*/
#include<stdio.h>
#include<string.h>
void modify(char str[],int len){
	int i;
	int j=0;
	for(i=0;i<len;i++){
		if(str[i]!='b' && str[i]!='a')
			str[j++]=str[i];
		else{
			if(str[i]=='b')
				continue;
			else{
				if(i+1<len && str[i+1]=='c'){
					if(i+2<len)
						str[j++]=str[i+2];
					i++;
				}else{
					str[j++]=str[i];
				}
			}
		}
	}
	if(j<len)
		str[j]='\0';
}
int main(void){
	char str[][10]={"acbac","aaac","ababac","bbbbd"};
	//char str[][10]={"ababac"};
	int n=sizeof(str)/sizeof(str[0]);
	int i;
	for(i=0;i<n;i++){
		printf("\nFinal for %s is:",str[i]);
		modify(str[i],strlen(str[i]));
		printf("%s",str[i]);
	}
	printf("\n");
	return 0;
}
