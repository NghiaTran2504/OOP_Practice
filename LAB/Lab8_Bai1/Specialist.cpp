#include "Specialist.h"

// HELPER FUNCTION
double Specialist::calculateSalary() {
	double ans = (yearWorking * 4 + numProjects()) * 18000;
	return ans;
}

int Specialist::numProjects() {
	int count = 0;
	for (int i = 0; i < projectsID.size(); ++i) {
		if (projectsID[i][0] == 'T') count++;
	}

	return count;
}

// INPUT OUTPUT STREAM
void Specialist::nhap(istream& inDev) {
	cout << "====================================\n";
	cout << "==== NHAP THONG TIN CHUYEN VIEN ====\n";
	cout << "====================================\n";

	NhanSu::nhap(inDev);
	cout << "Input year of working: "; inDev >> yearWorking;
	cout << "Input number of educational projects: ";
	int n; inDev >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cout << "ID project " << i + 1 << " (EX: M01, X92): ";
		getline(inDev >> ws, s);
		projectsID.push_back(s);
	}
	setSalary(calculateSalary());
}

void Specialist::xuat(ostream& outDev) const {
	outDev << "=================================\n";
	outDev << "===== THONG TIN CHUYEN VIEN =====\n";
	outDev << "=================================\n";

	NhanSu::xuat(outDev);
	outDev << "Year of working: " << yearWorking << "\n";
	outDev << "Number of educational projects: " << projectsID.size() << "\n";
	outDev << "===== LIST PROJECTS ID =====\n";
	for (int i = 0; i < projectsID.size(); ++i) {
		outDev << projectsID[i] << '\n';
	}
	outDev << "--> Salary: " << getSalary();
}