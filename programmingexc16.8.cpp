#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> vecmat;
	cout << "Hello Mat!\nPlease enter your friends' names now (Enter empty slot to quit): \n";
	string str;
	while (getline(cin, str) && str != "")
		vecmat.push_back(str);
	sort(vecmat.begin(), vecmat.end());
	for (auto x : vecmat) cout << x << ", ";
	cout << endl;
	cout << "It's your turn Pat : " << endl;
	vector<string> vecpat;
	while (getline(cin, str) && str != "")
		vecpat.push_back(str);

	sort(vecpat.begin(), vecpat.end());
	for (auto x : vecpat) cout << x << ", ";
	cout << endl;

	vector<string> result(vecmat.size() + vecpat.size());
	merge(vecmat.begin(), vecmat.end(), vecpat.begin(), vecpat.end(), result.begin());
	
	vector<string>::iterator it = unique(result.begin(), result.end());
	result.erase(it, result.end());
	for (auto x : result) cout << x << ", ";
	cout << endl;
	cin.get();
}