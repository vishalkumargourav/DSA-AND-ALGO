/*
	AUTHOR	:	VISHAL KUMAR GOURAV	
	PROBLEM	:	GIVEN TWO STRINGS WITH WILDCARDS SEE IF THEY MATCH
*/
#include<stdio.h>
#include<stdbool.h>
bool test(char *str1,char *str2){
	if(*str1=='\0' && *str2=='\0')
		return true;
	if(*str1=='\0' || *str2=='\0'){
	//	if(*str1=='\0')
	//		printf("\n====>first string ended");
	//	if(*str2=='\0')
	//		printf("\n====>second string ended");
		return false;
	}
	if(*str1!='*' && *str1!='?'){
		if(*str1!=*str2){
	//		printf("\n=====>%c and %c do not matches",*str1,*str2);
			return false;
		}
	//	printf("\n=====>%c and %c matches",*str1,*str2);
		return test(str1+1,str2+1);
	}else{
		if(*str1=='?')
			return test(str1+1,str2+1);
		if(*str1=='*')
			return test(str1,str2+1)||test(str1+1,str2);
	}
}
int main(){
	char *str1[]={"g*ks","ge?ks","g*k","*pqrs","abc*bcd","abc*c?d","*c*d","*?c*d"};
	char *str2[]={"geeks","geeksforgeeks","gee","pqrst","abcdhghgbcd","abcd","abcd","abcd"};
	int n=sizeof(str1)/sizeof(str1[0]);
	int i;
	for(i=0;i<n;i++){
		if(test(str1[i],str2[i]))
			printf("\nYes %s and %s matches.",str1[i],str2[i]);
		else
			printf("\nNo %s and %s do not matches.",str1[i],str2[i]);
	}
	printf("\n");
	return 0;
}
