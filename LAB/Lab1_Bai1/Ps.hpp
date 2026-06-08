#ifndef PHANSO_HPP
#define PHANSO_HPP

#include <iostream>
#include <algorithm>
#include <numeric>

class PhanSo {
private:
	int tuSo, mauSo;
public:
	int getNumerator();
	int getDenominator();
	void setNumerator(int num);
	void setDenominator(int num);
	friend std::istream& operator >> (std::istream& in, PhanSo& ps);
	friend std::ostream& operator << (std::ostream& out, const PhanSo & ps);
	PhanSo operator + (const PhanSo& ps);
	PhanSo operator - (const PhanSo& ps);
	PhanSo operator * (const PhanSo& ps);
	PhanSo operator / (const PhanSo& ps);
};
#endif