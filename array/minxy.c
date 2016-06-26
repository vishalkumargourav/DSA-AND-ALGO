/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN AN ARRAY AND TWO ELEMENTS X AND Y. FIND MINIMUM DISTANCE B/W THESE TWO ELEMENTS.
*/
#include<stdio.h>
#include<limits.h>
int findMin(int *a,int n,int x,int y){
	int flag,i=0,prev;
	int min=INT_MAX;
	if(x==y){
		while(i<n){
			if(a[i]==x)
				return 0;
			i++;
		}
		return -1;
	}
	while(i<n && a[i]!=x && a[i]!=y){
		i++;
		if(a[i]==x){
			flag=1;
			prev=i;
		}
		if(a[i]==y){
			flag=2;
			prev=i;
		}
	}
	i++;
	if(i>=n-1)
		return -1;
	while(i<n){
		if(a[i]==x){
			if(flag==2){
				if(min>i-prev)
					min=i-prev;
			}
			prev=i;
			flag=1;
		}else if(a[i]==y){
			if(flag==1){
				if(min>i-prev)
					min=i-prev;
			}
			prev=i;
			flag=2;
		}
		i++;
	}
	if(min==INT_MAX)
		return -1;
	return min;
}
int main(){
	int a[]={3,5,4,2,6,5,6,6,5,4,8,3};
	int x,y;
	x=3;
	y=6;
	//int a[]={2,5,3,5,4,4,2,3};
	//int x=3;
	//int y=2;
	int n=sizeof(a)/sizeof(a[0]);
	int min_res=findMin(a,n,x,y);
	printf("\nMin dist=%d",min_res);
	printf("\n");
	return 0;
}
