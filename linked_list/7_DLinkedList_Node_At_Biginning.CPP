#include<iostream>

using namespace std;
//Doubly Link List 1
//Insertion at the beginning and print
class Node
{
	int data;
	Node* prev;
	Node* next;
	public:
	void insert(int);
	void print();
};
Node* head;
void Node::insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	if(head == NULL)
	{
		temp->prev = NULL;
		temp->next = NULL;
		head = temp;
		return;
	}
	head->prev = temp;// Always work in this way for Doubly Link List.
	temp->prev = NULL;
	temp->next = head;
	head = temp;
}
void Node::print()   // same as Singly Linked List
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
	Node* dll;
	head = NULL;
	dll->insert(2);// 2
	dll->insert(4);// 4 2
	dll->insert(6);// 6 4 2
	dll->insert(8);// 8 6 4 2
	dll->print();// 8 6 4 2 // Insertion at the beginning .
	return 0;
}
