#include<stdio.h>
#include<stdlib.h>
int printMat(int *a[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
int main(){
	int i,j,n=5;
	int count=1;
	int **a=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		a[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			a[i][j]=count++;
	}
	printMat((int**)a,n);
	printf("\n");
	return 0;
}
