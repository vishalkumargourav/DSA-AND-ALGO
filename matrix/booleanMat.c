/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	A BOOLEAN MATRIX QUESTION
*/
#include<stdio.h>
#include<stdbool.h>
#define R 4 
#define C 4
void transform(int mat[R][C],int r,int c){
	bool row,col;
	row=col=false;
	int i,j;
	for(i=0;i<c;i++){
		if(mat[0][i])
			row=true;
	}
	for(i=0;i<r;i++){
		if(mat[i][0])
			col=true;
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(mat[i][j]){
				mat[0][j]=1;
				mat[i][0]=1;
			}
		}
	}
	for(i=1;i<r;i++){
		for(j=1;j<c;j++){
			if(mat[0][j]==1||mat[i][0]==1)
				mat[i][j]=1;
		}
	}
	if(row){
		for(i=0;i<c;i++)
			mat[0][i]=1;
	}
	if(col){
		for(i=0;i<r;i++)
			mat[i][0]=1;
	}
}
void printMat(int mat[R][C],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d  ",mat[i][j]);
		printf("\n");
	}
}
int main(){
	int mat[R][C]={
		{1,0,0,1},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,0,0}
	};
	transform(mat,R,C);
	printf("\nFinal matrix is....\n");
	printMat(mat,R,C);
	printf("\n");
	return 0;
}
