#pragma once

#include "NhanSu.h"
#include <vector>

class NCS : public NhanSu {
private:
	vector <string> projectsID;
	int yearWorking = 0;
public:
	// CONSTRUCTOR
	NCS() = default;
	NCS(string name, string dob, string id, double salary, int year) : NhanSu(name, dob, id, salary), yearWorking(year) {}
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