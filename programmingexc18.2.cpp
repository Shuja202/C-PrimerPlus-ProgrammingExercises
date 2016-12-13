#include<iostream>
#include<string>
using namespace std;
#include"programmingexc18.2.h"

int main()
{
	{
		cout << "Checking every constructor : \n";
		Cpmv a;		// default constructor
		Cpmv b("5400", "5600");		// strings constructor
		Cpmv c(b);	// copy constructor
		cout << "To check an rvalue constructor, an operator+() will also be called : \n";
		Cpmv d(c + b); 	// move constructor // operator+()
		a = b;		// copy assignment
		cout << endl << "Calling move assignment and providing rvalue by operator+() : \n";
		a = b + c;	// move assignment

		cout << "Lastly calling the display for a object which was default constructed : \n";
		a.Display();
		cout << "Now rest of destructors will be called : we created 4 objects a,b,c, & d\n";
	}
	cin.get();
	return 0;
}