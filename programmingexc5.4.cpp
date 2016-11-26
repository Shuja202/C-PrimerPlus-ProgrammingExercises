#include<iostream>
#include<conio.h>

using namespace std;

void main()
{
	int yearcount = 0;
	int daphne = 100;
	float cloe = 100;
	do
	{
		yearcount++;
		daphne += 10;
		cloe += cloe*0.05;

	} while (cloe <= daphne);
	cout << "It takes " << yearcount << " years for cloe's balance to surpass daphne's balance\n";
	system("pause");
}