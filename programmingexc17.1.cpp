#include<iostream>

int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cin >> ch;
	while (ch != '$')
	{
		count++;
		cin >> ch;
	}
	cin.putback(ch);
	cout << "Total number of characters counted = " << count << endl;
	return 0;
}