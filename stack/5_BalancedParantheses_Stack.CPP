#include<conio.h>
#include<iostream.h>
#include<stack.h>
#include<stdio.h>
#include<string.h>
// Checking the balanced parantheses using stack .
class CheckParantheses
{
	char* str;
	public:
	void setstr();
	char* getstr();
	char* check();
};
void CheckParantheses::setstr()
{
	puts("Enter the String : ");
	gets(str);
}

char* CheckParantheses::getstr()
{ return str; }

char* CheckParantheses::check()
{
	Stack<char> s;
	for(int i=0 ; i<strlen(str) ; i++)
	{
		if( str[i] == '(' || str[i] == '{' || str[i] == '[')
		      s.push(str[i]);
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if( s.isEmpty() )
				return "False"; // as boolean in not working.
			else if(s.tope() == '(' && str[i] == ')')
				s.pop();
			else if(s.tope() == '{' && str[i] == '}')
				s.pop();
			else if(s.tope() == '[' && str[i] == ']')
				s.pop();
			else           // [) or {(] etc
				return "False";

		}
	}
	return s.isEmpty()?"True":"False";
}
int main()
{
	clrscr();
	CheckParantheses cp;
	cp.setstr();
	cout<<"Checking the Parantheses : ";
	cout<<cp.check();
	getch();
	return 0;
}
