#include "GiangVien.h"

// HELPER FUNCTION
double GiangVien::calculateSalary() {
	double ans = listSubject.size() * yearTeaching * 0.12 * 20000;
	return ans;
}

// INPUT OUTPUT STREAM
void GiangVien::nhap(istream& inDev) {
	cout << "==================================\n";
	cout << "==== NHAP THONG TIN GIANG VIEN====\n";
	cout << "==================================\n";
	NhanSu::nhap(inDev);
	cout << "Input hoc ham: ";
	getline(inDev >> ws, hocHam);
	cout << "Input hoc vi: ";
	getline(inDev >> ws, hocVi);
	cout << "Input year of teaching: ";
	inDev >> yearTeaching;
	cout << "Input number of teaching subjects: ";
	int n; inDev >> n;
	setListSubject(n);
	setSalary(calculateSalary());
}

void GiangVien::xuat(ostream& outDev) const {
	outDev << "===============================\n";
	outDev << "==== THONG TIN GIANG VIEN ==== \n";
	outDev << "===============================\n";

	NhanSu::xuat(outDev);
	outDev << "Hoc ham: " << hocHam << "\n";
	outDev << "Hoc vi: " << hocVi << "\n";
	outDev << "Year of teaching: " << yearTeaching << "\n";
	outDev << "===== LIST OF TEACHING SUBJECTS =====\n";
	for (int i = 1; i <= listSubject.size(); ++i) {
		outDev << "Subject " << i << ": " << listSubject[i - 1] << "\n";
	}
	outDev << " --> Salary: " << getSalary() << "\n";
}