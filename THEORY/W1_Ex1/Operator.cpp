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
	in >> a.tuSo;
	std::cout << "Nhap mau so " << a.dem << ": ";
	in >> a.mauSo;
	a.dem++;
	return in;
}

std::ostream& operator << (std::ostream& out, const Fraction& a) {
	out << a.tuSo << "/" << a.mauSo;
	return out;
}



