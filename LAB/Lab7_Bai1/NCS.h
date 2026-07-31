#pragma once

#include "NhanSu.h"
#include <vector>

class NCS : public NhanSu {
private:
	vector <string> projectsID;
	int yearWorking;
public:
	// CONSTRUCTOR
	NCS() = default;
	~NCS() {
		projectsID.clear();
	}

	// HELPER FUNCTIONS
	double calculateSalary() override;
	int numProjects();

	// INPUT OUTPUT STREAM
	void nhap(istream& inDev) override;

	void xuat(ostream& outDev) const override;
};