#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct car
{
	char make[20];
	int year;
};
void main()
{
	int carcounter;
	cout << "How many cars do you want to catalogue? \n";
	cin >> carcounter;
	car* carptr;
	carptr = new car[carcounter];

	for (int i = 0; i < carcounter; i++)
	{
		cout << "Car #: " << i+1 << endl;
		cout << "Enter the make of the car\n";
		cin.get();
		cin.getline(carptr[i].make, 20);

		cout << "Enter the year of the car\n";
		cin >> carptr[i].year;
	}
	cout << "Here is your collection\n";

	for (int i = 0; i < carcounter; i++)
	{
		cout << carptr[i].year << ' ';
		cout << carptr[i].make;
		cout << endl;
	}
	system("pause");
}