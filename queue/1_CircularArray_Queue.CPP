#include<conio.h>
#include<iostream.h>
#define MAXSIZE 10
// Implementation of Queue using the Circular Array .
class Queue
{
	int array[MAXSIZE];
	int front , rear;
	public:
	Queue();
	void enQueue(int);
	void deQueue();
	int frnt();
	int isEmpty();
	int isFull();
	void print(); // not a specefic operation just for checking .
};
Queue :: Queue()
{
	front = -1;
	rear = -1;
}

void Queue::enQueue(int x)
{
	if( ((rear + 1)%MAXSIZE) == front ) // Array is full / Exhausted
		return ;      // we deal with circular array here .

	else if( isEmpty() ) // checking here for front == rear == -1 ;
		front = rear = 0;

	else
		rear = ((rear + 1)%MAXSIZE);

	array[rear] = x;
}

void Queue::deQueue()
{
	if( isEmpty() )  // checking here for front == rear == -1
		return;
	else if( front == rear)
		front = rear = -1;
	else
		front = ((front + 1)%MAXSIZE); // for circular array .
}

int Queue::frnt()
{ return array[front] ; }

int Queue::isEmpty()
{
	if( front == -1 && rear == -1 )
		return 1;
	else
		return 0;
}

int  Queue::isFull()
{
	if( (rear+1)%MAXSIZE == front )
		return 1;
	else
		return 0;
}

void Queue::print()
{
	if( ! isEmpty() )
	{
		int i ;
		if( rear >= front)
		{
			for( i = front ; i <= rear ; i++)
				cout<<" "<<array[i];
		}
		else
		{
			for( i = front ; i < MAXSIZE  ; i++ )
				cout<<" "<<array[i];
			for( i = 0 ; i <= rear ; i++)
				cout<<" "<<array[i];
		}

	}
	else
		cout<<"\n Empty Stack .";
	cout<<"\n";
}

int main()
{
	clrscr();
	Queue q;
	cout<<q.isEmpty()<<"\n"; // 1
	cout<<q.isFull()<<"\n"; // 0
	q.enQueue(2); // array[0] , rear = front = 0
	q.print(); // 2
	q.enQueue(4);// array[1] , rear = 1
	q.enQueue(6);// array[2] , rear = 2
	q.enQueue(8);// array[3] , rear = 3
	q.enQueue(10);// array[4] , rear = 4
	q.print(); // 2 4 6 8 10
	q.deQueue();// front = 1
	q.deQueue();// front = 2
	q.print(); // 6 8 10
	cout<<q.frnt()<<"\n"; // 6 // array[2]
	q.enQueue(12); // array[5] , rear = 5
	q.enQueue(14); // array[6] , rear = 6
	q.enQueue(16); // array[7] , rear = 7
	q.enQueue(18); // array[8] , rear = 8
	q.enQueue(20); // array[9] , rear = 9
	q.enQueue(22); // array[0] , rear = 0;
	q.enQueue(24); // array[1] , rear = 1;
	q.enQueue(26); // No change here as Array is Full .
	q.print(); // 6 8 10 12 14 16 18 20 22 24
	cout<<q.isEmpty()<<"\n"; // 0
	cout<<q.isFull()<<"\n"; // 1
	getch();
	return 0;
}
