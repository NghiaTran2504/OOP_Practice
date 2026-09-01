#include "GiangVien.h"

void GiangVien::Nhap(istream& inDev) {
	NhanSu::Nhap(inDev);
	cout << "Hoc ham: "; getline(inDev >> ws, hocHam);
	cout << "Hoc vi: "; getline(inDev >> ws, hocVi);
	cout << "So nam giang day: "; inDev >> yearTeaching;

	cout << "So luong mon giang day: ";
	int n; inDev >> n;
	for (int i = 0; i < n; ++i) {
		cout << "Mon thu " << i + 1 << ": ";
		string s;
		getline(inDev >> ws, s);
		dsMonHoc.push_back(s);
	}

	salary = CalculateSalary();
}

void GiangVien::Xuat(ostream& outDev) const {
	NhanSu::Xuat(outDev);
	outDev << "\n==== THONG TIN GIANG VIEN ==== \n";
	outDev << "Hoc ham: " << hocHam << " | Hoc vi: " << hocVi << " | Nam giang day: "
		<< yearTeaching << " | Luong: " << salary << "\n";
	outDev << "Cac mon giang day: ";
	for (auto x : dsMonHoc) outDev << x << " ";
	outDev << "\n";
}