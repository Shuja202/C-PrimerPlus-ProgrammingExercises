#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> vecmat;
	string str;
	ifstream fin("mat.dat");
	while (!fin.eof())
	{
		getline(fin, str);
		vecmat.push_back(str);
	}
	sort(vecmat.begin(), vecmat.end());
/*	cout << "Data copied from mat's file : \n";
	for (auto x : vecmat) cout << x << " : ";
	cout << endl;
	*/
	fin.close();
	fin.open("pat.dat");
	vector<string> vecpat;
	while (!fin.eof())
	{
		getline(fin, str);
		vecpat.push_back(str);
	}
	fin.close();
	sort(vecpat.begin(), vecpat.end());
/*	cout << "Data copied from pat's file : \n";
	for (auto x : vecpat) cout << x << " : ";
	cout << endl;
	*/
	vector<string> result(vecmat.size() + vecpat.size());
	merge(vecmat.begin(), vecmat.end(), vecpat.begin(), vecpat.end(), result.begin());

	vector<string>::iterator it = unique(result.begin(), result.end());
	result.erase(it, result.end());
	ofstream fout("matnpat.dat");
/*	cout << "Final list of all guests : \n";
	for (auto x : result) cout << x << " : ";
	cout << endl;
	*/
	for (auto x : result) fout << x << endl;
	fout.close();
	return 0;
}