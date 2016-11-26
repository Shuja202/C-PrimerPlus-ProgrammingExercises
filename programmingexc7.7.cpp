#include<iostream>

using namespace std;

double* Fill_array(double*, double*);
void Show_array(const double*, const double *);		// so that the display function can't alter the pointers
void Reverse_array(double *&,double *&);		// to get the value by rvalue referrence

void main()
{
	double * d;
	d = new double[3];
	double * size = Fill_array(d,d+3);
	Show_array(d, size);
	Reverse_array(d, size);
	Show_array(d, size);
	delete[] d;
	system("pause");
} 
double* Fill_array(double * start, double * end)
{
	int size = end - start;
	int  i;
	for (i = 0; i < size; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> *(start + i);
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (*(start + i) < 0) // signal to terminate
		{
			break;
		}
	}
	return (start + (i-1));
}
void Show_array(const  double * start,const double * end)
{
	int size = end - start;
	for (int i = 0; i <= size; i++)
	{
		cout << "Element # " << i + 1 << '\t' << start[i] << endl;
	}
	cout << endl;
}
void Reverse_array(double * & start, double *& end)
{
	double * temp;
	temp = new double;
	int size = end - start;
	int runtime = ((size)+1) / 2;
	for (int i = 0; i < runtime; i++)
	{
		*temp = start[i];
		start[i] = start[size - i];
		start[size - i] = *temp;
	}
	cout << "Array Reversed!" << endl;
	delete temp;
}