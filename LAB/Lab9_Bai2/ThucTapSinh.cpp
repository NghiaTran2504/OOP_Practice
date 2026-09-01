#include "ThucTapSinh.h"

int ThucTapSinh::NumProjects() const {
	int count = 0;
	for (const string& s : maDuAn) {
		if (!s.empty() && s[0] == 'R') count++;
	}
	return count;
}

void ThucTapSinh::Nhap(istream& inDev) {
	NhanSu::Nhap(inDev);
	int n;
	cout << "So du an: "; inDev >> n;

	for (int i = 0; i < n; ++i) {
		cout << "Ma du an " << i + 1 << ": ";
		string s;
		getline(inDev >> ws, s);
		maDuAn.push_back(s);
	}
	salary = CalculateSalary();
}

void ThucTapSinh::Xuat(ostream& outDev) const {
	NhanSu::Xuat(outDev);
	outDev << "\n==== THONG TIN THUC TAP SINH ==== \n";
	outDev << "So du an: " << maDuAn.size() << " | Luong: " << salary << "\n";
	outDev << "==== DANH SACH DU AN ====\n";
	for (const string& s : maDuAn)
		outDev << s << endl;
}