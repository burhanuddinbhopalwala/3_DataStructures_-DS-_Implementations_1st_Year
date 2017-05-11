#include<conio.h>
#include<iostream.h>
// Finding the Min and Max of BST using Recursion .
// And the Height of BST using Recursion .
class BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
	public:
	BstNode* insert( BstNode* , int );
	int findMinimum( BstNode* );
	int findMaximum( BstNode* );
	int findHeight( BstNode* );
};

BstNode* BstNode::insert( BstNode* root , int x )
{
	if( root == NULL ) // Exit condition from recursion .
	{
		root = new BstNode();
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}

	else if( x <= root->data )
		root->left = insert( root->left , x );

	else
		root->right = insert( root->right , x);

	return root;
}

int BstNode::findMinimum( BstNode* root )
{
	if( root == NULL ) // Exit condition from recursion .
		return -1; //for empty tree

	else if( root->left == NULL )
		return root->data;

	else return findMinimum( root->left ); // keep on searching on
}                                                            //left subtree.

int BstNode::findMaximum( BstNode* root )
{
	if( root == NULL ) // Exit condition from recursion .
		return -1;//for empty tree

	else if( root->right == NULL )
		return root->data;

	else return findMaximum( root->right );// Keep on searching on
}						//right subtree.

int BstNode::findHeight( BstNode* root )
{
	if( root == NULL ) // Exit condition from recursion .
		return -1; // Height of empty tree is -1 ;

	int left_height = findHeight( root->left );
	int right_height = findHeight( root->right );

	if( left_height > right_height )
		return ( left_height + 1 );

	else
		return ( right_height + 1 );
/* NOTE : We are counting number of edges here so we have to add 1 edge from
root node to right or left subtree node accordingly because we start  the
counting/recursion from left subtree node and right subtree node accordingly .*/
}

int main()
{
	clrscr();
	BstNode* root = NULL;
	BstNode* bst;
	root = bst->insert(root , 100);
	root = bst->insert(root , 200);
	root = bst->insert(root , 300);
	root = bst->insert(root , 400);
	root = bst->insert(root , 90);
	root = bst->insert(root , 80);
	root = bst->insert(root , 70);
	root = bst->insert(root , 60);
	cout<<"Minimum of bst tree : "<<bst->findMinimum( root )<<"\n";
	cout<<"Maximum of bst tree : "<<bst->findMaximum( root )<<"\n";
	cout<<"Bst Height : "<<bst->findHeight( root )<<"\n";
	getch();
	return 0;
}