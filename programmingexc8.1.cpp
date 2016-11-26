#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int check = 0;
void print(string & s, int i = 0)
{
	if (i != 0)
	{
		cout << "cout from the function\n";
		for (int j = 0; j < check; j++)
		{
			cout << s << endl;
		}
		check++;
	}
	else 
	{
		cout << "cout from the function\n";
		check++;
		cout << s << endl;
	}
}
void main()
{
	string name = "Shuja";
	print(name, 2);
	name = "Ale";
	print(name);
	print(name, -1);
	_getch();
}