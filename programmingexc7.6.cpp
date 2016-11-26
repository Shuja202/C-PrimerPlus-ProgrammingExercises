#include<iostream>

using namespace std;

int Fill_array(double[], int);
void Show_array(const double[], int);
void Reverse_array(double[], int);

void main()
{
	double a[5];
	cout << "The number of elements in the arrray is \n" << Fill_array(a, 5) << endl;
	Show_array(a, 5);
	Reverse_array(a, 5);
	Show_array(a, 5);
	system("pause");
}
int Fill_array(double d[], int size)
{
	int i = 0;
	double temp;
	for (i = 0; i < size; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0) // signal to terminate if negative input
			break;
		d[i] = temp;
	}
	return i;
}
void Show_array(const double d[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Element # " << i + 1 << '\t' << d[i] << endl;
	}
	cout << endl;
}
void Reverse_array(double d[], int size)
{
	double temp; 
	for (int i = 0; i < size; i++, size--)	// will run until the mid element reached
	{
		temp = d[i];		// swapping
		d[i] = d[size - 1];
		d[size - 1] = temp;
	}
}