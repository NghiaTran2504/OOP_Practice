#pragma once

#include "Researcher.h"


class NCS : public NhanSu {
private:
	vector <string> ncsProjectsID;
public:
	NCS() = default;
	NCS(string name, string dob, string id, double salary) : NhanSu(name, dob, id, salary) {}
	~NCS() {
		ncsProjectsID.clear();
	}
	
	// HELPER FUNCTION
	double calculateSalary() override;
	int numProjects();

	// INPUT OUTPUT STREAM
	void nhap(istream& inDev) override;
	void xuat(ostream& outDev) const override;
};
