#include<iostream>

using namespace std;
//Linked List 2
//Inserting the node at nth position .
class Node
{
	int data;
	Node* next;
	public:
	void insert(int , int);
	void print();
};
Node* head;
void Node::insert(int x ,int n)
{
	Node* temp1 = new Node();
	temp1->data = x;
	if(n==1)
	{
		temp1->next = head; // head = NULL
		head = temp1; // temp1 block is at heap ;
		return;
	}
	Node* temp2 = head;
	for(int i=0 ; i<n-2 ; i++)
		temp2 = temp2->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
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
	llist->insert(2,1);// 2
	llist->insert(3,2);// 2 3
	llist->insert(4,1);// 4 2 3
	llist->insert(5,2);// 4 5 2 3
	llist->print();
	return 0;
}
