#pragma once
// emp.h -- header file for employees class and children
#include <string>

class employee
{
private:
	string fname; // employee's first name
	string lname; // employee's last name
	string job;
public:
	employee();
	employee(const string & fn, const string & ln, const string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream&);
	virtual void ReadAll(ifstream&);
	friend ostream& operator<<(ostream& os, const employee& e);
	friend istream& operator>>(istream& is,  employee& e);
};
employee::employee()
{
	fname = "nothing";
	lname = "nothing";
	job = "vela";
}
employee::employee(const string &fn, const string &ln, const string &j)
{
	fname = fn;
	lname = ln;
	job = j;
}
void employee::ShowAll() const
{
	cout << "First name : " << fname << endl;
	cout << "Last name : " << lname << endl;
	cout << "Job Title : " << job << endl;
}
void employee::SetAll()
{
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cout << "Enter first name : ";
	getline(cin, fname);
	cout << "Enter last name : ";
	getline(cin, lname);
	cout << "Enter job title : ";
	getline(cin, job);
}
ostream& operator<<(ostream & os, const employee & e)
{
	os << "First Name : " << e.fname << endl;
	os << "Last Name : " << e.lname << endl;
	return os;
}
istream& operator>>(istream& is, employee & e)
{
	cout << "Enter first name : ";
	is >> e.fname;
	cout << "Enter last name : ";
	is >> e.lname;
	cout << "Enter job title : ";
	is >> e.job;
	return is;
}
void employee::WriteAll(ofstream& ofs)
{
	ofs << fname << endl << lname << endl << job << endl;
}
void employee::ReadAll(ifstream& ifs)
{
	getline(ifs, fname);
	getline(ifs, lname);
	getline(ifs, job);
}
class manager : virtual public employee
{
private:
	int inchargeof; // number of employees managed
protected:
	int InChargeOf() const { return inchargeof; } // output
	int & InChargeOf() { return inchargeof; } // input
public:
	manager();
	manager(const string & fn, const string & ln, const string & j, int);
	manager(const employee & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream&);
	virtual void ReadAll(ifstream&);
	friend ostream& operator<<(ostream& os, const manager& e);
	friend istream& operator>>(istream& is, manager& e);
};
manager::manager() : employee() {};
manager::manager(const string & fn, const string & ln, const string & j, int ico = 0) : inchargeof(ico), employee(fn, ln, j) {};
manager::manager(const  employee & e, int ico) : inchargeof(ico), employee(e) {};
manager::manager(const manager & m) : inchargeof(m.inchargeof), employee(m) {};
void manager::SetAll()
{
	employee::SetAll();
	cout << "Enter the number of employees managed : ";
	cin >> inchargeof;
}
void manager::ShowAll() const
{
	employee::ShowAll();
	cout << "Number of employees managed : " << inchargeof << endl;
}
ostream& operator<<(ostream& os, const manager& m)
{
	m.ShowAll();
	return os;
}
istream& operator>> (istream& is, manager& m)
{
	m.SetAll();
	return is;
}
void manager::WriteAll(ofstream& ofs)
{
	employee::WriteAll(ofs);
	ofs << inchargeof << endl;
}
void manager::ReadAll(ifstream& ifs)
{
	employee::ReadAll(ifs);
	ifs >> inchargeof;
}
class fink : virtual public employee
{
private:
	string reportsto; // to whom fink reports
protected:
	const string ReportsTo() const { return reportsto; }
	string & ReportsTo() { return reportsto; }
public:
	fink();
	fink(const string & fn, const string & ln, const string & j, const string & rpo);
	fink(const employee & e, const string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream&);
	virtual void ReadAll(ifstream&);
	friend ostream& operator<<(ostream& os, const fink& e);
	friend istream& operator>>(istream& is, fink& e);
};
fink::fink() : employee() {};
fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : reportsto(rpo), employee(fn, ln, j) {};
fink::fink(const employee & e, const string & rpo) : reportsto(rpo), employee(e) {};
fink::fink(const fink & e) : reportsto(e.reportsto), employee(e) {};
void fink::ShowAll() const
{
	employee::ShowAll();
	cout << "Reports to : " << reportsto << endl;
}
void fink::SetAll()
{
	employee::SetAll();
	cout << "Enter the person to whom fink reports : ";
	getline(cin, reportsto);
}
ostream& operator<<(ostream& os, const fink& f)
{
	f.ShowAll();
	return os;
}
istream& operator>> (istream& is, fink& f)
{
	f.SetAll();
	return is;
}
void fink::WriteAll(ofstream& ofs)
{
	employee::WriteAll(ofs);
	ofs << reportsto << endl;
}
void fink::ReadAll(ifstream& ifs)
{
	employee::ReadAll(ifs);
	getline(ifs, reportsto);
}
class highfink : public manager, public fink // management fink
{
public:
	highfink();
	highfink(const string & fn, const string & ln,
		const string & j, const string & rpo,
		int ico);
	highfink(const employee & e, const string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream&);
	virtual void ReadAll(ifstream&);
	friend ostream& operator<<(ostream& os, const highfink& hf);
	friend istream& operator>>(istream& is, highfink& hf);
};
highfink::highfink() : employee() ,manager(), fink() {};
highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : employee(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {};
highfink::highfink(const employee & e, const string & rpo, int ico) : employee(e), manager(e, ico), fink(e, rpo) {};
highfink::highfink(const fink& f, int ico) : fink(f), manager(f, ico) {};
highfink::highfink(const manager& m, const string & rpo) : employee(m), manager(m), fink(m, rpo) {};
highfink::highfink(const highfink& h) {};

void highfink::ShowAll() const
{
	employee::ShowAll();
	cout << "Number of employees managed : " << InChargeOf() << endl;
	cout << "Reports to : " << ReportsTo() << endl;
}
void highfink::SetAll()
{
	employee::SetAll();
	cout << "Enter the number of employee(s) managed : ";
	cin >> InChargeOf();
	cout << "Enter the person to whom fink reports : " << endl;
	cin.clear();
	while (cin.get() != '\n')
		continue;
	getline(cin, ReportsTo());
}
ostream& operator<<(ostream& os, const highfink& hf)
{
	hf.ShowAll();
	return os;
}
istream& operator>>(istream& is, highfink& hf)
{
	hf.SetAll();
	return is;
}
void highfink::WriteAll(ofstream& ofs)
{
	employee::WriteAll(ofs);
	ofs << ReportsTo() << endl << InChargeOf() << endl;
}
void highfink::ReadAll(ifstream& ifs)
{
	employee::ReadAll(ifs);
	getline(ifs, ReportsTo()) >> InChargeOf();
}