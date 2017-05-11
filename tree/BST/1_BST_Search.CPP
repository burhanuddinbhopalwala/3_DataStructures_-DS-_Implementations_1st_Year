#include<conio.h>
#include<iostream.h>
// implementation of BST using Recursion .
// for ease of implemantation we are taking root variable as local variable .
class BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
	public:
	BstNode* insert( BstNode* , int );
	int search( BstNode* , int );
};

BstNode* BstNode::insert( BstNode* root , int x )
{
	if( root == NULL )
	{
		root = new BstNode();
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}

	else if( x <= root->data )
		root->left = insert( root->left , x);

	else
		root->right = insert( root->right , x);
	return root;
}

int BstNode::search( BstNode* root , int x )
{
	if( root == NULL ) return 0;
	else if( x == root->data ) return 1;
	// if not found then searching on left subtree .
	else if( x <= root->data ) return search( root->left , x);
	// else searching on the right subtree .
	else return search( root->right , x );
}

int main()
{
	clrscr();
	BstNode* root = NULL;
	BstNode* bst;
	root = bst->insert(root , 15); // at root tree
	root = bst->insert(root , 10); // at left subtree
	root = bst->insert(root , 20); // at right subtree
	root = bst->insert(root , 25); // at right branch of right subtree.
	root = bst->insert(root , 8); // at left branch of left subtree.
	cout<<bst->search( root , 15 )<<"\n";
	cout<<bst->search( root , 10 )<<"\n";
	cout<<bst->search( root , 20 )<<"\n";
	cout<<bst->search( root , 22)<<"\n";
	cout<<bst->search( root , 8)<<"\n";
	getch();
	return 0;
}