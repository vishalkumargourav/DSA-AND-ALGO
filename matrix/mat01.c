/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A BOOLEAN MATRIX FIND k SUCH THAT ALL ELEMENTS IN Kth ROW ARE 0 
			AND ALL ELEMENTS IN kth COLUMN ARE 1
			ELEMENT AT MAT[K][K] COULD BE EITHER 0 OR 1
*/
#include<stdio.h>
#include<stdbool.h>
#define N 5
bool isValid(int i,int j,int r,int c){
	return i>=0&&i<r&&j>=0&&j<c;
}
int findK(int mat[N][N],int n){
	int i=0,j=n-1,k;	//starting from top right corner
	int res=-1;
	while(isValid(i,j,n,n)){
		if(mat[i][j]){
			for(;i<n&& mat[i][j];i++);
			if(i==n){
				res=j;
				break;
			}else
				j--;
		}else{
			for(;j>=0 && mat[i][j]==0;j--);
			if(j==-1){
				//printf("\n----------%d",j);
				res=i;
				break;
			}else
				i++;
		}
	}
	if(res==-1)
		return -1;
	for(i=0;i<n;i++){
		if(res==i)
			continue;
		if(mat[res][i]!=0)
			break;
	}
	if(i<n)
		return -1;
	for(i=0;i<n;i++){
		if(res==i)
			continue;
		if(mat[i][res]!=1)
			break;
	}
	if(i<n)
		return -1;
	return res;
}
int main(){
	int mat[N][N]={
			{0, 1, 1, 0, 1},
                        {0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1}};
        printf("\nK=%d",findK(mat,N));
	printf("\n");
	return 0;
}
