#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
void ShowStr(const string&);
class Store
{
	ofstream& ofs;
public:
	Store(ofstream & file) : ofs(file) {};
	bool operator()(const string &);
};
bool Store::operator()(const string& c)
{
	int len = c.length();
	ofs.write((char *)&len, sizeof(int)); // store length
	ofs.write(c.data(), len); // store characters
	return true;
}
void GetStrs(ifstream& ifs, vector<string>& c);
int main()
{
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary | ios_base::app);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	system("pause");
	return 0;
}
void ShowStr(const string & c)
{
	cout << c << endl;
}
void GetStrs(ifstream& ifs, vector<string>& c)
{
	string temp;
	char ch;
	int len = 0;
	while (ifs.read((char*)&len, sizeof(int)))
	{
		for (int i = 0; i < len; i++)
		{
			ifs.get(ch);
			temp.push_back(ch);
		}
		c.push_back(temp);
		temp.clear();
	}
}