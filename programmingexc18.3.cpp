#include<iostream>
#include<string>
using namespace std;


template<class t>
long double sum_values(t x) { return x; }

template<class t, class... Args>
long double sum_values(t value, Args...args)
{
	return (value + sum_values(args...));
}
int main()
{

	cout << "The sum of the arbitrary list is : \n";
	cout << sum_values(15, 163.2, 14, 62L, 92, 1.02) << endl;
	cout << "Now mixing characters with the list : \n";
	short c = 2;
	cout << sum_values(18, 'g', 14, 0.0021, 26, c) << endl;

	cin.get();
	return 0;
}