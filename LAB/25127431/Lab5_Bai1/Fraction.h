#pragma once

#include <iostream>

class Fraction {
private:
	int* tuSo = new int;
	int* mauSo = new int{ 1 };
	static int dem;
public:
	// ===== CONSTRUCTOR, DESTRUCTOR ===== //
	Fraction() = default;
	~Fraction();
	Fraction(int tu, int mau);
	Fraction(int tu);
	Fraction(const Fraction& other);


	// ===== GETTER, SETTER ====== // 
	int getTu() const { return *this->tuSo; }
	int getMau() const { return *this->mauSo;  }
	bool setMau(int mau);
	void setTu(int tu);

	// ===== OPERATOR ===== //
	Fraction& operator = (const Fraction& other);
	Fraction operator + (const Fraction& other) const;
	Fraction operator - (const Fraction& other) const;
	Fraction operator * (const Fraction& other) const;
	Fraction operator / (const Fraction& other) const;

	Fraction& operator += (const Fraction& other);
	Fraction& operator -= (const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);

	bool operator == (const Fraction& other) const;
	bool operator < (const Fraction& other) const;
	bool operator > (const Fraction& other) const;
	bool operator <= (const Fraction& other) const;
	bool operator >= (const Fraction& other) const;
	bool operator != (const Fraction& other) const;

	Fraction& operator ++ ();	// prefix ++a
	Fraction& operator -- ();	// prefix --a
	Fraction operator ++ (int); // postfix a++
	Fraction operator -- (int); // postfix a--


	friend std::istream& operator >> (std::istream& inDev, Fraction& ps);
	friend std::ostream& operator << (std::ostream& outDev, const Fraction& ps);

	// ====== HELPER FUNCTION ===== //
	void rutGon();
	void quyDong(Fraction& other);
	friend int gcd(int a, int b);
	friend int lcm(int a, int b);
	void resetDem(int num);
};

int gcd(int a, int b);
int lcm(int a, int b);
