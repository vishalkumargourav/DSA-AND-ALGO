/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CONSTRUCT A TREE FROM ANCESTOR MATRIX
*/
#include<bits/stdc++.h>
using namespace std;
#define N 6
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
node *construct(int mat[][N]){
	node *root=NULL;
	int parent[N]={0};
	multimap<int,int> mm;
	int i , j;
	for(i=0;i<N;i++){
		int sum=0;
		for(j=0;j<N;j++)
			sum+=mat[i][j];
		mm.insert(pair<int ,int>(sum,i));
	}
	node *nodes[N];
	for(i=0;i<N;i++)
		nodes[i]=NULL;
	for(multimap<int,int>::iterator it=mm.begin();it!=mm.end();++it){
		nodes[it->second]=createNode(it->second);
		root=nodes[it->second];
		printf("\nFor : %d\n",it->second);
		if(it->first!=0){
			for(i=0;i<N;i++){
				if(!parent[i] && mat[it->second][i]){
					if(nodes[i]->left==NULL){
						printf("\nMaking %d as left child of %d",nodes[i]->data,nodes[it->second]->data);
						nodes[it->second]->left=nodes[i];
					}else{
						printf("\nMaking %d as right child of %d",nodes[i]->data,nodes[it->second]->data);
						nodes[it->second]->right=nodes[i];
					}
					parent[i]=1;
				}
			}
		}
	}
	return root;
}
int main(){
	int mat[N][N]={
		{0,0,0,0,0,0},
		{1,0,0,0,1,0},
		{0,0,0,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{1,1,1,1,1,0}
	};
	node *root=construct(mat);
	printf("\nInorder traversal is:");
	inorder(root);
	printf("\n");
	return 0;
}
