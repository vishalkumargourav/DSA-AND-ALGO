/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FLOOD FILL ALGORITHM
*/
#include<stdio.h>
#include<stdbool.h>
#define R 8
#define C 8
bool isValid(int x,int y,int r,int c,int prevC,int mat[R][C]){
	return x>=0&&x<r&&y>=0&&y<c&&mat[x][y]==prevC;
}
void floodFill(int mat[R][C],int x,int y,int r,int c,int prevC,int newC){
	if(isValid(x,y,r,c,prevC,mat)){
		mat[x][y]=newC;
		floodFill(mat,x+1,y,r,c,prevC,newC);
		floodFill(mat,x-1,y,r,c,prevC,newC);
		floodFill(mat,x,y+1,r,c,prevC,newC);
		floodFill(mat,x,y-1,r,c,prevC,newC);
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
	int mat[R][C]={{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
	int x,y,newC;
	newC=3;
	x=y=4;
	floodFill(mat,x,y,R,C,mat[x][y],newC);
	printf("\nNew matrix is.....\n");
	printMat(mat,R,C);
	printf("\n");
	return 0;
}
