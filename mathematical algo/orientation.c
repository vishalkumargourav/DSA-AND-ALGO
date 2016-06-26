/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FIND ORIENTAION OF 3 GIVEN POINTS 
			->CLOCKWISE
			->ANTI-CLOCKWISE
			->COLLENEAR
*/
#include<stdio.h>
typedef struct Point{
	int x,y;
}Point;
int orientation(Point p1,Point p2,Point p3){
	return ((p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x));
}
void printOrientation(Point p1,Point p2,Point p3){
	int res=orientation(p1,p2,p3);
	if(res<0)
		printf("Counter-clockwise");
	if(res>0)
		printf("Clockwise");
	if(res==0)
		printf("Linear");
}
int main(){
	Point p1,p2,p3;
	p1.x=0;
	p1.y=0;
	p2.x=4;
	p2.y=4;
	p3.x=1;
	p3.y=2;
	printf("\nOrientaion is:");
	printOrientation(p1,p2,p3);
	printf("\n");
	return 0;
}
