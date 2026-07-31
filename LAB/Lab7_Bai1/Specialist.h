#pragma once

#include "NhanSu.h"
#include "NCS.h"

class Specialist : public NhanSu {
private:
	vector <string> projectsID;
	int yearWorking = 0;
public:
	// CONSTRUCTOR
	Specialist() = default;
	~Specialist() {
		projectsID.clear();
	}

	// HELPER FUNCTION
	double calculateSalary() override;
	int numProjects();

	// INPUT OUTPUT STREAM
	void nhap(istream& inDev) override;
	void xuat(ostream& outDev) const override;
};