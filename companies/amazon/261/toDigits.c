/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONVERT A NUMERIC VALUE TO WORDS
*/
#include<stdio.h>
#include<math.h>
char *hash1[]={"","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};

char *hash3[]={"tens","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
char *hash4[]={"hundred","thousands","lakhs","crores"};

int countDigits(int n){
	int i=0;
	while(n!=0){
		i++;
		n/=10;
	}
	return i;
}

void toWords(int n){
	int t3;
	int d;
	int digits=countDigits(n);
	while(digits>3){
		d=0;
		if(digits&1){
			t3=digits/2-1;
			d=n/((int)pow(10,digits-1));
			n%=(int)pow(10,digits-1);
			digits--;
			d*=10;
			d+=n/((int)pow(10,digits-1));
			n%=(int)pow(10,digits-1);
			digits--;
		}else{
			t3=digits/2-1;
			d=n/((int)pow(10,digits-1));
			n%=(int)pow(10,digits-1);
			digits--;
		}
		if(d<=20 && d!=0){
			printf("%s %s ",hash1[d],hash4[t3]);
		}else if(d!=0)
			printf("%s %s %s ",hash3[d/10-1],hash1[d%10],hash4[t3]);
	}
	if(digits==3){
		d=n/100;
		if(d!=0)
			printf("%s hundreds ",hash1[d]);
		n=n%100;
		if(n!=0){
			if(n<=20)
				printf("%s",hash1[n]);
			else
				printf("%s %s",hash3[n/10-1],hash1[n%10]);
		}
	}
}
int main(){
	//int n=1234;
	int n=1234567;
	toWords(n);
	printf("\n");
	return 0;
}
