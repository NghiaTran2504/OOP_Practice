#include "Fraction.hpp"

Fraction Fraction::operator + (const Fraction& a) {
	Fraction tmp1 = *this, tmp2 = a;
	tmp1.quyDongHaiPhanSo(tmp2);
	tmp1.tuSo += tmp2.tuSo;
	tmp1.reduction();
	return tmp1;
}

Fraction Fraction::operator - (const Fraction& a) {
	Fraction tmp1 = *this, tmp2 = a;
	tmp1.quyDongHaiPhanSo(tmp2);
	tmp1.tuSo -= tmp2.tuSo;
	tmp1.reduction();
	return tmp1;
}

Fraction Fraction::operator * (const Fraction& a) {
	Fraction tmp1 = *this, tmp2 = a;
	tmp1.tuSo *= tmp2.tuSo;
	tmp1.mauSo *= tmp2.mauSo;
	tmp1.reduction();
	return tmp1;
}

Fraction Fraction::operator / (const Fraction& a) {
	Fraction tmp1 = *this, tmp2 = a;
	std::swap(tmp2.mauSo, tmp2.tuSo);
	return  tmp1 * tmp2;
}

std::istream& operator >> (std::istream& in, Fraction& a) {
	std::cout << "Nhap tu so " << a.dem << ": ";
	std::cin >> a.tuSo;
	std::cout << "Nhap mau so " << a.dem << ": ";
	std::cin >> a.mauSo;
	a.dem++;
	return in;
}

std::ostream& operator << (std::ostream& out, const Fraction& a) {
	std::cout << a.tuSo << "/" << a.mauSo;
	return out;
}



