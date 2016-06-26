/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	CHECK IF THE GIVEN TWO TREES HAVE LEAVES IN SAME ORDER
*/
using namespace std;
#include<cstdio>
#include<stack>
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
int isLeaf(node *root){
	return root->left==NULL && root->right==NULL;
}
int sameLeaves(node *root1,node *root2){
	node *temp1,*temp2;
	if(NULL==root1 && NULL==root2)
		return 1;
	if(NULL==root1 || NULL==root2)
		return 0;
	stack<node *> s1,s2;
	s1.push(root1);
	s2.push(root2);
	while(!s1.empty() || !s2.empty()){
		if(s1.empty() || s2.empty())	
			return 0;
		temp1=s1.top();
		s1.pop();
		while(temp1!=NULL && !isLeaf(temp1)){
			if(temp1->right!=NULL)
				s1.push(temp1->right);
			if(temp1->left!=NULL)
				s1.push(temp1->left);
			temp1=s1.top();
			s1.pop();
		}
		temp2=s2.top();
		s2.pop();
		while(temp2!=NULL && !isLeaf(temp2)){
			if(temp2->right)
				s2.push(temp2->right);
			if(temp2->left)
				s2.push(temp2->left);
			temp2=s2.top();
			s2.pop();
		}
		if(temp1==NULL && temp2!=NULL)
			return 0;
		if(temp1!=NULL && temp2==NULL)
			return 0;
		if(temp1->data!=temp2->data)
			return 0;
	}
	return 1;
}
int main(){
	node *root1=NULL,*root2=NULL;
	root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->right->left=createNode(6);
	root1->right->right=createNode(7);
	
	root2=createNode(0);
	root2->left=createNode(1);
	root2->right=createNode(5);
	root2->left->right=createNode(4);
	root2->right->left=createNode(7);
	root2->right->right=createNode(6);
	
	
	if(sameLeaves(root1,root2))
		printf("\nYes they have leaves in same order");
	else
		printf("\nNo they do not have leaves in same order");
	printf("\n");
	return 0;
}




