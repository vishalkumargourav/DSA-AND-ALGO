/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	REVERSE ALTERNATE LEVELS OF BINARY TREE
*/
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<stack>
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
void postorder(node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
stack<node *> s;
void reverseAlterUtil(node *root,int level){
	if(NULL==root)
		return;
	reverseAlterUtil(root->left,level+1);
	if(level%2==1)
		s.push(root);
	reverseAlterUtil(root->right,level+1);
}
void fillAlter(node *root,int level){
	if(NULL==root)
		return;
	fillAlter(root->left,level+1);
	if(level%2==1){
		root->data=s.top()->data;
		s.pop();
	}
	fillAlter(root->right,level+1);
}
void reverseAlter(node *root){
	reverseAlterUtil(root,0);
	fillAlter(root,0);
}
int main(){
	node *root1=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	root1->right->left=createNode(6);
	root1->right->right=createNode(7);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);
	reverseAlter(root1);
	printf("\nInorder traversal of the tree is:");
	inorder(root1);		
	printf("\n");
	return 0;
}
