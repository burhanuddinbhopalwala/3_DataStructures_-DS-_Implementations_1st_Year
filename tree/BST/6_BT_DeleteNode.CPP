#include<conio.h>
#include<iostream.h>
#include<queue.h>
// Delete a node from BT tree which is a BST .
class BtNode
{
	int data;
	public:
	BtNode* left;
	BtNode* right;
	BtNode* insert( int );
	void levelOrder( BtNode* );
	BtNode* findMin( BtNode* );
//Returning the addresse of min data node on left subtree for a given node .
	BtNode* del( BtNode* , int );
};

BtNode* BtNode::insert( int x )
{
	BtNode* temp = new BtNode();
	temp->data = x ;
	temp->left = NULL ;
	temp->right = NULL ;
	return temp;
}

void BtNode::levelOrder( BtNode* root )
{
	if( root == NULL )
		return;

	Queue<BtNode*> q;
	q.enQueue(root);

	while( ! q.isEmpty() )
	{
		BtNode* current = q.front();
		cout<<current->data<<" ";
		q.deQueue();

		if( current->left != NULL )
			q.enQueue(current->left);

		if(current->right != NULL )
			q.enQueue(current->right);
	}
}

BtNode* BtNode::findMin( BtNode* root )
{
//Returning the addresse of min data node on left subtree for a given node .
	if( root == NULL )
		return NULL;

	else if( root->left == NULL )
		return root;

	else
	return findMin( root->left );
}

BtNode* BtNode::del( BtNode* root , int x )
{
	if( root == NULL )
		return root; // Exit Condition from Recursion .
	else if( x < root->data )
		root->left = del( root->left , x );
	else if( x > root->data )
		root->right = del( root->right , x );

	else // finding the Node lets delete it .
	{
		if( root->left == NULL && root->right == NULL )
		{
			delete( root );
			root = NULL; // removing the stored addresses .
		}

		else if( root->left == NULL )
		{
			BtNode* temp = root ;
			root = root->right ; // building the link .
			delete temp ;
		}

		else if( root->right == NULL )
		{
			BtNode* temp = root;
			root = root->left;
			delete temp;
		}

		else // Node having children
		{
			BtNode* temp = findMin( root->right );//Min of
			root->data = temp->data;          //right subtree .
			root->right = del( root->right , temp->data );
		}       // building the link in the above statement .
	}
	return root;
}

int main()
{
	clrscr();
	BtNode* root = NULL;
	BtNode* bt;
	// Strickly insert the values for an BST .
	root = bt->insert(12);
	root->left = bt->insert(5);
	root->right = bt->insert(15);
	root->left->left = bt->insert(3);
	root->left->right = bt->insert(7);
	root->left->left->left = bt->insert(1);
	root->left->left->right = bt->insert(9);
	root->left->left->right->left = bt->insert(8);
	root->left->left->right->right = bt->insert(11);
	root->right->left = bt->insert(13);
	root->right->right = bt->insert(17);
	root->right->left->right = bt->insert(14);
	root->right->right->right = bt->insert(20);
	root->right->right->right->left = bt->insert(19);
	cout<<"Before Deletion in BST : \n";
	bt->levelOrder( root );
	bt->del( root , 15 );
	cout<<"\n\nAfter Deleting 15 from BST : \n";
	bt->levelOrder( root );
	getch();
	return 0;
}