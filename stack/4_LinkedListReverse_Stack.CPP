#include<conio.h>
#include<iostream.h>
#include<stack.h>
// Reversing the linked list using the stack .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void print();
	void reverse(Node*);
};
Node* head;
void Node::insert(int x)
{
	Node* temp1 = new Node();
	temp1->data = x;
	if(head == NULL)
	{
		temp1->next = NULL;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	while(temp2 != NULL)
	{
		if(temp2->next == NULL)
		{
			temp2->next = temp1;
			temp1->next = NULL;
			return;
		}
		temp2 = temp2->next;
	}
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
void Node::reverse(Node* p)
{
	Stack<Node*> s;
	while(p != NULL)
	{
		s.push(p);  // inserting the full node
		p = p->next;
	}
	Node* temp = s.tope();
	head = temp;
	s.pop();
	while( ! s.isEmpty() )
	{
	   temp->next = s.tope();
	   s.pop();
	   temp = temp->next;
	}
	temp->next = NULL;
}
int main()
{
	clrscr();
	Node* llist;
	head = NULL;
	llist->insert(5);
	llist->insert(10);
	llist->insert(15);
	llist->insert(20);
	llist->print(); // 5 10 15 20
	llist->reverse(head);
	llist->print();// 20 15  10 5
	getch();
	return 0;
}