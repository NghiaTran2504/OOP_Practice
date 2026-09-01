#pragma once

#include "NhanSu.h"

using namespace std;

class ChuyenVien : public NhanSu {
private:
	vector <string> maDuAn;
	int yearExperience = 0;
public:
	ChuyenVien() = default;
	ChuyenVien(const ChuyenVien& other) : NhanSu(other) {
		maDuAn = other.maDuAn;
		yearExperience = other.yearExperience;
	}
	~ChuyenVien() = default;

	string LayTenDoiTuong() override {
		return "ChuyenVien";
	}

	double CalculateSalary() override {
		return (yearExperience * 4 + NumProjects()) * 18000;
	}

	NhanSu* Clone() override {
		return new ChuyenVien(*this);
	}

	int NumProjects() const;

	void Nhap(istream& inDev) override;
	void Xuat(ostream& outDev) const override;
};