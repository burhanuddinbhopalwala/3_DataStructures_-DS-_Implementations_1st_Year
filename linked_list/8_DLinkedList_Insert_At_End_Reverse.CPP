#include<iostream>

using namespace std;
// Doubly Link List
// Insertion at the end and Print in forward and reverse manner .
class Node
{
	int data;
	Node* prev;
	Node* next;
	public:
	void insert(int);
	void print();
	void printr();
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
void Node::printr()
{
	Node* temp = head;
	while(temp != NULL)
	{
		if(temp->next == NULL)
		{
			while(temp != NULL)
			{
				cout<<" "<<temp->data;
				temp = temp->prev;
			}
			return;
		}
		temp = temp->next;
	}
	cout<<"\n";
}
int main()
{
	Node* dllist;
	head = NULL;
	dllist->insert(2);
	dllist->insert(4);
	dllist->insert(6);
	dllist->insert(8);
	dllist->print(); // 2 4 6 8
	dllist->printr();// 8 6 4 2
	return 0;
}
