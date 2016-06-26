/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND THE LENGTH OF LONGEST VALID SUBSTRING OF PARENTHESIS
*/
#include<cstdio>
using namespace std;
#include<stack>
#include<cstring>
#include<climits>
int max(int a,int b){
	return a>b?a:b;
}
int findLongest(char *str,int n){
	stack<int> s;
	int temp;
	s.push(-1);
	int res=INT_MIN;
	int i;
	for(i=0;i<n;i++){
		if(str[i]=='(')
			s.push(i);
		else{
			s.pop();
			if(!s.empty()){
				temp=i-s.top();
				res=max(res,temp);
			}else{
				s.push(i);
			}
		}
	}
	return res;
}
int main(){
	//char str[]="((()";
	//char str[]=")()())";
	char str[]="()(()))))";
	int len=strlen(str);
	int res=findLongest(str,len);
	printf("\nResult is:%d",res);
	printf("\n");
	return 0;
}
