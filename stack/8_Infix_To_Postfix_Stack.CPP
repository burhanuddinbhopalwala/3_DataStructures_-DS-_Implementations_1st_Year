#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stack.h>
// Infix to Postfix Conversion .
// scanning from left to right .
class Conversion
{
	char* str;
	public:
	void setstr();
	char* getstr();
	int priority(char);
	char* convert();
};
void Conversion::setstr()
{
	puts("Enter a Infix Expression : ");
	gets(str);
}

char* Conversion::getstr()
{ return str; }

int Conversion::priority(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/' || c == '%')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return 0;

}
char* Conversion::convert()
{
	Stack<char> s;
	char* result;
	int n=0;
	for(int i = 0 ; i < strlen(str) ; i++ ) // form left to right
	{
		if( str[i] == ' ' || str[i] == '\t' || str[i] == ',' )
			continue;

		else if( isdigit(str[i]) || isalpha(str[i]) ) // from ctype.h
		{
			*result = str[i];
			result++;
		}

		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' ||
str[i] == '/' || str[i] == '%' || str[i] == '^')
		{
			while( ! s.isEmpty() && ( priority(s.tope()) > priority(str[i]) ) )
			{
				*result = s.tope();
				cout<<result;
				result++;
				s.pop();
			}
			s.push(str[i]);
		}

		else if(str[i] == '(')
			s.push(str[i]);

		else if( str[i] == ')')
		{
			while(s.tope() == '(')
			{
				*result = s.tope();
				result++;
				s.pop();
			}
		}

	}// for loop

	while( ! s.isEmpty() ) // for left operator in stack finally
	{                      // added into the stack .
		*result = s.tope();
		result++;
		s.pop();
	}

	*result = '\0';
	return result;
}// function
int main()
{
	clrscr();
	Conversion c;
	c.setstr();
	cout<<"The Postfix Expression is : "<<c.convert();
	getch();
	return 0;
}
