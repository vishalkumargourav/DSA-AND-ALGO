/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	COUNT THE NUMBER OF ISLANDS
*/
#include<stdio.h>
//#define R 6
//#define C 3
#define R 6
#define C 6
int countIslands(int mat[R][C],int r,int c){
	int i,j,count;
	count=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(mat[i][j]==1){
				if((i==0 || mat[i-1][j]!=1) && (j==0 || mat[i][j-1]!=1))
					count++;
			}
		}
	}
	return count;
}
int main(){
	/*int mat[R][C]={
		{0,0,0},
		{1,1,0},
		{1,1,0},
		{0,0,1},
		{0,0,1},
		{1,1,0}	
	};*/
	int mat[R][C]={
		{1,0,0,0,0,0},
		{1,0,1,1,1,1},
		{0,0,0,0,0,0},
		{1,1,1,0,1,1},
		{1,1,1,0,1,1},
		{0,0,0,0,1,1}
	};
	printf("\nNumber of islands are:%d",countIslands(mat,R,C));
	printf("\n");
	return 0;
}
