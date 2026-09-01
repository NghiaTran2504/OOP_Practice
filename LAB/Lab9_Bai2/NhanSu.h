#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanSu {
protected:
	string name, dob, id;
	double salary = 0;

private:
	static vector <NhanSu*> DoiTuongMau;

public:
	virtual ~NhanSu() = default;

	string getID() const { return this->id; }

	virtual double CalculateSalary() = 0;
	virtual NhanSu* Clone() = 0;
	virtual string LayTenDoiTuong() = 0;
	static void ThemDoiTuongMau(NhanSu* ns);
	static NhanSu* TaoDoiTuongTheoTen(string ten);
	static void XoaDoiTuongMau();

	virtual void Nhap(istream& inDev);
	virtual void Xuat(ostream& outDev) const;

	friend istream& operator >> (istream& inDev, NhanSu& ns) {
		ns.Nhap(inDev);
		return inDev;
	}
	friend ostream& operator << (ostream& outDev, const NhanSu& ns) {
		ns.Xuat(outDev);
		return outDev;
	}
};