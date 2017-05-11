#include<iostream>

using namespace std;
// Linked List 5
// Reverse Linked List Recursive Method .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void reverse(Node* p);
	void print();
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
			return;
		}
		temp2 = temp2->next;
	}
}
void Node::reverse(Node* p)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	reverse(p->next);
	// rest statements are executed after p->next == NULL reach .
	// Number of times as the function call are save in the memory.
	Node* q = p->next; // p->next->next = p;
	q->next = p;
	p->next = NULL;
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
	Node* llist;
	head = NULL;
	llist->insert(2);
	llist->insert(4);
	llist->insert(6);
	llist->insert(8);
	llist->print();// 2 4 6 8
	llist->reverse(head);
	llist->print();// 8 6 4 2
	return 0;
}
