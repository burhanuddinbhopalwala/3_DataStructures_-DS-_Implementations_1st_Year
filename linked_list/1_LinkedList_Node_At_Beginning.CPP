#include<iostream>

using namespace std;
// Linked List 1
//Inserting the node at the beginning .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int);
	void print();
};
Node* head; // Global Variable.
void Node::insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}
void Node::print()
{
	Node* temp = head;
	cout<<"List is : ";
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
	int num , value;
	cout<<"How many numbers you want in the List : ";
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		cout<<"\nEnter the value : ";
		cin>>value;
		llist->insert(value);
		llist->print();
	}
	return 0;
}
