/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	WAP FOR PRINTING MAGIC SQUARE FOR n, IS SHOULD HAVE n*n ELEMENTS
			PROPERTIES:
				-> MAGIC SUM = n(n*n+1)/2
				-> FIRST ELEMENT THAT IS 1 IS ALWYAS STORE AT : (n/2,n-1) SAY IT TO BE (i,j)
				-> NEXT ELEMENT IS STORED AT (i-1,j+1)
*/
#include<stdio.h>
#include<stdlib.h>
int nextRow1(int i,int n){
	if(i==0)
		i=n-1;
	else
		i--;
	return i;
}
int nextRow2(int i,int n){
	if(i==n-1)
		i=0;
	else
		i++;
	return i;
}
int nextCol1(int j,int n){
	if(j==n-1)
		j=0;
	else
		j++;
	return j;
}
int nextCol2(int j,int n){
	if(j==n-2)
		j=0;
	else if(j==n-1)
		j=1;
	else
		j+=2;
	return j;
}
void printMagicSquare(int n){
	if(n==0)
		return;
	int **mat=(int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*n);
	int j,k;
	i=n/2;
	j=n-1;
	for(k=1;k<=n*n;){
		//3rd condition
		if(i==-1 && j==n){
			i=0;j=n-2;
		}else{
			if(j==n)
				j=0;
			if(i<0)
				i=n-1;
		}
		if(mat[i][j]!=0){
			i++;
			j-=2;
			continue;
		}else
			mat[i][j]=k++;
		j++;i--;
	}
	printf("\nMagic matrix is....\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}
int main(){
	int n=3;
	printMagicSquare(n);
	printf("\n");
	return 0;
}
