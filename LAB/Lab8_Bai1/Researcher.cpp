#include "Researcher.h"

// HELPER FUNCTIONS
int Researcher::numProjects() {
	int count = 0;
	for (int i = 0; i < projectsID.size(); ++i) {
		if (projectsID[i][0] == 'D') count++;
	}

	return count;
}

double Researcher::calculateSalary() {
	double ans = (yearWorking * 2 + numProjects()) * 20000;
	return ans;
}

// INPUT OUTPUT STREAM
void Researcher::nhap(istream& inDev) {
	cout << "========================================\n";
	cout << "==== NHAP THONG TIN NGHIEN CUU VIEN ====\n";
	cout << "========================================\n";

	NhanSu::nhap(inDev);
	cout << "Input year of researching: "; inDev >> yearWorking;
	cout << "Input number of researched projects: "; 
	int n; inDev >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cout << "ID project " << i + 1 << " (EX: M01, X92): ";
		getline(inDev >> ws, s);
		projectsID.push_back(s);
	}
	setSalary(calculateSalary());
}

void Researcher::xuat(ostream& outDev) const {
	outDev << "=====================================\n";
	outDev << "===== THONG TIN NGHIEN CUU VIEN =====\n";
	outDev << "=====================================\n";

	NhanSu::xuat(outDev);
	outDev << "Year of researching: " << yearWorking << "\n";
	outDev << "Number of researched projects: " << projectsID.size() << "\n";
	outDev << "===== LIST PROJECTS ID =====\n";
	for (int i = 0; i < projectsID.size(); ++i) {
		outDev << projectsID[i] << '\n';
	}
	outDev << "--> Salary: " << getSalary() << "\n";
}