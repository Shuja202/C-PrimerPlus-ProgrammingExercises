#include<iostream>
#include<initializer_list>
using namespace std;

template<class t = double>
double average_list(initializer_list<t> li)
{
	double sum = 0; int numofelements = 0;
	for (auto p = li.begin(); p != li.end(); p++)
	{
		sum += *p;
		numofelements++;
	}
	double average = sum / numofelements;
	return average;
}
int main()
{
	// list of double deduced from list contents
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;
	// list of int deduced from list contents
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	// forced list of double
	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;
	cin.get();
	return 0;
}