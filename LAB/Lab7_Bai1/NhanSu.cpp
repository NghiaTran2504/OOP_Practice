#include "NhanSu.h"
#include "GiangVien.h"
#include "TroGiang.h"
#include "NCS.h"
#include "Specialist.h"

// HELPER FUNCTIONS
double NhanSu::totalSalary(const vector <NhanSu*>& list) {
	double total = 0;
	for (int i = 0; i < list.size(); ++i) {
		cout << list[i]->getSalary() << "\n";
		total += list[i]->getSalary();
	}

	return total;
}

void NhanSu::clearMemory(vector <NhanSu*>& list) {
	for (int i = 0; i < list.size(); ++i) {
		delete list[i];
	}
	list.clear();
}

void NhanSu::pushList(istream& inDev, vector <NhanSu*>& list, string& s) {
	if (s == "giang vien") {
		NhanSu* p = new GiangVien;
		list.push_back(p);
		inDev >> *p;
	}
	else if (s == "tro giang") {
		NhanSu* p = new TroGiang;
		list.push_back(p);
		inDev >> *p;
	}
	else if (s == "nghien cuu sinh") {
		NhanSu* p = new NCS;
		list.push_back(p);
		inDev >> *p;
	}
	else {
		NhanSu* p = new Specialist;
		list.push_back(p);
		inDev >> *p;
	}
}

void NhanSu::chuanHoa(string& s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = tolower(s[i]);
	}
}

// INPUT OUTPUT STREAM
void NhanSu::nhap(istream& in) {
	cout << "Input name: ";
	getline(in >> ws, name);
	cout << "Input day of birth (dd/mm/yyyy): ";
	getline(in >> ws, dob);
	cout << "Input personal ID: ";
	getline(in >> ws, id);
}

void NhanSu::xuat(ostream& out) const {
	out << "Name: " << name << "\n";
	out << "DOB: " << dob << "\n";
	out << "ID: " << id << "\n";
}

istream& operator >> (istream& inDev, vector <NhanSu*>& listNhanSu) {
	cout << "Number of people: ";
	int n; inDev >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cout << "Role of person " << i + 1 << " (giang vien/tro giang/nghien cuu sinh/chuyen vien): ";
		getline(inDev >> ws, s);
		NhanSu::chuanHoa(s);
		NhanSu::pushList(inDev, listNhanSu, s);
		cout << "\n";
	}
	return inDev;
}

ostream& operator << (ostream& outDev, const vector<NhanSu*>& listNhanSu) {
	outDev << "=============================\n";
	outDev << "===== DANH SACH NHAN SU =====\n";
	outDev << "=============================\n";

	for (int i = 0; i < listNhanSu.size(); ++i) {
		outDev << *listNhanSu[i] << "\n";
	}

	outDev << "==> TOTAL SALARY: " << NhanSu::totalSalary(listNhanSu) << "\n";

	return outDev;
}