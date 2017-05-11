#include<conio.h>
#include<iostream.h>
#include<limits.h>
// Checking weather the BT is BST or not .
// Correct and Efficient Algorithm .
class BtNode
{
	int data;
	public:
	BtNode* left;
	BtNode* right;
	BtNode* insert( int );
	int isBst( BtNode* );
	int isBstUtil( BtNode* , int , int );
};

BtNode* BtNode::insert( int x )
{
	BtNode* temp = new BtNode();
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int BtNode::isBst( BtNode* root )
{
	return isBstUtil( root , INT_MIN , INT_MAX );
}
// pass temp as root either root is global otherwise it creates problem in
// Recursion .
int BtNode::isBstUtil(BtNode* root , int min , int max)
{
	if( root == NULL )
		return 1;

	if( root->data > min
	&& root->data < max
	&& isBstUtil( root->left , min , root->data )
	&& isBstUtil( root->right , root->data , max) )
		return 1;
	return 0;
}

int main()
{
	clrscr();
	BtNode* root = NULL;
	BtNode* bt;
	root = bt->insert(7);
	root->left = bt->insert(4);
	root->right = bt->insert(9);
	root->left->left = bt->insert(1);
	root->left->right = bt->insert(6);
	if ( bt->isBst( root ))
	cout<<"It is BST" ;
	else
	cout<<"Not a BST";
	getch();
	return 0;
}
/*
NOTE : Another Algorithm for checking isBST is that take inorder traversal
BT and if it is sorted form then it is a BST .
*/



