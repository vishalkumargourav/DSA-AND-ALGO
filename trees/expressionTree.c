/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A BINARY TREE FIND DIAGONAL SUM OF ALL DIAGONALS
*/
using namespace std;
#include<cstdio>
#include<queue>
#include<cstdlib>
typedef struct node{
	int data,op;
	struct node *left,*right;
}node;
node *createNode(int data,int op){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->op=op;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(node *root){
	if(NULL==root)
		return;
	printf("(");
	inorder(root->left);
	if(!root->op)
		printf("%d ",root->data);
	else{
		if(root->data==1)
			printf("+ ");
		else if(root->data==2)
			printf("- ");
		else if(root->data==3)
			printf("* ");
		else
			printf("/ ");
	}
	inorder(root->right);
	printf(")");
}
void preorder(node *root){
	if(NULL==root)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int evalUtil(int a,int b,int op){
	if(op==1)
		return a+b;
	if(op==2)
		return a-b;
	if(op==3)
		return a*b;
	if(op==4)
		return a/b;
}
int evaluate(node *root){
	if(root->left==NULL && root->right==NULL){
		//i.e. it is operannd and root->op=0
		return root->data;
	}
	int a=evaluate(root->left);
	int b=evaluate(root->right);
	return evalUtil(a,b,root->data);
}
int main(){
	node *root1=NULL,*root2=NULL;
	root1=createNode(1,1);
	root1->left=createNode(3,0);
	root1->right=createNode(3,1);
	root1->right->left=createNode(1,1);
	root1->right->right=createNode(2,0);
	root1->right->left->left=createNode(5,0);
	root1->right->left->right=createNode(9,0);
	printf("\nInorder traversal of the tree is(PREFIX):");
	inorder(root1);
	int ans=evaluate(root1);
	printf("\nAnswer is:%d",ans);
	
	/*char exp[]={}
	node *root2=constructExpressionTree(exp,&i,n);*/
	printf("\n");
	return 0;
}
