#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	int count = 0;char  ch;
	ifstream fin;

	string filename;
	cout << "Enter the file name\n";
	cin >> filename;
	
	fin.open(filename);
	if (fin.is_open())
	{
		while (fin >> ch)
		count++;
		cout << "Number of characters read : " << count << endl;
	}
	else 
	{
		cout << "Error! opening file Failed\n\a";
		exit(EXIT_FAILURE);
	}
	fin.close();
	system("pause");
}