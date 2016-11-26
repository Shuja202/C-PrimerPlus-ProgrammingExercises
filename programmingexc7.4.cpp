#include<iostream>
#include<typeinfo>
using namespace std;

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0; // here come some local variables
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}
void main()
{
	double choices;
	int megafieldend,fieldend;
	long double answer;
	cout << fixed;
	cout << "Enter the highest number of field and\n"
		"the number of picks allowed:\n";
	while ((cin >> fieldend >> choices) && (choices <= fieldend))
	{
		cout << "Enter the highest number of mega field\n";
		cin >> megafieldend;
		if (megafieldend >= 1)
		{
			answer = probability(megafieldend, 1);
		}
		else
		{
			cout << "You entered an Invalid number\n\a";
			continue;
		}
		cout << "You have one chance in ";
		cout << answer * probability(fieldend, choices); // compute the odds
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";
}