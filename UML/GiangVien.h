#pragma once
#include "NhanSu.h"

#include <vector>

class GiangVien : public NhanSu {
private:
	string hocHam;
	string hocVi;
	int yearTeaching = 0;
	vector <string> listSubject;
public:
	// CONSTRUCTOR, DESTRUCTOR
	GiangVien() = default;
	GiangVien(string name, string dob, string id, string a, string b, int year) : NhanSu(name, dob, id), hocHam(a), hocVi(b), yearTeaching(year) {}
	virtual ~GiangVien() {
		yearTeaching = 0;
		listSubject.clear();
	}

	// GETTER, SETTER
	string getHocHam() const { return hocHam; }
	string getHocVi() const { return hocVi; }
	int getYearTeaching() const { return yearTeaching; }
	vector <string> getListSubject() const { return listSubject; }

	// HELPER FUNCTION
	void setHocHam(string s) { hocHam = s; }
	void setHocVi(string s) { hocVi = s; }
	void setYearTeaching(int n) { yearTeaching = n; }
	void setListSubject(int n) {
		if (listSubject.size() != 0) 
			listSubject.clear();

		for (int i = 1; i <= n; ++i) {
			cout << "Subject " << i << ": ";
			string subject;
			getline(cin >> ws, subject);
			listSubject.push_back(subject);
		}
	}

	double calculateSalary() override;

	// INPUT OUTPUT STREAM
	void nhap(istream& inDev) override;
	void xuat(ostream& outDev) const override;
};