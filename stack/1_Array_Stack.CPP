#include<conio.h>
#include<iostream.h>
#define MAXSIZE 100
// Stack 1
// stack implementation using array .
class Stack
{
	int array[MAXSIZE];
	int top;
	public:
	Stack(){top = -1;}
	void push(int);
	void pop();
	int tope();
	int isEmpty();
	void print(); // for checking the impementation .
};
void Stack::push(int x)
{
	if( top == MAXSIZE - 1)
		return;
	array[++top] = x;
}
void Stack::pop()
{
	if(top == -1)
		return;
	--top;
}
int Stack::tope()
{
	return array[top];
}
int Stack::isEmpty()
{
   return top==-1?1:0;
}
void Stack::print()
{
	for(int i=top; i>-1; i--) // reverse print for stack .
		cout<<" "<<array[i];
	cout<<"\n";
}
int main()
{
	clrscr();
	Stack s; // Stack* s; This way constructor not invoked .
	s.push(2);// Because it is not the object it is the refrence .
	s.push(5);
	s.push(7);
	s.print();// 7 5 2
	s.pop();
	s.pop();
	s.print();// 2
	s.push(15);
	cout<<s.tope()<<"\n"; // 15
	s.print();//15 2
	cout<<s.isEmpty();// 0
	s.pop();
	s.pop();
	s.print();//
	cout<<" "<<s.tope()<<"\n"; // return Garbage value
	cout<<s.isEmpty();// 1
	getch();
	return 0;
}