#include<iostream>
#include<conio.h>

using namespace std;

void main()
{
	cout << "Enter number of rows to display\n";
	int x;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		for (int k = (x - 1); k > i; k--)
		{
			cout << '.';
		}
		for (int l = 0; l <= i; l++)
		{
			cout << '*';
		}
		cout << endl;
	}

	system("pause");
}