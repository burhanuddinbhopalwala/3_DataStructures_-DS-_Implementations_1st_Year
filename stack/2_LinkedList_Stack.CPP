#include<conio.h>
#include<iostream.h>
// Stack 2
// Stack implementation using the Linked List .
// A Linked List with insertion and deletion perform from the beginning is Stack.
class Node
{
	int data;
	Node* next;
	public:
	void insert(int); // push function of stack // insert at beginning
	void del();// pop function of stack // delete at beginning
	void print();
};
Node* head;
void Node::insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}
void Node::del()
{
	Node* temp = head;
	head = temp->next;
	delete temp;
}
void Node::print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->next;
	}
	cout<<"\n";
}
int main()
{
	clrscr();
	Node* llist;
	head = NULL;
	llist->insert(2);
	llist->insert(4);
	llist->insert(6);
	llist->insert(8);
	llist->print();// 8 6 4 2
	llist->del();
	llist->del();
	llist->print();// 4 2
	getch();
	return 0;
}