/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REVERSE A STACK USING RECURRSION
*/
#include<cstdio>
using namespace std;
#include<stack>
void insert(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int temp=s.top();
	s.pop();
	insert(s,x);
	s.push(temp);
}
void reverse(stack<int> &s){
	if(!s.empty()){
		int x=s.top();
		s.pop();
		reverse(s);
		insert(s,x);
	}
}
int main(){
	stack<int> s;
	int i;
	for(i=0;i<10;i++)
		s.push(i);
	reverse(s);
	printf("\nFinal stack is:");
	while(!s.empty()){
		printf("%d  ",s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}
