#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
struct contributors {
	string name;
	double donation;
};
void main()
{
	
	ifstream fin;
	fin.open("programmingexc6.9.txt");

	if (fin.is_open())
	{
		int arraysize;
		fin >> arraysize;
		contributors * cont;cont = new contributors[arraysize];
		for (int i = 0; i < arraysize; i++)
		{
			fin.ignore();
			getline(fin, cont[i].name);
			fin >> cont[i].donation;
		}
		for (int i = 0; i < arraysize; i++)
		{
			cout << "Mr./Mrs. " << cont[i].name << " donated " << cont[i].donation << "Rs.\n";
		}
		fin.close();
	}
	else {
		cout << "Error could not open file \a\n";
		_sleep(1000);
		exit(EXIT_FAILURE);
	}
	system("pause");
}