// F_w5
#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Stack.h"

using namespace std;

//reads a string from the console
string readInput()
{
	string in;
	cout << "Enter a string..." << endl;
	getline(cin, in);
	return in;
}

//returns true if the char is a bracket
bool isBracket(const char& c)
{
	switch (c)
	{
	case '{':
	case '}':
	case '[':
	case ']':
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}

//fills a stack with the brackets from an input string
void loadInputToStack(Stack<char>& s, const string& input)
{
	int length = input.length();
	for (size_t i = 0; i < length; i++)
	{
		if (isBracket(input[i]))
		{
			s.push(input[i]);
		}
	}
}

//returns true if c1 is an opener bracket that is closed by c2
bool areClosed(const char& c1, const char& c2)
{
	if ((c1 == '{' && c2 == '}')
		|| (c1 == '[' && c2 == ']')
		|| (c1 == '(' && c2 == ')'))
	{
		return true;
	}
	return false;
}

//returns true if all brackets are closed properly
bool checkBrackets(const string& str)
{
	Stack<char> s1, s2;
	loadInputToStack(s1, str);

	cout << "brackets in the beggining: ";
	s1.print();

	if (!s1.isEmpty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	while (!s1.isEmpty())
	{
		cout << "---------------" << endl;
		cout << "s1: ";
		s1.print();
		cout << "s2: ";
		s2.print();
		if (!s2.isEmpty())
		{
			char top = s1.top();
			s1.pop();
			if (areClosed(top, s2.top()))
			{
				s2.pop();
				cout << "Closed!" << endl;
			}
			else
			{
				s2.push(top);
			}
		}
		if (s1.isEmpty() && s2.isEmpty())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	bool allBracketsAreClosed = checkBrackets(readInput());
	cout << allBracketsAreClosed << endl;
	return 0;
}

//alg
/*
while s1.size !=0
	if s2.size == 0 , return true
	else
		compare s1.top and s2.top
		if opener + closer then remove both
		else add s2.push(s1.top) and s1.pop

return false;
*/
