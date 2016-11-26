#include<iostream>
#include<conio.h>
#include<string>
#include<stdio.h>
using namespace std;

void print(string & s);

int main()
{
	string name;
	do 
	{
		cout << "Enter string (q to quit) \n";
		getline(cin, name);
		if (name == "q"|| name == "Q")
		{
			break;
		}
		print(name);
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
}
void print(string & s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s.at(i) = toupper(s.at(i));
	}
	cout << s << endl;
}