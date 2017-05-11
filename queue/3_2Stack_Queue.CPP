#include<conio.h>
#include<iostream.h>
#include<stack.h>
class Queue
{
	int top_element;
	public:
	Queue():top_element(-1){}
	void enQueue( int );
	int deQueue(); // return front element of Queue also .
	int isEmpty();
	~Queue()
	{
		while( ! old_stack.isEmpty() )
			old_stack.pop();
		while( ! new_stack.isEmpty() )
			new_stack_pop();
	}

};

Stack<int> old_stack;
Stack<int> new_stack;

void Queue::enQueue( int x )
{new_stack.push( x );}

int Queue::deQueue()
{
	if( old_stack.isEmpty() )
	{
		while( ! new_stack.isEmpty() )
		{
			top_element = new_stack.tope();
			old_stack.push(top_element);
			new_stack.pop();
		}
	}
	else if( ! old_stack.isEmpty() )
	{
		top_element = old_stack.tope();
		old_stack.pop();
	}
	else
		cout<<" Empty Queue . \n";
	return top_element;
}

int Queue::isEmpty()
{
	if( old_stack.isEmpty() && new_stack.isEmpty() )
		return 1;
	else
		return 0;
}

int main()
{
	clrscr();
	Queue* q;
	int i;
	cout<<" 1 for Empty and 0 for Not Empty : "<<q->isEmpty()<<"\n";
	for( i = 0 ; i < 6 ; i++ )    //PROBLEM SORT IT OUT SOON .
	{
		q->enQueue( i*10 );
		cout<<"enQueued : "<<i*10<<" into the Queue\n";
	}
	cout<<"After enQueue -> ";
	cout<<" 1 for Empty and 0 for Not Empty : "<<q->isEmpty()<<"\n";
	for( i = 0 ; i < 6 ; i++ )
		cout<<"deQueued : "<<q->deQueue()<<"\n";
	cout<<" 1 for Empty and 0 for Not Empty : "<<q->isEmpty()<<"\n";
	getch();
	return 0;
}

