#include <iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

#define strsize 20

struct bop {

	char fullname[strsize]; // real name
	char title[strsize]; // job title
	char bopname[strsize]; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

void showmenu();
void addDetails(bop members[], int arraysize);

int main()
{
	bop members[3];
	addDetails(members, 3);

	showmenu();

	char ch;
	while (cin >> ch)
	{
		switch (ch)
		{
		case 'A': for (int i = 0; i < 3; i++)
		{
			cout << members[i].fullname << endl;
		}break;

		case 'B': for (int i = 0; i < 3; i++)
		{
			cout << members[i].title << endl;
		}break;
		case 'c': for (int i = 0; i < 3; i++)
		{
			cout << members[i].bopname << endl;
		}break;
		case 'D': for (int i = 0; i < 3; i++)
		{
			if (members[i].preference == 0)
			{
				cout << members[i].fullname << endl;
			}
			else if (members[i].preference == 1)
			{
				cout << members[i].title << endl;
			}
			else if (members[i].preference == 2)
			{
				cout << members[i].bopname << endl;
			}
		}break;
		case 'E':  exit(EXIT_SUCCESS);

		default:
		{
			cout << "Enter a valid choice\n";
			for (int i = 0; i < 5; i++)
			{
				Sleep(1000);
				cout << i << endl;
				system("CLS");
				showmenu();
			}
		}break;
		}
	}
}
void showmenu()
{
	cout << endl << "Make a choice\nA)display by name	B)display by title\nC)display by BOP name	D)Display by preference \nE)Quit";
}
void addDetails(bop members[], int arraysize) {
	cout << "Enter the spicifations of of the members\n";

	for (int i = 0; i < arraysize; i++)
	{
		cout << "Enter member # " << i + 1 << "'s name\n";
		cin.getline(members[i].fullname, strsize);
		cout << "Enter member # " << i + 1 << "'s title\n";
		cin.getline(members[i].title, strsize);
		cout << "Enter member # " << i + 1 << "'s bopname\n";
		cin.getline(members[i].bopname,strsize);
		cout << "Enter member # " << i + 1 << "'s preference\n";
		cin >> members[i].preference;
		cin.ignore();
	}
}