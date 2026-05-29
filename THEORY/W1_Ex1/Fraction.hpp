#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <algorithm>
class Fraction {
private:
	int tuSo, mauSo;
	int static dem;
public:
	void reduction();
	void quyDongHaiPhanSo(Fraction& a);
	Fraction inversion();
	void setNumerator();
	void setDemominator();
	int getNumerator();
	int getDenominator();
	void resetDem();
	int getDem();
	void updateDem();
	Fraction operator + (const Fraction& a);
	Fraction operator - (const Fraction& a);
	Fraction operator * (const Fraction& a);
	Fraction operator / (const Fraction& a);
	friend std::istream& operator >> (std::istream& in, Fraction& a);
	friend std::ostream& operator << (std::ostream& out, const Fraction& a);
};	

#endif