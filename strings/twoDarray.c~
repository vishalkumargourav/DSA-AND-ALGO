/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	ALLOCATE 2-D ARRAY DYNAMICALLY
			METHOD I : SIMULATING 2-D ARRAY WITH 1-D ARRAY
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *arr;
	int r,c;
	int j,i;
	r=4;
	c=5;
	int count=0;
	arr=(int*)malloc(sizeof(int)*r*c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[c*i+j]=count;
			count++;
		}
	}
	printf("\nArray is....\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d \t",arr[c*i+j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
