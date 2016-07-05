/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	MAXIMUM SUM PATH IN TWO ARRAYS
*/
#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int maxSum(int *a1,int *a2,int n1,int n2){
	int sum1,sum2,res;
	sum1=sum2=res=0;
	int i1,i2;
	i1=i2=0;
	while(i1<n1 && i2<n2){
		if(a1[i1]==a2[i2]){
			res+=max(sum1,sum2)+a1[i1];
			i1++;
			i2++;
			sum1=sum2=0;
		}else if(a1[i1]<a2[i2]){	
			sum1+=a1[i1];
			i1++;
		}else{ 
			sum2+=a2[i2];
			i2++;
		}
	}
	while(i1<n1){
		sum1+=a1[i1++];
	}
	while(i2<n2){
		sum2+=a2[i2++];
	}
	res+=max(sum1,sum2);
	return res;
}
int main(){
	//int a1[]={2,3,7,10,12};
	//int a2[]={1,5,7,8};
	
	//int a1[]={10,12};
	//int a2[]={5,7,9};
	
	int a1[]={2,3,7,10,12,15,30,34};
	int a2[]={1,5,7,8,10,15,16,19};
	
	int n1=sizeof(a1)/sizeof(a1[0]);
	int n2=sizeof(a2)/sizeof(a2[0]);
	printf("\nMaximum sum is:%d",maxSum(a1,a2,n1,n2));
	printf("\n");
	return 0;
}
