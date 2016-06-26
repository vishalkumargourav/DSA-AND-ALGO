/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ALLOCATE 2-D ARRAY DYNAMICALLY
			METHOD I : USING DOUBLE POINTER
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int **arr;
	int r,c;
	int j,i;
	int count=0;
	r=4;
	c=5;
	arr=(int**)malloc(sizeof(int*)*r);
	for(i=0;i<r;i++)
		arr[i]=(int*)malloc(sizeof(int)*c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			arr[i][j]=count++;
	}
	printf("\nGenerated 2-d array is....\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}
