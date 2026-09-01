#include "ChuyenVien.h"

int ChuyenVien::NumProjects() const{
	int count = 0;
	for (const string& s : maDuAn) {
		if (!s.empty() && s[0] == 'T') count++;
	}
	return count;
}

void ChuyenVien::Nhap(istream& inDev) {
	NhanSu::Nhap(inDev);
	cout << "So nam kinh nghiem nghien cuu: "; inDev >> yearExperience;
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

void ChuyenVien::Xuat(ostream& outDev) const {
	NhanSu::Xuat(outDev);
	outDev << "\n==== THONG TIN CHUYEN VIEN==== \n";
	outDev << "So nam kinh nghiem: " << yearExperience << " | " << "So du an: " << maDuAn.size() << " | Luong: " << salary << "\n";
	outDev << "==== DANH SACH DU AN ====\n";
	for (const string& s : maDuAn)
		outDev << s << endl;
}