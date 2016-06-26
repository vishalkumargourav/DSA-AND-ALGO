/*
	AUTHOR	:	VISHAL KUMAR GOURAV <vishal.vs911@gmail.com>
	PROBLEM	:	FIND Nth NUMBER THAT CAN BE FORMED WITH 3 AND 4
	
	OBSERVATIONS:
			i)Number at ith index contains log2(i+2) digits
			ii)Bits can easily be used to mock for 3 and 4
	ALGORITHM:
			i)Count the number of digits that would be in output
			ii)make a array of that many elements
			ii)Count the difference b/w actual number and number formed 
			when we raise 2 to the power of number of digits in output
			iii)for that difference update the auxiliary array as done in loop
			iv)traverse auxiliary array if you see a 0 then print 3 else print 4
	EXAMPLE	:	
			i)  Consider n=20
			ii) number of digits in output would be log2(20+2)=4
			iii)make a auxiliary array of 4 digits and initilize all elements to be 0
			iv) now calculate how much far we are from our ans, in this case it would be
			    (20+2)-pow(2,4)=6
			v)  bit representation of 6 is 0110, making it to 4 digits because our
			    output contains 4 digits
			vi) now for every set bit in this representaion of 6 , set the corresponding bit
			    of auxiliary array
			vii)In this case our auxiliary array would become 0110
			viii)traverse auxiliary array if you see a 0 then print 3 else print 4
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void printNumber(int n){
	//here k is the number of digits that would be in output
	int k=log2(n),i,n1;
	//counting how much far we are from required number
	n1=n-pow(2,k);
	//creating a auxiliary array in this array if a element at index i
	//is 0 then we will output 3 else if it is 1 we will output 4
	int *a=(int*)calloc(sizeof(int),k);
	i=k-1;
	while(n1>0){
		if(n1&1)
			a[i]=1;
		n1>>=1;
		i--;
	}
	for(i=0;i<k;i++){
		if(a[i]==0)
			printf("3");
		else
			printf("4");
	}
}
int main(){
	int n;
	int i;
	for(n=0;n<=20;n++){
		printf("\n%dth 3 and 4 is:",n);
		printNumber(n+2);
	}
	printf("\n");
	return 0;
}
