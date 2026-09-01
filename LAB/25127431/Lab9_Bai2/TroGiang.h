#pragma once

#include "NhanSu.h"

using namespace std;

class TroGiang : public NhanSu {
private:
	int soMonTroGiang = 0;
public:
	TroGiang() = default;
	TroGiang(const TroGiang& other) : NhanSu(other) {
		soMonTroGiang = other.soMonTroGiang;
	}
	~TroGiang() = default;

	string LayTenDoiTuong() override {
		return "TroGiang";
	}

	double CalculateSalary() override {
		return (soMonTroGiang * 0.3) * 18000;
	}

	NhanSu* Clone() override {
		return new TroGiang(*this);
	}

	void Nhap(istream& inDev) override {
		NhanSu::Nhap(inDev);
		cout << "So mon tro giang: "; inDev >> soMonTroGiang;

		salary = CalculateSalary();
	}

	void Xuat(ostream& outDev) const override {
		NhanSu::Xuat(outDev);
		outDev << "\n==== THONG TIN TRO GIANG ==== \n";
		outDev << "So mon tro giang: " << soMonTroGiang << " | Luong: " << salary << "\n";
	}
};