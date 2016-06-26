/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LENGTH ENCODING OF STRING
*/
#include<stdio.h>
void lengthEncoding(char *str,int n){
	int i,j;
	for(i=0;i<n;i++){
		j=i;
		while(j<n && str[j]==str[i])
			j++;
		printf("%c%d\n",str[i],j-i);
		if(j<n)
			i=j-1;
		else
			break;
	}
	printf("\n");
}
int main(){
	char str[]="wwwwwaaaaadddeexxxxxxx";
	int n=sizeof(str)/sizeof(str[0]);
	n-=1;
	lengthEncoding(str,n);
	return 0;
}
