/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONNECT NODES AT SAME LEVEL
*/
#include<iostream>
using namespace std;
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<climits>
typedef struct node{
	int data;
	struct node *left,*right,*next;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=temp->next=NULL;
	return temp;
}
node *insert(node *root,int data){
	if(NULL==root)
		return createNode(data);
	if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void inorder(node *root){
	if(NULL==root)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(node *root){
	if(NULL==root)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void connectLevel(node *root){
	if(NULL==root)
		return;
	queue<node *> q;
	q.push(root);
	node *prev,*temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		prev=NULL;
		while(temp){
			if(prev){
				if(temp->left){
					prev->next=temp->left;
					q.push(temp->left);
					prev=temp->left;
				}
				if(temp->right){
					prev->next=temp->right;
					q.push(temp->right);
					prev=temp->right;
				}
			}else{
				if(temp->left){
					q.push(temp->left);
					prev=temp->left;
				}
				if(temp->right && prev){
					prev->next=temp->right;
					q.push(temp->right);
					prev=temp->right;
				}else if(temp->right){
					q.push(temp->right);
					prev=temp->right;
				}
			}
			temp=temp->next;
			if(temp)
				q.pop();
		}
	}
}
void printLevelWise(node *root,int i){
	static int max=INT_MIN;
	node *temp;
	if(NULL==root)
		return;
	if(i>max){
		max=i;
		temp=root;
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printLevelWise(root->left,i+1);
	printLevelWise(root->right,i+1);
}
int main(){
	node *root1=NULL;
	int i,n;
	int a[]={20,8,22,4,12,21,10,14};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
		root1=insert(root1,a[i]);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	connectLevel(root1);
	printf("\nLevel order traversal is:");
	printLevelWise(root1,1);
	printf("\n");
	return 0;
}
