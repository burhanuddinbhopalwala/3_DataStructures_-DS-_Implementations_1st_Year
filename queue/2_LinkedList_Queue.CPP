#include<conio.h>
#include<iostream.h>
// Implementation of Queue using Linked List .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int); //  insertion at tail or rear end ;
	void del(); // deletion at beginning or front end ;
	int frnt();
	void print();
};

Node* front ; // or head
Node* rear ;

void Node::insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL ; // insertion always at tail , rear end .

	if( front == NULL && rear == NULL ) // front == rear == NULL
	{                                  // THEN NOT WORKING
		front = rear = temp;
		return;
	}

			rear->next = temp;
			rear = temp;


}

void Node::del()
{
	Node* temp = front;

	if( front == NULL && rear == NULL )// front == rear == NULL
		return;                    // THEN NOT WORKING

	else if( front == rear )
		front = rear = NULL;
	else
	     front = front->next;

	     delete(temp); // explicitly delete from dynamic memory or heap.
}

int Node::frnt()
{
	return front->data;
}

void Node::print()
{
	Node* temp = front;
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
	Node* n;
	front = NULL;
	rear = NULL;
	n->insert(2);
	n->insert(4);
	n->insert(6);
	n->print(); // 2 4 6
	cout<<n->frnt()<<"\n"; // 2
	n->del();
	n->del();
	n->print(); // 6
	getch();
	return 0;
}