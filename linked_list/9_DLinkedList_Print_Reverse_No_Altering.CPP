#include<iostream>

using namespace std;
// Doubly Link List
// Print in forward and reverse manner using recursion without Altering the List .
class Node
{
	int data;
	Node* prev;
	Node* next;
	public:
	void insert(int);
	void print(Node*);   // Same as Singly Linked List
	void printr(Node*);  // Same as Singly Linked List
};
Node* head;
void Node::insert(int x)
{
	Node* temp1 = new Node();
	temp1->data = x;
	if(head == NULL)
	{
		temp1->prev = NULL;
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
			temp1->prev = temp2;
			temp1->next = NULL;
			return;
		}
		temp2 = temp2->next;
	}
}
void Node::print(Node* p)
{
	if(p == NULL)// Exit Condition
	{
		cout<<"\n";
		return;
	}
	cout<<" "<<p->data;
	print(p->next);
}
void Node::printr(Node* p)
{
	if(p == NULL) // Exit Condition
	{
		cout<<"\n";
		return;
	}
	printr(p->next);
	cout<<" "<<p->data;
}
int main()
{
	Node* dllist;
	head = NULL;
	dllist->insert(2);
	dllist->insert(4);
	dllist->insert(6);
	dllist->insert(8);
	dllist->print(head); // 2 4 6 8
	dllist->printr(head); // 8 6 4 2
	return 0;
}
