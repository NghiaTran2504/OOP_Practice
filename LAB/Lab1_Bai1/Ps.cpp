#include "Ps.hpp"

std::istream& operator >> (std::istream& in, PhanSo& ps) {
	in >> ps.tuSo >> ps.mauSo;
	return in;
}

std::ostream& operator << (std::ostream& out, const PhanSo& ps) {
	out << ps.tuSo << "/" << ps.mauSo << " hay " << (double)ps.tuSo / ps.mauSo;
	return out;
}

int PhanSo::getDenominator() {
	return this->mauSo;
}

int PhanSo::getNumerator() {
	return this->tuSo;
}

void PhanSo::setNumerator(int num) {
	this->tuSo = num;
}

void PhanSo::setDenominator(int num) {
	if (num != 0) this->mauSo = num;
}
void quyDongHaiPhanSo(PhanSo& ps1, PhanSo& ps2) {
	int lcm = ps1.getDenominator() * ps2.getDenominator() / std::gcd(ps1.getDenominator(), ps2.getDenominator());
	ps1.setNumerator(lcm / ps1.getDenominator() * ps1.getNumerator());
	ps2.setNumerator(lcm / ps2.getDenominator() * ps2.getNumerator());
	ps1.setDenominator(lcm);
	ps2.setDenominator(lcm);
}

void rutGonPhanSo(PhanSo& ps) {
	int gcd = std::gcd(ps.getNumerator(), ps.getDenominator());
	ps.setNumerator(ps.getNumerator() / gcd);
	ps.setDenominator(ps.getDenominator() / gcd);
}
PhanSo PhanSo::operator+ (const PhanSo& ps) {
	PhanSo tmp1 = *this, tmp2 = ps;
	quyDongHaiPhanSo(tmp1, tmp2);
	tmp1.tuSo += tmp2.tuSo;
	return tmp1;
}

PhanSo PhanSo::operator - (const PhanSo& ps) {
	PhanSo tmp1 = *this, tmp2 = ps;
	tmp2.tuSo *= -1;
	return tmp1 + tmp2;
}

PhanSo PhanSo::operator* (const PhanSo& ps) {
	PhanSo tmp1 = *this, tmp2 = ps;
	tmp1.tuSo *= tmp2.tuSo;
	tmp1.mauSo *= tmp2.mauSo;
	rutGonPhanSo(tmp1);
	return tmp1;
}

PhanSo PhanSo::operator / (const PhanSo& ps) {
	PhanSo tmp1 = *this, tmp2 = ps;
	if (tmp2.getNumerator() != 0) std::swap(tmp2.tuSo, tmp2.mauSo);
	return tmp1 * tmp2;
}

