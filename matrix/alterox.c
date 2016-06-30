/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A MATRIX WITH ALTERNATING O AND 1
*/
#include<stdio.h>
#include<stdlib.h>
void printMat(int r,int c){
	int **mat=(int**)malloc(sizeof(int*)*r);
	int i,j,sr,sc,er,ec;
	int ch=0;
	for(i=0;i<r;i++)
		mat[i]=(int*)malloc(sizeof(int)*c);
	sr=sc=0;
	er=r-1;
	ec=c-1;
	while(sr<=er&&sc<=ec){
		ch=ch==0?1:0;
		for(i=sc;i<=ec;i++)
			mat[sr][i]=ch;
		sr++;
		for(i=sr;i<=er;i++)
			mat[i][ec]=ch;
		ec--;
		if(sr<=er){
			for(i=ec;i>=sc;i--)
				mat[er][i]=ch;
			er--;
		}
		if(sc<=ec){
			for(i=er;i>=sr;i--)
				mat[i][sc]=ch;
			sc++;
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d  ",mat[i][j]);
		printf("\n");
	}
}
int main(){
	int r,c;
	/*printf("\nEnter the number of rows:");
	scanf("%d",&r);
	printf("\nEnter the number of columns:");
	scanf("%d",&c);*/
	r=10;
	c=12;
	printMat(r,c);
	printf("\n");
	return 0;
}
