#include "Fraction.h"

#include <string>
#include <sstream>

using namespace std;
int Fraction::dem = 1;

// ===== CONSTRUCTOR, DESTRUCTOR ===== //
Fraction::~Fraction() {
	delete tuSo; tuSo = nullptr;
	delete mauSo; mauSo = nullptr;
}

Fraction::Fraction(int tu, int mau) {
	tuSo = new int;
	mauSo = new int;

	*tuSo = tu;
	if (mau == 0) {
		*mauSo = 1;
	}
	else *mauSo = mau;
}

Fraction::Fraction(int tu) {
	tuSo = new int;
	mauSo = new int;

	*tuSo = tu;
	*mauSo = 1;
}

Fraction::Fraction(const Fraction& other) {
	tuSo = new int;
	mauSo = new int;

	*tuSo = other.getTu();
	*mauSo = other.getMau();
}

// ====== SETTER ====== //
void Fraction::setTu(int tu) {
	*tuSo = tu;
}

bool Fraction::setMau(int mau) {
	if (mau == 0) return false;
	*mauSo = mau;
	return true;
}
//-----------------------------------------------//
// ====== HELPER FUNCTION ===== //
void Fraction::rutGon() {
	int soRutGon = gcd(*tuSo, *mauSo);
	*tuSo /= soRutGon;
	*mauSo /= soRutGon;
}

void Fraction::quyDong(Fraction& other) {
	int mauChung = lcm(this->getMau(), other.getMau());
	
	this->setTu(this->getTu() * mauChung / this->getMau());
	other.setTu(other.getTu() * mauChung / other.getMau());

	this->setMau(mauChung);
	other.setMau(mauChung);

}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

void Fraction::resetDem(int num) {
	dem = num;
}
//--------------------------------------------------------//
// ===== OPERATOR ===== //
Fraction& Fraction::operator= (const Fraction& other) {
	if (this == &other)
		return *this;

	*tuSo = other.getTu();
	*mauSo = other.getMau();
	return *this;
}

Fraction Fraction::operator + (const Fraction& other) const {
	int mauChung = lcm(*mauSo, other.getMau());
	Fraction ans;
	ans.setMau(mauChung);
	int heSoNhan1 = mauChung / *mauSo;
	int heSoNhan2 = mauChung / other.getMau();
	ans.setTu(*tuSo * heSoNhan1 + other.getTu() * heSoNhan2);
	ans.rutGon();

	return ans;
}

Fraction Fraction::operator - (const Fraction& other) const {
	Fraction ps = other;
	*ps.tuSo *= -1;
	Fraction ans = *this;
	return ans + ps;
}

Fraction Fraction::operator * (const Fraction& other) const {
	Fraction ans;
	ans.setTu(this->getTu() * other.getTu());
	ans.setMau(this->getMau() * other.getMau());

	ans.rutGon();
	return ans;
}

Fraction Fraction::operator / (const Fraction& other) const {
	Fraction ans = *this;
	Fraction ps = other;
	swap(ps.tuSo, ps.mauSo);

	return ans * ps;
}
// ---------------------------------------------------------

Fraction& Fraction::operator += (const Fraction& other) {
	*this = *this + other;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& other) {
	*this = *this - other;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& other) {
	*this = *this * other;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& other) {
	*this = *this / other;
	return *this;
}
//----------------------------------------------------------

bool Fraction::operator== (const Fraction& other) const {
	return (*tuSo * other.getMau() == *mauSo * other.getTu());
}

bool Fraction::operator != (const Fraction& other) const {
	return !(*this == other);
}

bool Fraction::operator < (const Fraction& other) const {
	return (*tuSo * other.getMau() < *mauSo * other.getTu());
}

bool Fraction::operator > (const Fraction& other) const {
	return (*tuSo * other.getMau() > *mauSo * other.getTu());
}

bool Fraction::operator <= (const Fraction& other) const {
	return (*this < other || *this == other);
}

bool Fraction::operator >= (const Fraction& other) const {
	return (*this > other || *this == other);
}
//-----------------------------------------------------------

Fraction& Fraction::operator ++ () {
	this->setTu(this->getTu() + this->getMau());
	return *this;
}

Fraction& Fraction::operator -- () {
	this->setTu(this->getTu() - this->getMau());
	return *this;
}

Fraction Fraction::operator ++ (int dummy) {
	Fraction tmp = *this;
	++*this;
	return tmp;
}

Fraction Fraction::operator -- (int dummy) {
	Fraction tmp = *this;
	--*this;
	return tmp;
}
//----------------------------------------------

istream& operator >> (istream& inDev, Fraction& ps) {
	int tu = 0, mau = 1;
	string s;

	while (true) {
		cout << "NHAP PHAN SO (dang a/b hoac a b): ";
		if (getline(inDev >> ws, s)) {
			stringstream ss(s);
			if (!(ss >> tu)) {
				cout << "\n--> TU SO KHONG HOP LE! VUI LONG NHAP LAI.\n\n";
				continue;
			}

			ss >> ws;
			if (ss.peek() == '/') {
				char slash;
				ss >> slash;
			}

			if (!(ss >> mau) || mau == 0) {
				cout << "\nMAU SO KHONG HOP LE! VUI LONG NHAP LAI\n\n";
				continue;
			}
		}
		break;
	}
	ps.setTu(tu);
	ps.setMau(mau);
	return inDev;
}

ostream& operator << (ostream& outDev, const Fraction& ps) {
	outDev << ps.getTu() << "/" << ps.getMau() << "\n";
	return outDev;
}