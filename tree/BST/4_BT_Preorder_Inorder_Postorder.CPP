#include<conio.h>
#include<iostream.h>
#include<queue.h>
// Preorder , Inorder , Postorder transversal of a Binary Tree .
class BtNode
{
	char data;
	public:
	BtNode* left;
	BtNode* right;
	BtNode* insert( char );
	void preorder( BtNode* );
	void inorder( BtNode* );
	void postorder( BtNode* );
};

BtNode* BtNode::insert( char c )
{
	BtNode* temp = new BtNode();
	temp->data = c;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BtNode::preorder( BtNode* root )
{
	if( root == NULL )
		return ; // Exit condition from Recursion .

	cout<<root->data<<" ";
	preorder( root->left );
	preorder( root->right );
}

void BtNode::inorder( BtNode* root )
{
	if( root == NULL )
		return; // Exit condition from Recursion .
	inorder( root->left );
	cout<<root->data<<" ";
	inorder( root->right );
}

void BtNode::postorder( BtNode* root )
{
	if( root == NULL )// Exit condition from Recursion .
		return;
	postorder( root->left );
	postorder( root->right );
	cout<<root->data<<" ";
}
int main()
{
	clrscr();
	BtNode* root = NULL;
	BtNode* bt;
	root = bt->insert('f');
	root->left = bt->insert('d');
	root->right = bt->insert('j');
	root->left->left = bt->insert('b');
	root->left->right = bt->insert('e');
	root->left->left->left = bt->insert('a');
	root->left->left->right = bt->insert('c');
	root->right->left = bt->insert('g');
	root->right->right = bt->insert('k');
	root->right->left->right = bt->insert('i');
	root->right->left->right->left = bt->insert('h');
	cout<<"preorder traversal : ";
	bt->preorder( root );
	cout<<"\ninorder traversal : ";
	bt->inorder( root );
	cout<<"\npostorder traversal : ";
	bt->postorder( root );
	getch();
	return 0;
}