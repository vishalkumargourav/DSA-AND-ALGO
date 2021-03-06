/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK FOR BALANCED PARENTHESIS {,(,[
*/
#include<cstdio>
using namespace std;
#include<stack>
#include<cstring>
#include<cstdbool> 
bool isBalanced(char *str,int n){
	stack<char> s;
	int i=0;
	while(!s.empty()||i<n){
		switch(str[i]){
			case '(':
				s.push('(');
			break;
			case ')':
				if(!s.empty()&&s.top()=='(')
					s.pop();
				else 	
					return false;
			break;
			case '[':
				s.push('[');
			break;
			case ']':
				if(!s.empty()&&s.top()=='[')
					s.pop();
				else
					return false;
			break;
			case '{':
				s.push('{');
			break;
			case '}':
				if(!s.empty()&&s.top()=='{')
					s.pop();
				else
					return false;
			break;
			default:
				return false;
		}
		i++;
	}
	return true;
}
int main(){
	char str[]="[()]{}{[()()]()}";
	int n=strlen(str);
	if(isBalanced(str,n))
		printf("\nYes\n");
	else
		printf("\nNo\n");
	printf("\n");
	return 0;
}
