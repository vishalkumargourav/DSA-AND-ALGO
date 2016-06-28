/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MAXIMUM OF ALL SUBARRAYS OF SIZE K
*/
#include<cstdio>
using namespace std;
#include<deque>
void printk(int *a,int n,int k){
	deque<int> d;
	int i=0;
	while(i<k){
		while(!d.empty()&&a[d.back()]<=a[i])
			d.pop_back();
		d.push_back(i);
		i++;
	}
	for(;k<n;k++){
		printf("%d  ",a[d.front()]);
		while(!d.empty()&&d.front()<=i-k)
			d.pop_front();
		while(!d.empty()&&a[d.back()]<=a[i])
			d.pop_back();
		d.push_back(i);
	}
	printf("%d  ",a[d.front()]);
}
int main(){
	int a[]={12,1,78,90,57,89,56};
	int n=sizeof(a)/sizeof(a[0]);
	int k=3;
	printf("\nMax k are:");
	printk(a,n,k);
	printf("\n");
	return 0;
}
