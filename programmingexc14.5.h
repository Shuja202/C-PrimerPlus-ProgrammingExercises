// emp.h -- header file for abstr_emp class and children
#include <iostream>
#include <string>
class abstr_emp
{
private:
	string fname; // abstr_emp's first name
	string lname; // abstr_emp's last name
	string job;
public:
	abstr_emp();
	abstr_emp(const string & fn, const string & ln, const string & j);
	virtual void ShowAll() const; // labels and shows all data
	virtual void SetAll(); // prompts user for values
	friend ostream& operator<<(ostream & os, const abstr_emp & e);
	// just displays first and last name
	virtual	~abstr_emp() = 0; // virtual base class
};
abstr_emp::abstr_emp()
{
	fname = "nothing";
	lname = "nothing";
	job = "vela";
}
abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
{
	fname = fn;
	lname = ln;
	job = j;
}
void abstr_emp::ShowAll() const
{
	cout << "First name : " << fname << endl;
	cout << "Last name : " << lname << endl;
	cout << "Job Title : " << job << endl;
}
void abstr_emp::SetAll()
{
	cout << "Enter first name : ";
	getline(cin, fname);
	cout << "Enter last name : ";
	getline(cin, lname);
	cout << "Enter job title : ";
	getline(cin, job);
}
ostream& operator<<(ostream & os, const abstr_emp & e)
{
	os << "First Name : " << e.fname << endl;
	os << "Last Name : " << e.lname << endl;
	return os;
}
abstr_emp::~abstr_emp() {};
class employee : public abstr_emp
{
public:
	employee();
	employee(const string & fn, const string & ln, const string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
};
employee::employee() : abstr_emp()
{
}
employee::employee(const string &fn, const string &ln, const string &j) : abstr_emp(fn, ln, j)
{
}
void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}
class manager : virtual public abstr_emp
{
private:
	int inchargeof; // number of abstr_emps managed
protected:
	int InChargeOf() const { return inchargeof; } // output
	int & InChargeOf() { return inchargeof; } // input
public:
	manager();
	manager(const string & fn, const string & ln, const string & j, int);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
};
manager::manager() : abstr_emp() {};
manager::manager(const string & fn, const string & ln, const string & j, int ico = 0) : inchargeof(ico), abstr_emp(fn, ln, j) {};
manager::manager(const abstr_emp & e, int ico) : inchargeof(ico), abstr_emp(e) {};
manager::manager(const manager & m) : inchargeof(m.inchargeof), abstr_emp(m) {};
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the number of abstr_emp(s) managed : ";
	cin >> inchargeof;
}
void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Number of abstr_emp managed : " << inchargeof << endl;
}
class fink : virtual public abstr_emp
{
private:
	string reportsto; // to whom fink reports
protected:
	const string ReportsTo() const { return reportsto; }
	string & ReportsTo() { return reportsto; }
public:
	fink();
	fink(const string & fn, const string & ln, const string & j, const string & rpo);
	fink(const abstr_emp & e, const string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
};
fink::fink() : abstr_emp() {};
fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : reportsto(rpo), abstr_emp(fn, ln, j) {};
fink::fink(const abstr_emp & e, const string & rpo) : reportsto(rpo), abstr_emp(e) {};
fink::fink(const fink & e) : reportsto(e.reportsto), abstr_emp(e) {};
void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reports to : " << reportsto << endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the person to whom fink reports : " << endl;
	getline(cin, reportsto);
}
class highfink : public manager, public fink // management fink
{
public:
	highfink();
	highfink(const string & fn, const string & ln,
		const string & j, const string & rpo,
		int ico);
	highfink(const abstr_emp & e, const string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
};
highfink::highfink() : manager(), fink() {};
highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {};
highfink::highfink(const abstr_emp & e, const string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {};
highfink::highfink(const fink& f, int ico) : fink(f), manager(f, ico) {};
highfink::highfink(const manager& m, const string & rpo) : abstr_emp(m), manager(m), fink(m, rpo) {};
highfink::highfink(const highfink& h) {};
void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Number of abstr_emp managed : " << InChargeOf() << endl;
	cout << "Reports to : " << ReportsTo() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the number of abstr_emp(s) managed : ";
	cin >> InChargeOf();
	cout << "Enter the person to whom fink reports : " << endl;
	cin.clear();
	while (cin.get() != '\n')
		continue;
	getline(cin, ReportsTo());
}