#include "Fraction.hpp"


int Fraction::dem = 1;

void Fraction::reduction() {
	int gcd = std::gcd(this->tuSo, this->mauSo);
	this->tuSo /= gcd;
	this->mauSo /= gcd;
}

void Fraction::quyDongHaiPhanSo(Fraction& a) {
	int mau_chung = (1LL) * (this->mauSo * a.mauSo) / std::gcd(this->mauSo, a.mauSo);
	this->tuSo *= mau_chung / this->mauSo;
	a.tuSo *= mau_chung / a.mauSo;
	this->mauSo = a.mauSo = mau_chung;
}

int Fraction::getDenominator() {
	return this->mauSo;
}

int Fraction::getNumerator() {
	return this->tuSo;
}

Fraction Fraction::inversion() {
	Fraction tmp;
	tmp.tuSo = this->mauSo;
	tmp.mauSo = this->tuSo;
	return tmp;
}

void Fraction::setDemominator() {
	int n;
	while (1) {
		std::cin >> n;
		if (n == 0) {
			std::cout << "Mau khong hop le. Hay thu lai \n";
			std::cout << "Nhap gia tri mau so " << getDem() << ": ";
		}
		else {
			this->mauSo = n;
			break;
		}
	}
}

void Fraction::setNumerator() {
	std::cin >> this->tuSo;
}

void Fraction::resetDem() {
	dem = 1;
}

int Fraction::getDem() {
	return dem;
}

void Fraction::updateDem() {
	dem++;
}