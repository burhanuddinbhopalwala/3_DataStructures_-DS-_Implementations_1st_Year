#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<stack.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
// Evaluation of Prefix Evaluation .
// scanning form right to left .
class PrefixEvaluation
{
	char* str;
	public:
	void setstr();
	char* getstr();
	int evaluation();
};
void PrefixEvaluation::setstr()
{
	puts("Enter a prefix expression : ");
	gets(str);
}

char* PrefixEvaluation::getstr()
{ return str; }

int PrefixEvaluation::evaluation()
{
	int i1,i2,i3,n=0;
	Stack<int> s;
	for(int i=strlen(str)-1; i>=0 ; i--) // form right to left
	{
		if(str[i]==' ' || str[i]=='\t' || str[i]==',')
		{
			--n;
			continue;
		}
		else if( isdigit(str[i]) )// from ctype.h
		{
			str[i] = str[i] - '0';
			++n;
			if( n == 2 )
			{
				str[i] = ((str[i]*10) + s.tope());// !!CAUTION
				s.pop();
				s.push(str[i]);
				--n;
				continue;
			}
			s.push(str[i]);
		}
		else
		{
			if( s.isEmpty() ) // Not working
				return 0;

			i1 = s.tope();
			s.pop();

			if( s.isEmpty() ) //for + 2
				return 0;

			i2 = s.tope();
			s.pop();

			switch(str[i])
			{
				case '+':
				{
					i3 = i1 + i2;
					break;
				}
				case '-':
				{
					i3 = i1 - i2;
					break;
				}
				case '*':
				{
					i3 = i1 * i2;
					break;
				}
				case '/':
				{
					i3 = i1 / i2;
					break;
				}
				case '%':
				{
					i3 = i1 % i2;
					break;
				}
				case '^':
				{
					i3 = pow( i2 , i1 );
					break;
				}
				default :
				{
					cout<<"Invalid Operator .";
					break;
				}
			}//switch

			s.push(i3);
		}//else
	}// for loop
	return s.tope();
}
int main()
{
	clrscr();
	PrefixEvaluation pe;
	pe.setstr();
	cout<<"Result is : "<<pe.evaluation();
	getch();
	return 0;
}