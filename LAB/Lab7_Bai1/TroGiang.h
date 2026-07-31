#pragma once

#include "NhanSu.h"

class TroGiang : public NhanSu{
private:
	int numSubjectAssist = 0;
public:
	// CONSTRUCTOR
	TroGiang() = default;
	~TroGiang() = default;
	TroGiang(string name, string dob, string id, int n) : NhanSu(name, dob, id), numSubjectAssist(n) {}

	// HELPER FUNCTION
	double calculateSalary() override;
	// INPUT OUTPUT STREAM
	void nhap(istream& inDev) override;
	void xuat(ostream& outDev) const override;
};