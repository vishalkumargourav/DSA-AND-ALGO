/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND INTERSECTION AND UNION OF TWO SORTED ARRAYS	
*/
#include<stdio.h>
void printUnion(int *a,int n1,int *b,int n2){
	int i,j;
	i=0;
	j=0;
	while(i<n1 && j<n2){
		if(a[i]==b[j]){
			printf("%d ",a[i]);
			i++;
			j++;
		}else if(a[i]<b[j]){
			printf("%d ",a[i]);
			i++;
		}else{
			printf("%d ",b[j]);
			j++;
		}
	}
	while(i<n1){
		printf("%d ",a[i]);
		i++;
	}
	while(j<n2){
		printf("%d ",a[j]);
		j++;
	}
}
void printIntersection(int *a,int n1,int *b,int n2){
	int i,j;
	i=j=0;
	while(i<n1 && j<n2){
		if(a[i]==b[j]){
			printf("%d ",a[i]);
			i++;
			j++;
		}else if(a[i]<b[j]){
			i++;
		}else
			j++;
	}
}
int main(){
	int a[]={1,3,4,5,7};
	int n1=sizeof(a)/sizeof(a[0]);
	int b[]={2,3,5,6};
	int n2=sizeof(b)/sizeof(b[0]);
	printf("\nUnion of two arrays is:");
	printUnion(a,n1,b,n2);
	printf("\nIntersection of two arrays is:");
	printIntersection(a,n1,b,n2);
	printf("\n");
	return 0;
}
