/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MIN JUMPS REQUIRED TO REACH THE END OF ARRAY
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int a,int b){
	return a<b?a:b;
}
int findMin(int *a,int n){
	int i,j;
	int *jmp=(int*)malloc(sizeof(int)*n);
	jmp[0]=0;
	for(i=1;i<n;i++){
		jmp[i]=INT_MAX;
		for(j=0;j<i;j++){
			if((a[j]+j)>=i){
				jmp[i]=min(jmp[i],jmp[j]+1);
			}
		}
	}
	return jmp[n-1];
}
int main(){
	int a[]={1,3,6,1,0,9};
	int n=sizeof(a)/sizeof(a[0]);
	int res=findMin(a,n);
	printf("\nMin jumps required=%d",res);
	return 0;
}
