#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkifpalindrome(string);
int main()
{
	string pln;
	while (true)
	{
		cout << "Enter a palindrome\n";
		getline(cin, pln);
		transform(pln.begin(), pln.end(), pln.begin(), toupper);
		if (!checkifpalindrome(pln))
			cout << "\aThe entered string is not a palindrome\n";
		else
			cout << "Passes!!\n";
		cout << "Do you wish to continue? yes/no : \n___\b\b\b";
		cin >> pln;
		transform(pln.begin(), pln.end(), pln.begin(), toupper);
		while (pln != "YES" && pln != "NO")
		{
			cout << "Please enter a valid statement\n\a";
			cin >> pln;
			transform(pln.begin(), pln.end(), pln.begin(), toupper);
		}
		if (pln == "NO")
			break;
		cin.clear();		// to clear the input
		while (cin.get() != '\n')
			continue;
	}
	return 0;
}
bool checkifpalindrome(string c)
{
	int passingindex = 0;
	for (int i = 0; i < c.length(); i++)
	{
		if (!isalpha(c.at(i)))
			passingindex++;
	}
	int limit = (c.length()- passingindex) / 2;
	for (int i = 0, j = c.length() - 1; i < limit; i++, j--)
	{
		if (!isalpha(c.at(i)))
		{
			i++;
			continue;
		}
		if (!isalpha(c.at(j)))
		{
			j--;
			continue;
		}
		if (c.at(i) != c.at(j))
			return false;
	}
	return true;
}