/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GENERATE ANCESTOR MATRIX FROM GIVEN BINARY TREE
*/
using namespace std;
#include<cstdlib>
#include<cstdio>
#include<vector>
#define MAX 100
typedef struct node{
	int data;
	struct node *left,*right;
}node;
node *createNode(int data){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void preorder(node *root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int mat[MAX][MAX];
int fillMatrix(node *root,vector<int> *v){
	if(NULL==root)
		return 0;
	int i;
	for(i=0;i<(*v).size();i++)
		mat[(*v)[i]][root->data]=1;
	(*v).push_back(root->data);
	int l=fillMatrix(root->left,v);
	int r=fillMatrix(root->right,v);
	(*v).pop_back();
	return l+r+1;
}
void ancestor(node *root){
	if(NULL==root)
		return;
	vector<int> v;
	int n=fillMatrix(root,&v);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}
int main(){
	node *root;
	root=createNode(5);
	root->left=createNode(1);
	root->right=createNode(2);
	root->left->left=createNode(0);
	root->left->right=createNode(4);
	root->right->left=createNode(3);
	//printf("\nInorder traversal of the tree is:");
	//inorder(root);
	ancestor(root);
	printf("\n");
	return 0;
}
