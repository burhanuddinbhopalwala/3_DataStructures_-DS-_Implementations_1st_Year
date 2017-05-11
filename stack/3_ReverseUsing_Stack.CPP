#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<stack.h>
//stack.h -> Standard Template Library(STL) .
// stdio.h for puts() and gets() function not in string.h .
// Reversing the string using stack .
class StackReverse
{
	char* str1;
	char* str2;
	// char* str1 , str2 ; // Give ERROR
	public:
	void setstr();
	char* getstr();
	void reverse();
	void checkPalindrom();
	~StackReverse()
	{
		delete(str1);
		delete(str2);
	}
};
void StackReverse::setstr()
{
	puts("Enter an String : ");
	gets(str1);
}

char* StackReverse::getstr()
{ return str1; }

void StackReverse::reverse()
{
	int i;
	Stack<char> s;
	for(i=0 ; i<strlen(str1) ; i++)
		s.push(str1[i]);//push(),pop(),tope() direct also accessible.
	for(i=0 ; i<strlen(str1) ; i++)//but the best way is OOP approach .
	{
		str2[i] = s.tope();
		s.pop();
	}
	str2[i] = '\0';
	puts("Reverse String is : ");
	puts(str2);
}

void StackReverse::checkPalindrom()
{
	if( ! strcmp(str1 , str2) )
		cout<<"\nIt is a Palindrom .";
	else
		cout<<"\nNot a Palindrom .";
}

int main()
{
	clrscr();
	StackReverse sr;
	sr.setstr();
	sr.reverse();
	sr.checkPalindrom();
	getch();
	return 0;
}
/*
NOTE : This method has time and space complexity not the best method to
reverse the string . Probably the best method to reverse the string is
by SWAP the characters method .
*/