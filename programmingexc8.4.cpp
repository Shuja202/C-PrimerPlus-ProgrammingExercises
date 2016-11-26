#include <iostream>
#include<conio.h>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy 
{
	char * str;			// points to a string
	int ct;				// length of string (not counting '\0')
};
// prototypes for set(), show(), and show() go here
void  set(stringy&, char[]);
void show(const stringy&, int i = 0);
void show(char[], int i = 0);
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
						 // allocates space to hold copy of testing,
						 // sets str member of beany to point to the
						 // new block, copies testing to new block,
						 // and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
	_getch();
	delete[] beany.str;
	return 0;
}
void set(stringy& s, char c[] )
{
	s.ct = strlen(c);
	s.str = new char[s.ct+1];
	strcpy_s(s.str,s.ct+1, c);
	s.str[s.ct + 1] = '\n';
}
void show(const stringy& s, int i)
{
	if (i==0)
	{
		cout << s.str << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << s.str << endl;
		}
	} 
}
void show(char c[], int i)
{
	if (i == 0)
	{
		cout << c << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << c << endl;
		}
	}
}