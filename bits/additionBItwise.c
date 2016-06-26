#include<stdio.h>
int add(int x,int y){
	int carry;
	while(y!=0){
		carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
int main(){
	int x[]={1,2,3,4,5,6,7,8,9};
	int y[]={5,6,7,8,9,1,2,3,4};
	int i;
	int n=sizeof(x)/sizeof(x[0]);
	for(i=0;i<n;i++)
		printf("\nadd(%d,%d)=%d",x[i],y[i],add(x[i],y[i]));
	printf("\n");
	return 0;
}
