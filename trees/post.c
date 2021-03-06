/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN INORDER AND PREORDER TRAVERSAL YOU NEED TO PRINT THE POST ORDER TRAVERSAL
*/
#include<stdio.h>
#include<stdlib.h>
int findInInorder(int *in,int data,int s,int e){
	int i;
	for(i=s;i<=e;i++)
		if(in[i]==data)
			return i;
	return -1;
}
void postorder(int *in,int *pre,int *i,int s,int e,int n){
	if(s>e || e>=n)
		return;
	int temp=pre[*i];
	++*i;
	int ti=findInInorder(in,temp,s,e);
	if(ti!=-1){
		postorder(in,pre,i,s,ti-1,n);
		postorder(in,pre,i,ti+1,e,n);
	}
	printf("%d ",temp);
}
int main(){
	int in[]={4,2,5,1,3,6};
	int pre[]={1,2,4,5,3,6};
	int n=sizeof(in)/sizeof(in[0]);
	int i=0;
	postorder(in,pre,&i,0,n-1,n);
	printf("\n");
	return 0;
}
