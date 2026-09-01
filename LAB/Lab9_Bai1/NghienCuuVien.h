#pragma once

#include "NhanSu.h"

using namespace std;

class NghienCuuVien : public NhanSu {
private:
	vector <string> maDuAn;
	int yearExperience = 0;
public:
	NghienCuuVien() = default;
	NghienCuuVien(const NghienCuuVien& other) : NhanSu(other) {
		maDuAn = other.maDuAn;
		yearExperience = other.yearExperience;
	}
	~NghienCuuVien() = default;

	string LayTenDoiTuong() override {
		return "NghienCuuVien";
	}

	double CalculateSalary() override {
		return (yearExperience * 2 + NumProjects()) * 20000;
	}

	NhanSu* Clone() override {
		return new NghienCuuVien(*this);
	}


	int NumProjects() const;

	void Nhap(istream& inDev) override;
	void Xuat(ostream& outDev) const override;

};