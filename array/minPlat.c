/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	TRAIN AND PLATFORM PROBLEM
*/
#include<stdio.h>
int cmp(const void *a,const void *b){
	int x=*(int*)a;
	int y=*(int*)b;
	return x-y;
}
int minPlatforms(int *a,int *d,int n){
	qsort(a,n,sizeof(int),cmp);
	qsort(d,n,sizeof(int),cmp);
	int i=1,j=0;
	int max_plat=1;
	int curr_plat=1;
	while(i<n && j<n){
		if(a[i]<d[j]){
			curr_plat++;
			i++;
			if(curr_plat>max_plat)
				max_plat=curr_plat;
		}else{
			j++;
			curr_plat--;
		}
	}
	return max_plat;
}
int main(){
	int a[]={900,940,950,1100,1500,1800};
	int d[]={910,1200,1120,1130,1900,2000};
	int n=sizeof(a)/sizeof(a[0]);
	printf("\nMin platforms needed are:%d",minPlatforms(a,d,n));
	printf("\n");
	return 0;
}
