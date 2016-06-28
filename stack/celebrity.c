/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CELEBRITY PROBLEM
*/
#include<cstdio>
using namespace std;
#include<stack>
#define SIZE 4
int mat[SIZE][SIZE]={
			{0,0,1,0},
			{0,0,1,0},
			{0,0,0,0},
			{0,0,1,0}
			};
int findCeleb(){
	stack<int> s;
	int i;
	int n=SIZE;
	for(i=0;i<n;i++)
		s.push(i);
	int t1,t2;
	while(s.size()>1){
		t1=s.top();
		s.pop();
		t2=s.top();
		s.pop();
		if(mat[t1][t2])
			s.push(t2);
		else if(mat[t2][t1])
			s.push(t1);
	}
	t1=s.top();
	t2=n-1-t1;
	if(mat[t2][t1])
		return t1;
	return -1;
}
int main(){
	printf("\nId of celebrity is: %d",findCeleb());
	return 0;
}
