#include<stdio.h>
int sub(int x,int y){
	int borrow;
	while(y!=0){
		borrow=~x&y;
		x=x^y;
		y=borrow<<1;
	}
	return x;
}
int main(){
	int x[]={1,2,3,4,5,6,7,8,9};
	int y[]={5,6,7,8,9,1,2,3,4};
	int i;
	int n=sizeof(x)/sizeof(x[0]);
	for(i=0;i<n;i++)
		printf("\nsub(%d,%d)=%d",x[i],y[i],sub(x[i],y[i]));
	printf("\n");
	return 0;
}
