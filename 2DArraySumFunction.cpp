#include<iostream>
using namespace std;

int sum(int** x , int rows, int cols) {
	int total = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			total += *(*(x + i) + j);
		}
	}return total;
}

void main()
{
	cout << "Enter number of rows\n";
	int rows;
	cin >> rows;
	cout << "Enter number of cols\n";
	int cols;
	cin >> cols;
	
	int ** twodarray;
	twodarray = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		twodarray[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			twodarray[i][j] = rand() % 15 + 5;
		}
	}
	cout << "The array is \n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << twodarray[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "and the sum of the array is : " << sum(twodarray, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		delete[] twodarray[i];
	}
	delete[] twodarray;
	system("pause");
}