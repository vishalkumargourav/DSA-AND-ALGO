/*
	AUTHOR  :	VISHAL KUMAR GOURAV
	PROBLEM	:	STOCK SPAN PROBLEM
*/
#include<cstdio>
using namespace std;
#include<stack>
typedef struct Node{
	int ele,index;
}Node;
void stockSpan(int *a,int n){
	stack<Node> s;
	int i=0,count;
	Node temp;
	while(i<n){
		if(!s.empty()){
			if(s.top().ele>a[i])
				count=i-s.top().index;
			else{
				while(!s.empty()&&s.top().ele<a[i])
					s.pop();
				if(!s.empty())
					count=i-s.top().index;
				else
					count=i+1;
			}
		}else
			count=i+1;
		temp.ele=a[i];
		temp.index=i;
		printf("\n%d->%d",temp.ele,count);
		s.push(temp);
		i++;
	}
}
int main(){
	int a[]={100,80,60,70,60,75,85};
	int n=sizeof(a)/sizeof(a[0]);
	stockSpan(a,n);
	printf("\n");
	return 0;
}
