// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include<algorithm>
#include<iterator>

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	list<int> yadayada = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> etcetera{ 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	cout << "Original lists:\n";
	auto outint = [](int x) {cout << x << " "; };
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](int& x) {return x > 100; }); // use a named function object
	etcetera.remove_if([](int& x) {return x > 200; }); // construct a function object
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}