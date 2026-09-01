#pragma once

#include "NhanSu.h"

using namespace std;

class ThucTapSinh : public NhanSu {
private:
	vector <string> maDuAn;

public:
	ThucTapSinh() = default;
	ThucTapSinh(const ThucTapSinh& other) : NhanSu(other) {
		maDuAn = other.maDuAn;
	}
	~ThucTapSinh() = default;

	string LayTenDoiTuong() override {
		return "ThucTapSinh";
	}

	double CalculateSalary() override {
		return (0.1 * NumProjects()) * 10000;
	}

	NhanSu* Clone() override {
		return new ThucTapSinh(*this);
	}

	int NumProjects() const;

	void Nhap(istream& inDev) override;
	void Xuat(ostream& outDev) const override;
};