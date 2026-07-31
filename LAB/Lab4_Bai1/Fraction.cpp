#include "Fraction.hpp"
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

// ===== Constructor ===== //
Fraction::Fraction(int tuSo) {
	this->tuSo = new int;
	this->mauSo = new int;
	*this->tuSo = tuSo;
	*this->mauSo = 1;
}

Fraction::Fraction(int tuSo, int mauSo)
{
	this->tuSo = new int;
	this->mauSo = new int;
	*this->tuSo = tuSo;
	*this->mauSo = (mauSo == 0) ? 1 : mauSo;
}

Fraction::Fraction(const Fraction& phanSo)
{
	this->tuSo = new int;
	this->mauSo = new int;
	*tuSo = *phanSo.tuSo;
	*mauSo = *phanSo.mauSo;
}

Fraction::~Fraction()
{
	delete tuSo;
	tuSo = nullptr;
	delete mauSo;
	mauSo = nullptr;
}

// ===== Getter, Setter ===== //
int Fraction::getTu() const
{
	return *this->tuSo;
}

int Fraction::getMau() const
{
	return *this->mauSo;
}

bool Fraction::setTu (int tu)
{
	*this->tuSo = tu;
	return true;
}

bool Fraction::setMau(int mau)
{
	if (mau == 0) return false;
	*this->mauSo = mau;
	return true;
}
 
// ===== OPERATOR =====//

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void Fraction::rutGon(Fraction& ps)
{
	int tmp = gcd(ps.getTu(), ps.getMau());
	ps.setTu(ps.getTu() / tmp);
	ps.setMau(ps.getMau() / tmp);
}
Fraction Fraction::operator + (const Fraction& ps)
{
	int mauChung = this->getMau() * ps.getMau() / gcd(this->getMau(), ps.getMau());
	Fraction ans;
	ans.setMau(mauChung);
	int tu = (mauChung / this->getMau()) * this->getTu() + (mauChung / ps.getMau()) * ps.getTu();
	ans.setTu(tu);
	ans.rutGon(ans);
	return ans;
}

Fraction Fraction::operator - (const Fraction& ps)
{
	Fraction ans;
	Fraction tmp(ps);
	tmp.setTu(-tmp.getTu());
	ans = *this + tmp;
	rutGon(ans);
	return ans;
}

Fraction Fraction::operator* (const Fraction& ps)
{
	Fraction ans;

	// In case number overflow
	Fraction tmp1 = *this;
	Fraction tmp2 = ps;
	rutGon(tmp1); 
	rutGon(tmp2);

	ans.setTu(tmp1.getTu() * tmp2.getTu());
	ans.setMau(tmp1.getMau() * tmp2.getMau());
	rutGon(ans);
	return ans;
}

Fraction Fraction::operator / (const Fraction& ps)
{
	Fraction ans;
	Fraction thisFraction = *this;
	Fraction tmp;
	tmp.setTu(ps.getMau());
	tmp.setMau(ps.getTu());
	return ans = thisFraction * tmp;
}

Fraction& Fraction::operator = (const Fraction& ps)
{
	this->setTu(ps.getTu());
	this->setMau(ps.getMau());
	return *this;
}

std::istream& operator >> (std::istream& in, Fraction& ps)
{
	int tu, mau;
	std::string res;

	if (std::getline(in >> std::ws, res)) {
		std::stringstream ss(res);

		if (ss >> tu) {
			ss >> std::ws;

			if (ss.peek() == '/') {
				char rac;
				ss >> rac;
			}
		}

		if (ss >> mau) {};
	}

	ps.setTu(tu);
	if (!ps.setMau(mau)) {
		std::cout << "\nMAU SO KHONG HOP LE. VUI LONG THU LAI\n";
		*ps.mauSo = 0;
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Fraction& ps)
{
	out << ps.getTu() << "/" << ps.getMau();
	out << " (~ " << std::fixed << std::setprecision(3) << static_cast<double>(ps.getTu()) / ps.getMau() << ")";
	return out;
}
