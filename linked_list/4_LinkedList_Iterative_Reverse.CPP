#include<iostream>

using namespace std;
//Linked List 4
//Reverse the Linked List Iterative Method .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void reverse();
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
void Node::reverse()
{
	Node* current;
	Node* prev;
	Node*  nnext;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		nnext = current->next;
		current->next = prev;
		prev = current;
		current = nnext;
	}
	head = prev; // because prev at last pointing to the last Node .
}                    // which become 1st node after reverse.
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
	llist->reverse();
	llist->print();
	return 0;
}
