/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT TOP VIEW OF THE BINARY TREE
*/
#include<cstdio>
using namespace std;
#include<queue>
#include<cstdlib>
#include<climits>
#define NOT_ASSIGN -999
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *createNode(int data){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void updateMinMax(Node *root,int *min,int *max,int i){
	if(NULL==root)	
		return;
	if(i<*min)
		*min=i;
	if(i>*max)
		*max=i;
	updateMinMax(root->left,min,max,i-1);
	updateMinMax(root->right,min,max,i+1);
}
typedef struct Node_q{
	Node *data;
	int dist;
}Node_q;
void fillTopView(Node *root,int *left,int *right,int i){
	queue<Node_q> q;
	Node_q temp,temp1;
	Node_q MARKER={createNode(-999),-999};
	temp.data=root;
	temp.dist=0;
	q.push(temp);
	q.push(MARKER);
	while(!q.empty()){
		while(q.front().data->data!=-999){
			temp=q.front();
			//printf("\nTop element is:%d",temp.data->data);
			if(temp.dist>=0 && right[temp.dist]==NOT_ASSIGN)
				right[temp.dist]=temp.data->data;
			if(temp.dist<0 && left[abs(temp.dist)]==NOT_ASSIGN)
				left[abs(temp.dist)]=temp.data->data;
			if(temp.data->left){
				temp1.dist=temp.dist-1;
				temp1.data=temp.data->left;
				q.push(temp1);
			}
			if(temp.data->right){
				temp1.dist=temp.dist+1;
				temp1.data=temp.data->right;
				q.push(temp1);
			}
			q.pop();
		}
		q.pop();
		if(!q.empty())
			q.push(MARKER);
	}
}
void printTopViewUtil(int *left,int min,int *right,int max){
	int i;
	for(i=abs(min);i>0;i--)
		printf("%d ",left[i]);
	for(i=0;i<=max;i++)
		printf("%d ",right[i]);
}
void printTopView(Node *root){
	int max=INT_MIN;
	int min=INT_MAX;
	updateMinMax(root,&min,&max,0);
	int *right=(int*)malloc(sizeof(int)*(max+1));
	int i;
	for(i=0;i<=max;i++)
		right[i]=NOT_ASSIGN;
	int *left=(int*)malloc(sizeof(int)*(abs(min)+1));
	for(i=0;i<=abs(min);i++)
		left[i]=NOT_ASSIGN;
	fillTopView(root,left,right,0);
	printf("\nTop view is:");
	printTopViewUtil(left,min,right,max);
}
void inorder(Node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main(){
	Node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->left->left->left=createNode(6);
	root->left->left->right=createNode(7);
	root->left->right->right=createNode(8);
	root->right->left=createNode(9);
	root->right->right=createNode(10);
	root->right->right->left=createNode(11);
	//printf("\nINORDER:");
	//inorder(root);
	printTopView(root);
	printf("\n");
	return 0;
}
