/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REARRANGE ARRAY SUCH THAT A[I] BECOMES A[A[I]]
*/
#include<stdio.h>
void util(int *a,int n,int i){
	if(a[i]<0)
		return;
	int val=a[a[i]];
	i=a[i]-1;
	while(a[i]>0){
		int new_i=a[i]-1;
		a[i]=val;
		val=-a[a[i]];
		i=new_i;
	}
}
void rearrange(int *a,int n){
	int i;
	for(i=0;i<n;i++)
		a[i]++;
	for(i=0;i<n;i++){
		if(a[i]>0)
			util(a,n,i);
	}
	for(i=0;i<n;i++)
		a[i]=-a[i]-1;
}
int main(){
	int a[]={3,2,0,1};
	int n=sizeof(a)/sizeof(a[0]);
	rearrange(a,n);
	int i;
	printf("\nArray is:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
