/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND MAX LEN PATH SUCH THAT EVERY ELEMENT IN THAT PATH IS ATMOST 1 DIFF AWAY
*/
#include<stdio.h>
#include<stdbool.h>
#define R 3
#define C 3
typedef struct Node{
	int x,y;	//coordinates
}Node;
bool canBeNext(int i,Node arr[R+1]){
	return ((abs(arr[i-1].x-arr[i].x)==1&&abs(arr[i-1].y-arr[i].y)==0)||(abs(arr[i-1].y-arr[i].y)==1&&abs(arr[i-1].x-arr[i].x)==0));
}
int maxLen(int mat[R][C],int n){
	Node arr[R*R+1];		//considering number of rows equals no. of columns
	int i,j;
	for(i=1;i<=n*n;i++)
		arr[i].x=arr[i].y=-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arr[mat[i][j]].x=i;
			arr[mat[i][j]].y=j;
		}
	}
	int currLen=1,maxLen=0,maxEle=-1;
	for(i=2;i<=n*n;i++){
		if(arr[i].x!=-1&&arr[i-1].x!=-1){
			if(canBeNext(i,arr))
				currLen++;
			else
				currLen=1;
			if(currLen>maxLen){
				maxLen=currLen;
				maxEle=i;
			}
		}
	}
	printf("\nMax path ele ending at:%d",maxEle);
	return maxLen;
}
int main(){
	int mat[R][C]={
		{1,2,9},
		{5,3,8},
		{4,6,7}
	};
	printf("\nMax len path is:%d",maxLen(mat,R));
	printf("\n");
	return 0;
}
