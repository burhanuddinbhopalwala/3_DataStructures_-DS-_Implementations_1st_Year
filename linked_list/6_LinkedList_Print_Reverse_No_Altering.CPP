#include<iostream>

using namespace std;
// Linked List 6
// Printing the Linked List in forward and reverse manner without altering.
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void print(Node*);
	void printr(Node*);
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
	Node* temp2 = head ;
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
void Node::print(Node* p)
{
	if(p == NULL)   //Exit Condition
	{
		cout<<"\n";
		return;
	}
	cout<<" "<<p->data;
	print(p->next);
}
void Node::printr(Node* p)
{
	if(p == NULL)
	{
		cout<<"\n";
		return;
	}
	printr(p->next);
	cout<<" "<<p->data;
}
int main()
{
	Node* llist;
	head = NULL;
	llist->insert(2);
	llist->insert(4);
	llist->insert(6);
	llist->insert(8);
	llist->print(head);// 2 4 6 8
	llist->printr(head);// 8 6 4 2
	return 0;
}
