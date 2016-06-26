/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	FOR A PERFECT BINARY TREE DO A SPECIAL LEVEL ORDER TRAVERSAL
*/
using namespace std;
#include<cstdio>
#include<queue>
#include<cstdlib>
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
void perfectLevel(node *root){
	if(NULL==root)
		return;
	queue<node *> q;
	node *temp1,*temp2;
	printf("%d ",root->data);
	q.push(root->left);
	q.push(root->right);
	while(!q.empty()){
		temp1=q.front();
		q.pop();
		temp2=q.front();
		q.pop();
		printf("%d %d ",temp1->data,temp2->data);
		if(temp1->left)
			q.push(temp1->left);
		if(temp2->right)
			q.push(temp2->right);
		if(temp1->right)
			q.push(temp1->right);
		if(temp2->left)
			q.push(temp2->left);
	}
}
int main(){
	node *root1=NULL,*root2=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	root1->right->left=createNode(6);
	root1->right->right=createNode(7);
	root1->left->left->left=createNode(8);
	root1->left->left->right=createNode(9);
	root1->left->right->left=createNode(10);
	root1->left->right->right=createNode(11);
	root1->left->left->left->left=createNode(16);
	root1->left->left->left->right=createNode(17);
	root1->left->left->right->left=createNode(18);
	root1->left->left->right->right=createNode(19);
	root1->left->right->left->left=createNode(20);
	root1->left->right->left->right=createNode(21);
	root1->left->right->right->left=createNode(22);
	root1->left->right->right->right=createNode(23);
	root1->right->left->left=createNode(12);
	root1->right->left->right=createNode(13);
	root1->right->left->left->left=createNode(24);
	root1->right->left->left->right=createNode(25);
	root1->right->left->right->left=createNode(26);
	root1->right->left->right->right=createNode(27);
	root1->right->right->left=createNode(14);
	root1->right->right->right=createNode(15);
	root1->right->right->left->left=createNode(28);
	root1->right->right->left->right=createNode(29);
	root1->right->right->right->left=createNode(30);
	root1->right->right->right->right=createNode(31);
	printf("\nSpecial level order traversal is:");
	perfectLevel(root1);
	printf("\n");
	return 0;
}
