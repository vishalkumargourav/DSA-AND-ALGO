/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	SORT A STACK USING RECURSSION
*/
#include<cstdio>
using namespace std;
#include<stack>
void insert(stack<int> &s,int x){
	if(s.empty()||x<s.top()){
		s.push(x);
		return;
	}
	int temp=s.top();
	s.pop();
	insert(s,x);
	s.push(temp);
}
void sortIt(stack<int> &s){
	if(!s.empty()){
		int temp=s.top();
		s.pop();
		sortIt(s);
		insert(s,temp);
	}
}
int main(){
	stack<int> s;
	s.push(3);
	s.push(8);
	s.push(4);
	s.push(1);
	s.push(5);
	s.push(0);
	s.push(9);
	s.push(6);
	s.push(2);
	s.push(7);
	sortIt(s);
	int temp;
	printf("\nSorted stack is:");
	while(!s.empty()){
		temp=s.top();
		s.pop();
		printf("%d  ",temp);
	}
	printf("\n");
	return 0;
}
