/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT A MATRIX IN SPIRAL FORM
*/
#include<stdio.h>
#define R 6
#define C 5
void printSpiral(int mat[R][C],int r,int c){
	int sr,er,sc,ec;
	//sr:starting row
	//er:ending row
	//sc:starting column
	//ec:ending column
	int k;
	sr=0;
	er=r-1;
	sc=0;
	ec=c-1;
	while(sr<=er&&sc<=ec){
		for(k=sc;k<=ec;k++)
			printf("%d ",mat[sr][k]);
		sr++;
		for(k=sr;k<=er;k++)
			printf("%d ",mat[k][ec]);
		ec--;
		if(sr<=er){
			for(k=ec;k>=sc;k--)
				printf("%d ",mat[er][k]);
			er--;
		}
		if(sc<=ec){
			for(k=er;k>=sr;k--)
				printf("%d ",mat[k][sc]);
			sc++;
		}
	}
}
int main(){
	int mat[R][C]={
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
		{26,27,28,29,30}
	};
	printf("\nSpiral form is:");
	printSpiral(mat,R,C);
	printf("\n");
	return 0;
}
