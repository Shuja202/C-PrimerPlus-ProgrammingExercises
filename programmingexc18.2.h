#pragma once
class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv & cp);
	Cpmv & operator=(Cpmv && mv);
	Cpmv operator+(const Cpmv & obj) const;
	void Display() const;
private:
	Info *pi;
};

Cpmv::Cpmv()
{
	pi = new Info;
	cout << "Default constructor called." << endl;
}
Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "Constructor with two strings input." << endl;
}
Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy Constructor with lvalue." << endl;
}
Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
	cout << "Move constructor with rvalue." << endl;
}
Cpmv::~Cpmv()
{
	delete pi;
	cout << "Destructor called." << endl;
}
Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	cout << "Copy Assignment called. Lvalue" << endl;
	if (this == &cp)
		return *this;
	else
	{	
		delete pi;
		pi = new Info;
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		return *this;
	}
}
void Cpmv::Display() const
{
	cout << " Qcode : " << pi->qcode << endl;
	cout << " Zcode : " << pi->zcode << endl;
}
Cpmv & Cpmv::operator=(Cpmv && mv)
{
	cout << "Move Assignment called. Rvalue" << endl;
	if (this == &mv)
		return *this;
	else
	{
		pi = mv.pi;
		mv.pi = nullptr;
		return *this;
	}
}
Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	cout << "Operator + called." << endl;
	cout << "Created a temporary Cvmp inside operator+() : \n";
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	return temp;
}