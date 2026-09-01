#include "TroGiang.h"

void TroGiang::nhap(istream& inDev) {
	cout << "==================================\n";
	cout << "==== NHAP THONG TIN TRO GIANG ====\n";
	cout << "==================================\n";
	NhanSu::nhap(inDev);
	cout << "Input number of subjects assisted: ";
	inDev >> numSubjectAssist;
	setSalary(calculateSalary());
}

double TroGiang::calculateSalary() {
	double ans = numSubjectAssist * 0.3 * 18000;
	return ans;
}

void TroGiang::xuat(ostream& outDev) const {
	outDev << "===============================\n";
	outDev << "==== THONG TIN TRO GIANG ======\n";
	outDev << "===============================\n";
	NhanSu::xuat(outDev);
	outDev << "Number of assisted subject: " << numSubjectAssist << "\n";
	outDev << "--> Salary: " << getSalary() << "\n";
}