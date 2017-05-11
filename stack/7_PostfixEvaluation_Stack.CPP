#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stack.h>
#include<math.h>
#include<stdlib.h>
// Evaluation of Postfix expression using the stack .
// scanning from left to right .
class PostfixEvaluation
{
	char* str;
	public:
	void setstr();
	char* getstr();
	int evaluation();
};
void PostfixEvaluation::setstr()
{
	puts("Enter a Postfix expression : ");
	gets(str);
}
char* PostfixEvaluation::getstr()
{ return str; }

int PostfixEvaluation::evaluation()
{
	int i1,i2,i3,n=0;
	Stack<int> s;
	for(int i=0; i<strlen(str); i++) // left to right
	{
		if(str[i] == ' ' || str[i] == '\t' || str[i] == ',')
		    {
			--n;
			continue;
		    }// skip rest statements start loop again .
		else if( isdigit(str[i]) ) // from ctype.h
			{
				str[i] = str[i] - '0';
				++n;
				if(n == 2)
				{
					str[i] = ((s.tope()*10) + str[i]);
					s.pop();
					s.push(str[i]);
					--n;
					continue;
				}
				s.push(str[i]);
			}
		else
		{
				if( s.isEmpty() ) // not work for empty string.
					return 0;

				i1 = s.tope();
				s.pop();

				if( s.isEmpty() ) // for 2 * etc
					return 0;     // or use else  */

				i2 = s.tope();
				s.pop();
				switch(str[i])
				{
					case '+':
					{
						i3 = i2 + i1;
						break;
					}
					case '-':
					{
						i3 = i2 - i1;
						break;
					}
					case '*':
					{
						i3 = i2 * i1;
						break;
					}
					case '/':
					{
						 i3 = i2 / i1;
						 break;
					}
					case '%':
					{
						i3 = i2 % i1;
						break;
					}
					case '^':
					{
						i3 = pow(i2 , i1);
						break;
					}
					default :
					{
						cout<<"Invalid Operator";
						exit(0);
						break;
					}
				}// switch
				s.push(i3);
		}//outer else
	}// for loop
	return s.tope();
}// function
int main()
{
	clrscr();
	PostfixEvaluation pe;
	pe.setstr();
	cout<<"Result is : "<<pe.evaluation();
	getch();
	return 0;
}
