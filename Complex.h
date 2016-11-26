#pragma once
#ifndef COMPLEX_NUM
#define COMPLEX_NUM

#include<iostream>
using namespace std;
class complex
{
	double x, y;
public:
	complex(double a = 0.0, double b = 0.0) { x = a; y = b; }
	complex operator+(const complex&);
	complex operator-(const complex&);
	complex operator*(const complex&);
	complex operator~() const;
	friend complex operator*(int, const complex&);
	friend istream& operator>>(istream&, complex&);
	friend ostream& operator<<(ostream&, const complex&);
};
complex complex::operator+(const complex & c)
{
	complex result = { x + c.x,y + c.y };
	return result;
}
complex complex::operator-(const complex & c)
{
	complex result = { x - c.x,y - c.y };
	return result;
}
complex complex::operator*(const complex & c)
{
	complex result = { (x * c.x) - (y * c.y) ,(x*c.y) + (y*c.x) };
	return result;
}
complex operator*(int i , const complex & c)
{
	complex result = { i * c.x, i * c.y };
	return result;
}
complex complex::operator~() const
{
	complex result = { x , -y };
	return result;
}
istream& operator>>(istream& is, complex& c)
{
	cout << "Real : ";
	is >> c.x;
	cout << "Imaginary : ";
	is >> c.y;
}
ostream& operator<<(ostream& os, const complex& c)
{
	os << "(" << c.x << "," << c.y << "i)";
	return os;
}
#endif