#include<iostream>

using namespace std;
//Linked List 3
//Insertion at end .
//Delete the node from nth position .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void del(int);
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
void Node::del(int n)
{
	Node* temp1 = head;
	if(n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}
	for(int i=0 ; i<n-2 ; i++)
		temp1 = temp1->next;
	Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
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
	llist->print();
	llist->del(1);
	llist->print();// 4 6 8
	llist->del(2);
	llist->print();// 4 8
	return 0;
}
