#include<iostream>
#include<string>
#include<iomanip>
int main()
{
	using namespace std;
	cout << "Enter your name : ";
	string name;
	getline(cin, name);
	cout << "Enter your hourly wages : ";
	int wages;
	cin >> wages;
	cout << "Enter the number of hours you worked : ";
	float hours;
	cin >> hours;
	// first format
	cout << setw(30) << right << name << ':' << left << setw(10) << '$' << wages << ':' << setw(5) << right << hours << endl;
	// second format
	cout << setw(30) << left << name << ':' << '$' << setw(11) << wages << ':' << hours << endl;
	
	return 0;
}