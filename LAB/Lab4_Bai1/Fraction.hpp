#pragma once

#include <iostream>

class Fraction {
private:
	int* tuSo = new int;
	int* mauSo = new int{ 1 };
public:
	// ---- Constructor ---- //
	Fraction() = default;
	Fraction(int tuSo);
	Fraction(int tuSo, int mauSo);
	Fraction(const Fraction&);
	~Fraction();

	// ---- Getter, Setter ---- //
	int getTu() const ;
	int getMau() const;
	bool setTu(int);
	bool setMau(int);

	// ---- Operator ---- //
	void rutGon(Fraction&);
	Fraction operator + (const Fraction&);
	Fraction operator - (const Fraction&);
	Fraction operator * (const Fraction&);
	Fraction operator / (const Fraction&);
	Fraction& operator = (const Fraction&);
	friend std::istream& operator >> (std::istream& in, Fraction&);
	friend std::ostream& operator << (std::ostream & out, const Fraction&);
};