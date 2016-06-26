/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND LCS OF TWO STRINGS
*/
#include<stdio.h>
#include<string.h>
#define S 100
int max(int a,int b){
	return a>b?a:b;
}
int lcs(char *str1,char *str2,int l1,int l2){
	if(l1==0 || l2==0)
		return 0;
	if(str1[l1-1]==str2[l2-1])
		return lcs(str1,str2,l1-1,l2-1)+1;
	return max(lcs(str1,str2,l1,l2-1),lcs(str1,str2,l1-1,l2));
}
int M[S][S];
int P[S][S];
//1->diagonally upwards
//2->upwards
//3->leftwards
void printLCS(char *str1,char *str2,int l1,int l2){
	if(l1==0||l2==0)
		return;
	if(P[l1][l2]==1){
		printLCS(str1,str2,l1-1,l2-1);
		printf("%c",str1[l1-1]);
	}else if(P[l1][l2]==2)
		printLCS(str1,str2,l1,l2-1);
	else
		printLCS(str1,str2,l1-1,l2);
}
int lcsDynamic(char *str1,char *str2,int l1,int l2){
	int i,j;
	for(i=0;i<=l1;i++){
		for(j=0;j<=l2;j++){
			if(i==0 || j==0)
				M[i][j]=0;
			else if(str1[i-1]==str2[j-1]){
				M[i][j]=M[i-1][j-1]+1;
				P[i][j]=1;			//diagonally upwards
			}else{
				if(M[i][j-1]>=M[i-1][j])
					P[i][j]=2;		//leftwards
				else
					P[i][j]=3;		//upwards
				M[i][j]=max(M[i][j-1],M[i-1][j]);
			}
		}
	}
	printf("\nLcs is:");
	printLCS(str1,str2,l1,l2);
	return M[l1][l2];
}
int main(){
	char *str1="aggtab";
	char *str2="gxtxayb";
	printf("\nLength of lcs for %s and %s is:%d\n",str1,str2,lcsDynamic(str1,str2,strlen(str1),strlen(str2)));
	return 0;
}
