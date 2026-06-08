#include "Complex.hpp"

double Complex::getReal() {
	return this->realPart;
}

double Complex::getImaginary() {
	return this->imaginaryPart;
}

void Complex::setImaginary(double num) {
	this->imaginaryPart = num;
}

void Complex::setReal(double num) {
	this->realPart = num;
}

Complex Complex::operator+ (const Complex& a) {
	Complex ans;
	ans.realPart = this->realPart + a.realPart;
	ans.imaginaryPart = this->imaginaryPart + a.imaginaryPart;
	return ans;
}

Complex Complex::operator - (const Complex& a) {
	Complex ans;
	ans.realPart = this->realPart - a.realPart;
	ans.imaginaryPart = this->imaginaryPart - a.imaginaryPart;
	return ans;
}

Complex Complex::operator * (const Complex& a) {
	Complex ans;
	ans.realPart = this->realPart * a.realPart - this->imaginaryPart * a.imaginaryPart;
	ans.imaginaryPart = this->realPart * a.imaginaryPart + this->imaginaryPart * a.realPart;
	return ans;
}

Complex Complex::operator / (const Complex& a) {
	Complex ans;
	ans.realPart = (this->realPart * a.realPart + this->imaginaryPart * a.imaginaryPart) / 
		(std::pow(a.realPart, 2) + std::pow(a.imaginaryPart, 2));

	ans.imaginaryPart = (a.realPart * this->imaginaryPart - a.imaginaryPart * this->realPart) /
		(std::pow(a.realPart, 2) + std::pow(a.imaginaryPart, 2));

	return ans;
}

double Complex::modulus() {
	return std::sqrt(std::pow(this->realPart, 2) + std::pow(this->imaginaryPart, 2));
}

std::istream& operator >> (std::istream& in, Complex& a) {
	std::string real, imaginary;
	in >> real >> imaginary;
	// Khong tim thay dau '/'
	if (real.find('/') == std::string::npos) {
		a.realPart = std::stod(real);
	}
	else {
		int pos = real.find('/');
		double tuSo = stod(real.substr(0, pos));
		double mauSo = stod(real.substr(pos + 1, real.size() - 1 - pos));
		a.realPart = tuSo / mauSo;
	}

	if (real.find('/') == std::string::npos) {
		a.imaginaryPart = std::stod(imaginary);
	}
	else {
		int pos = imaginary.find('/');
		double tuSo = stod(imaginary.substr(0, pos));
		double mauSo = stod(imaginary.substr(pos, imaginary.size() - 1 - pos));
		a.imaginaryPart = tuSo / mauSo;
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Complex& a) {
	out << a.realPart;
	if (a.imaginaryPart >= 0) out << "+" << a.imaginaryPart << "i";
	else out << a.imaginaryPart << "i";
	return out;
}
