/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND AN ELEMENT FROM ROW AND COLUMN WISE SORTED MATRIX
*/
#include<stdio.h>
#include<stdbool.h>
#define R 4
#define C 4
bool isValid(int i,int j,int r,int c){
	return i>=0&&i<r&&j>=0&&j<c;
}
void findIndex(int mat[R][C],int r,int c,int x){
	int e=mat[0][c-1];
	int i=0,j=c-1;
	while(isValid(i,j,r,c)){
		if(x==mat[i][j]){
			printf("\nIndex of %d is:(%d,%d)",x,i,j);
			return;
		}else if(x>mat[i][j])
			i++;
		else
			j--;
	}
	printf("\n%d is not present in matrix",x);
}
int main(){
	int mat[R][C]={
		{10,20,30,40},
		{15,25,35,45},
		{27,29,37,48},
		{32,33,39,50}
	};
	int x=34;
	findIndex(mat,R,C,x);
	printf("\n");
	return 0;
}
