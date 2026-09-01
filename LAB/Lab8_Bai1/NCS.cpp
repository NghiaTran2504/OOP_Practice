#include "NCS.h"

// HELPER FUNCTION
double NCS::calculateSalary() {
	return 0.1 * numProjects() * 10000;
}

int NCS::numProjects() {
	int count = 0;
	for (int i = 0; i < ncsProjectsID.size(); ++i) {
		if (ncsProjectsID[i][0] == 'R') count++;
	}
	return count;
}

// INPUT OUTPUT STREAM
void NCS::nhap(istream& inDev) {
	cout << "========================================\n";
	cout << "==== NHAP THONG TIN NGHIEN CUU SINH ====\n";
	cout << "========================================\n";

	NhanSu::nhap(inDev);
	cout << "Input number of researched projects: ";
	int n; inDev >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cout << "ID project " << i + 1 << " (EX: M01, X92): ";
		getline(inDev >> ws, s);
		ncsProjectsID.push_back(s);
	}
	setSalary(calculateSalary());
}

void NCS::xuat(ostream& outDev) const {
	outDev << "=====================================\n";
	outDev << "===== THONG TIN NGHIEN CUU SINH =====\n";
	outDev << "=====================================\n";

	NhanSu::xuat(outDev);
	outDev << "Number of researched projects: " << ncsProjectsID.size() << "\n";
	outDev << "===== LIST PROJECTS ID =====\n";
	for (int i = 0; i < ncsProjectsID.size(); ++i) {
		outDev << ncsProjectsID[i] << '\n';
	}
	outDev << "--> Salary: " << getSalary() << "\n";
}