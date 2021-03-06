/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND NEXT GREATER ELEMENT TO EVERY ELEMENT OF AN ARRAY
*/
#include<cstdio>
using namespace std;
#include<stack>
void printNextGreater(int *a,int n){
	stack<int> s;
	int i;
	if(n<=0)
		return;
	s.push(a[0]);
	for(i=1;i<n;i++){
		while(!s.empty()&&s.top()<a[i]){
			printf("\n%d->%d",s.top(),a[i]);
			s.pop();
		}
		s.push(a[i]);
	}
	while(!s.empty()){
		printf("\n%d->-1",s.top());
		s.pop();
	}
}
int main(){
	int a[]={11,13,21,3};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nNext greater elements are...\n");
	printNextGreater(a,n);
	printf("\n");
	return 0;
}
