#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
#include"programmingexc17.6.h"
int main(int args, char * argv[])
{
	ifstream fin;
	if (args == 1)
	{
		fin.open("EmployeeRecords.txt");
	}
	else
	{
		if (args == 2)
		{
			fin.open(argv[1]);
		}
		else
		{
			cout << "Only One File Allowed\n\aExiting Program . . . ";
			Sleep(3000);
			exit(EXIT_FAILURE);
		}
	}

	vector<employee*> earray;
	employee * temp;
	int check = 0;
	while (!fin.eof())
	{
		fin >> check;
		switch (check)
		{
		case 1:
			temp = new employee();
			temp->ReadAll(fin);
			earray.push_back(temp);
			break;
		case 2:
			temp = new manager();
			temp->ReadAll(fin);
			earray.push_back(temp);
			break;
		case 3:
			temp = new fink();
			temp->ReadAll(fin);
			earray.push_back(temp);
			break;
		case 4:
			temp = new highfink();
			temp->ReadAll(fin);
			earray.push_back(temp);
			break;
		default:
			break;
		}
		check = 0;
	}
	fin.close();
	if (earray.size() != 0)
	{
		cout << "Data of previous employees : \n";
		for (int i = 0; i < (int)earray.size(); i++)
		{
			cout << "Employee # " << i + 1 << " : \n";
			earray[i]->ShowAll();
		}
	}
	ofstream fout;
	if (args == 1)
	{
		fout.open("EmployeeRecords.txt", ios_base::app);
	}
	else
	{
		fout.open(argv[1], ios_base::app);
	}
	cout << "************************Employee Records********************\n";
	cout << "Enter the type of employee : \n1) Simple Employee\n2)Manager\n3)fink\n4)highfink\n";
	while (cin >> check)
	{
		switch (check)
		{
		case 1:
			temp = new employee();
			temp->SetAll();
			fout << check;
			temp->WriteAll(fout);
			earray.push_back(temp);
			break;
		case 2:
			temp = new manager();
			temp->SetAll();
			fout << check;
			temp->WriteAll(fout);
			earray.push_back(temp);
			break;
		case 3:
			temp = new fink();
			temp->SetAll();
			fout << check;
			temp->WriteAll(fout);
			earray.push_back(temp);
			break;
		case 4:
			temp = new highfink();
			temp->SetAll();
			fout << check;
			temp->WriteAll(fout);
			earray.push_back(temp);
			break;
		default:
			break;
		}
		cout << "Enter next choice : \n";
	}
	fout.close();
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cout << "Revised Data : \n";
	for (int i = 0; i < (int)earray.size(); i++)
	{
		cout << "Employee # " << i + 1 << " : \n";
		earray[i]->ShowAll();
		cout << endl;
	}
	system("pause");
	return 0;
}