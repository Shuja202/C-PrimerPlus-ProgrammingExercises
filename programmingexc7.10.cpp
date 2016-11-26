#include<iostream>
#include<conio.h>

using namespace std;
double Calculate(double x, double y, double (*fp)(double, double))
{
	return fp(x, y);
}
double add(double x, double y)
{
	return x + y;
}
double multiply(double x, double y)
{
	return x*y;
}
double subtract(double x, double y)
{
	return x - y;
}
void main()
{
	double(*pf[3])(double, double) = { add, multiply, subtract };
	double x, y;
	cout << "Enter two numbers";
	while (cin >> x >> y)
	{
		for (int  i = 0; i <3; i++)
		{
			cout << Calculate(x, y, pf[i]) << endl;
		}
		cout << endl;
		cout << "Enter two numbers";
	}
	cout << "Bad Input\n";
	_getch();
}