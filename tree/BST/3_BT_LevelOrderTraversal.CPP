#include<iostream>
#include<queue.h>

using namespace std;
// Level Order Tranversel of Binary Tree .
// We will take root variable as local variable for BT/BST always for smplcty.
class BtNode
{
	char data;
	public:
	BtNode* left;
	BtNode* right;
	BtNode* insert( char );
	void levelOrder( BtNode* );
};

BtNode* BtNode::insert( char c )
{
	BtNode* temp = new BtNode();
	temp->data = c;
	temp->left = NULL;
	temp->right = NULL;
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
		BtNode* current = q.front(); // storing the addresses .
		cout<<current->data<<" ";
		q.deQueue();

		// storing the addresses/refrences of the childrens .
		if( current->left != NULL )
			q.enQueue( current->left );

		if( current->right != NULL )
			q.enQueue( current->right );

	}
}

int main()
{
	BtNode* root = NULL;
	BtNode* bt;
	root = bt->insert('a');
	root->left = bt->insert('b');
	root->right = bt->insert('c');
	root->left->left = bt->insert('d');
	root->left->right = bt->insert('e');
	root->right->left = bt->insert('f');
	root->right->right = bt->insert('g');
	bt->levelOrder( root );
	return 0;
}
