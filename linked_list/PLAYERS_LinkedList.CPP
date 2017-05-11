#include<iostream>

using namespace std;

class PlayersLList
{
	char* name;
	int goals;
	int exp;
	PlayersLList* next;
	public:
	void insert( char* , int , int ); // insert at end .
	void del( int ); // deletion at nth position .
	void insertionSort( int[] , int );
	void print();
	void printSorted();
};

PlayersLList* head;

void PlayersLList::insert( char* nm , int i1 , int i2 )
{
	PlayersLList* temp1 = new PlayersLList();
	temp1->name = nm;
	temp1->goals = i1;
	temp1->exp = i2;
	if (head == NULL )
	{
		temp1->next = NULL;
		head = temp1;
		return;
	}
	PlayersLList* temp2 = head;
	while( temp2 != NULL )
	{
		if( temp2->next == NULL )
		{
			temp2->next = temp1;
			temp1->next = NULL;
			return;
		}
		temp2 = temp2->next ;
	}
}

void PlayersLList::del( int n )
{
	PlayersLList* temp1 = head ;
	if( n == 1 )
	{
		head = temp1->next;
		delete(temp1);
		return;
	}

	for( int i = 0 ; i<n-2 ; i++ )
		temp1 = temp1->next;
	PlayersLList* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);
}

void PlayersLList::print()
{
	PlayersLList* temp = head;
	while( temp != NULL )
	{
		cout<<temp->name<<" ";
		cout<<temp->goals<<" ";
		cout<<temp->exp<<" ";
		cout<<"\n";
		temp=temp->next;
	}
}

void PlayersLList::insertionSort( int array[] , int n )
{
	// Insertion Sort Below .
	int value , hole;
	for( int j=1 ; j<n ; j++)
	{
		value = array[j];
		hole=j;
		while( hole>0 && array[hole-1] > value)
		{
			array[hole] = array[hole-1];
			hole = --hole;
		}
		array[hole] = value;
	}
}

void PlayersLList :: printSorted()
{
	int array[10];
	int i=0;
	PlayersLList* temp = head;
	while( temp != NULL )
	{

		array[i] = temp->goals;
		++i;
		temp=temp->next;
	}
	insertionSort( array , i+1 );
	PlayersLList* temp2 = head;
	cout<<"\nSorted Records on the basis of Goals : \n";
	cout<<"Name Goals Experience\n";
	int flag;
	for(int k = 0 ; k<i+1 ; k++ )
	{
		flag = 0;
		while( temp2 != NULL && flag == 0 )
		{
			if( array[k] == temp2->goals )
			{
				cout<<temp2->name<<" ";
				cout<<temp2->goals<<" ";
				cout<<temp2->exp<<" ";
				cout<<"\n";
				temp2 = head;
				++flag;
				continue;
			}
			temp2 = temp2->next;
		}

	}
}
int main()
{
	head = NULL;
	PlayersLList* pll;
	cout<<"Name Goals Experience : \n";
	pll->insert("Burhan",25,5);
	pll->insert("Naman",20,5);
	pll->insert("Amit",15,5);
	pll->insert("Aryan",10,5);
	pll->insert("Pranjal",5,5);
	pll->print();
	cout<<"\nAfter Deletion from n = 3 :  \n";
	pll->del(3);
	pll->print();
	pll->printSorted();
    return 0;
}
