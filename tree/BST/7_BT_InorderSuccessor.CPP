#include<conio.h>
#include<iostream.h>
// Finding the InOrder Successor of BT which is a BST .
// TC stands for Time Complexity .
class BtNode
{
	int data;
	public:
	BtNode* left;
	BtNode* right;
	BtNode* insert( int );
	void inorder( BtNode* );// TC = O(n) where n is the no. of nodes .
	BtNode* findNode( BtNode* , int );// TC = O(h(tree))
	BtNode* findMin( BtNode* );// TC = O(h(tree))
//Returning the addresse of min data node on left subtree for a given node .
	int getInorderSuccessor( BtNode* , int );
};

BtNode* BtNode::insert( int x )
{
	BtNode* temp = new BtNode();
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BtNode::inorder( BtNode* root )
{
	if( root == NULL )
		return;
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );

}

BtNode* BtNode::findMin( BtNode* root )
{
	if( root == NULL )
		return NULL;
	else if( root->left == NULL )
		return root;
	else
		return findMin( root->left );
}

BtNode* BtNode::findNode( BtNode* root , int x )
{
	if( root == NULL )
		return NULL;
	else if( x == root->data )
		return root;
	else if( x < root->data )
		return findNode( root->left , x );
	else
		return findNode( root->right , x );

}

int BtNode::getInorderSuccessor( BtNode* root , int x )
{
	BtNode* current = findNode( root , x );
	if( current == NULL )
		return NULL;
	// case 1 : if a given node has a right subtree .
	else if( current->right != NULL )
		return findMin( current->right )->data;
	// case 2 : if a given node has no right subtree
	else
	{
		BtNode* successor = NULL;
		BtNode* ancestor = root;
		while( current != ancestor )// walking ->TC = O(h(tree))
		{
			if( current->data < ancestor->data )//for BST left
			{				      // subtree .
			  successor = ancestor ;
			  ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right ;
		}
		return successor->data;
	}
}

int main()
{
	clrscr();
	BtNode* root = NULL;
	BtNode* bt;
	// Strickly a BST .
	root = bt->insert(15);
	root->left = bt->insert(10);
	root->right = bt->insert(20);
	root->left->left = bt->insert(8);
	root->left->right = bt->insert(12);
	root->left->left->left = bt->insert(6);
	root->left->right->left = bt->insert(11);
	root->right->left = bt->insert(17);
	root->right->right = bt->insert(25);
	root->right->left->left = bt->insert(16);
	root->right->right->right = bt->insert(27);
	bt->inorder( root );
	cout<<"\nInOrder Successor of 8 : "<<bt->getInorderSuccessor( root , 8 )<<"\n";
	cout<<"Inorder Successor of 12 : "<<bt->getInorderSuccessor( root , 12 )<<"\n";
	getch();
	return 0;
}
