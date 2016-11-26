#include<iostream>
#include<conio.h>

using namespace std;
double taxreturn(double);
void main()
{
	int arraysize;
	cout << "Enter the number of employees\n";
	cin >> arraysize;
	double *salary; salary = new double[arraysize];
	
	for (int i = 0; i < arraysize; i++)
	{
		cout << "\nEnter the salary of employee # : " << i + 1 << endl;
		cin >> salary[i];
		if (cin.fail() || salary[i] < 0)
		{
			cout << "invalid input\n";
			cin.clear();
			cin.ignore();
			break;
		}

		else {
			cout << fixed;
			cout << "\nEmployee # " << i + 1 << "'s tax is " << (int)taxreturn(salary[i]) << " Tvarps\n";
		}
	}
	system("pause");

}
double taxreturn(double salary) {
	double x;
	if (salary <= 5000)
		return 0.00;
	else if (salary <= 15000)
		return (salary - 5000)*0.10;
	else if (salary <= 35000) 
	{
		x = salary - 15000; return x*0.15 + taxreturn(15000);
	}
	else if (salary > 35000)
	{
		x = salary - 35000; return x*0.20 + taxreturn(35000);
	}
}