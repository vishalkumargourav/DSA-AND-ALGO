/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND TOTAL NUMBER OF REVERSALS NEEDED FOR BALANCING ALL PARENTHESIS
*/
#include<cstdio>
using namespace std;
#include<stack>
#include<cstring>
#include<cstdlib>
int countReversals(char *str,int n){
	int left=0,right=0;
	stack<char> s;
	if(n<=0)
		return 0;
	if(n%2!=0)
		return -1;
	int i;
	for(i=0;i<n;i++){
		if(str[i]=='}'){
			if(s.empty()){
				left++;
			}else if(s.top()=='}'){
				left++;
			}else
				s.pop();
		}else if(str[i]=='{')
			s.push('{');
		else{
			printf("\nInvalid input!!!!");
			return -1;
		}
	}
	while(!s.empty()){
		right++;
		s.pop();
	}
	printf("\nLeft=%d and right=%d\n",left,right);
	return (left%2==0?(left/2):(left/2+1))+(right%2==0?right/2:(right/2+1));
}
int main(){
	char str[]="}{{}}{{{";
	//char str[]="{{{{}}";
	//char str[]="}{{}}{{{";
	int n=strlen(str);
	printf("Number of reversals neede =%d",countReversals(str,n));
	printf("\n");
	return 0;
}
