#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
using namespace std;
int main(int num, char* args[])
{

	if (num == 1)
	{
		cout << "No Files specified\a : \nExiting . . . ";
		Sleep(2000);
		exit(EXIT_FAILURE);
	}
	else
	{
		string data;
		ofstream fout;
		for (int i = 1; i < num; i++)
		{
			fout.open(args[i]);
			if (!fout.is_open())
			{
				cout << "Could not open " << args[i] << endl;
				fout.clear();
				continue;
			}
			cout << "Enter your data to be added to the file : ";
			getline(cin, data);
			fout << data << endl;
			fout.close();
		}
		cout << "Done!" << endl;
	}

	return 0;
}