#pragma once

#include "NhanSu.h"

using namespace std;

class GiangVien : public NhanSu {
private:
	string hocHam, hocVi;
	int yearTeaching = 0;
	vector <string> dsMonHoc;

public:
	GiangVien() = default;
	GiangVien(const GiangVien& other) : NhanSu(other) {
		hocHam = other.hocHam;
		hocVi = other.hocVi;
		yearTeaching = other.yearTeaching;
		dsMonHoc = other.dsMonHoc;
	}
	~GiangVien() = default;

	string LayTenDoiTuong() override {
		return "GiangVien";
	}

	double CalculateSalary() override{
		return (dsMonHoc.size() * yearTeaching * 0.12) * 20000;
	}

	NhanSu* Clone() override {
		return new GiangVien(*this);
	}

	void Nhap(istream& inDev) override;
	void Xuat(ostream& outDev) const override;
};