/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT ALL PERMUTATIONS OF STRING USING TEMPLATES
*/
#include<bits/stdc++.h>
using namespace std;
void printAll(string str){
	sort(str.begin(),str.end());
	do{
		cout<<str<<endl;
	}while(next_permutation(str.begin(),str.end()));
}
int main(){
	string str="CBA";
	printAll(str);
	printf("\n");
	return 0;
}
