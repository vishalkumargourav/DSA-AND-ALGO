using namespace std;
#include<bits/stdc++.h>
int isBst(int *pre,int n){
	stack<int> s;
	int root=INT_MIN;
	for(int i=0;i<n;i++){
		if(pre[i]<root)
			return 0;
		while(!s.empty() && s.top()<pre[i]){
			root=s.top();
			s.pop();
		}
		s.push(pre[i]);
	}
	return 1;
}
int main(){
	int pre[]={40,30,35,80,100};
	int n1=sizeof(pre)/sizeof(pre[0]);
	int pre2[]={40,30,35,20,80,100};
	int n2=sizeof(pre2)/sizeof(pre2[0]);
	if(isBst(pre,n1))
		printf("\nIt is bst");
	else
		printf("\nIt is not bst");
	if(isBst(pre2,n2))
		printf("\nIt is bst");
	else
		printf("\nIt is not bst");
	printf("\n");
	return 0;
}
