#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

int main(int num, char* arg[])
{
	using namespace std;
	if (num == 1)
	{
		cout << "No Files specified\a : \nExiting . . . ";
		Sleep(2000);
		exit(EXIT_FAILURE);
	}
	else
	{
		string temp1, temp2;
		ifstream file1(arg[1]);
		ifstream file2(arg[2]);
		ofstream file3(arg[3]);
		int counter1 = 0, counter2 = 0;
		while (!file1.eof() || !file2.eof())
		{
			getline(file1, temp1);
			getline(file2, temp2);
			if (file1.eof() && counter1 != 0)
			{
				file3 << temp2 << endl;
			}
			else
				if (file2.eof() && counter2 != 0)
				{
					file3 << temp1 << endl;
				}
				else
					file3 << temp1 << ' ' << temp2 << endl;
			if (file1.eof())
				counter1++;
			if (file2.eof())
				counter2++;
		}
		file1.close();
		file2.close();
		file3.close();
	}
	return 0;
}