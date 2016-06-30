/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT A MATRIX DIAGONALLY
*/
#include<stdio.h>
#include<stdbool.h>
#define R 5
#define C 4
bool isValid(int i,int j,int r,int c){
	return i>=0&&i<r&&j>=0&&j<c;
}
void printDiagonal(int mat[R][C],int r,int c){
	int i,j,tr,tc;
	for(i=0;i<r;i++){
		tr=i;
		tc=0;
		while(isValid(tr,tc,r,c)){
			printf("%d  ",mat[tr][tc]);
			tc++;
			tr--;
		}
	}
	for(j=1;j<c;j++){
		tc=j;
		tr=r-1;
		while(isValid(tr,tc,r,c)){
			printf("%d  ",mat[tr][tc]);
			tc++;
			tr--;
		}
	}
}
int main(){
	int mat[R][C]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
		{17,18,19,20}
	};
	printf("\nDiagonal order of matrix is:");
	printDiagonal(mat,R,C);
	printf("\n");
	return 0;
}
