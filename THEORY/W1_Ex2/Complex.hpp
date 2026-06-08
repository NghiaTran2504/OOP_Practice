#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <string>

class Complex {
private:
	double realPart, imaginaryPart;
public:
	double getReal();
	double getImaginary();
	void setReal(double num);
	void setImaginary(double num);
	double modulus();
	Complex operator + (const Complex& a);
	Complex operator - (const Complex& a);
	Complex operator * (const Complex& a);
	Complex operator / (const Complex& a);
	friend std::istream& operator >> (std::istream& in, Complex& a);
	friend std::ostream& operator << (std::ostream& out, const Complex& a);

};
#endif 