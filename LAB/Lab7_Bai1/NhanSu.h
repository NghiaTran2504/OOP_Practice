#pragma once 
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class NhanSu {
private:
	string name;
	string dob;
	string id;
	double salary = 0;
public:
	// CONSTRUCTOR
	NhanSu() = default;
	NhanSu(string _name, string _dob, string _id, double _salary) : name(_name), dob(_dob), id(_id), salary(_salary) {}
	virtual ~NhanSu() = default;
	string getName() const { return this->name; }
	string getDob() const { return this->dob; }
	string getId() const { return this->id; }
	double getSalary() const { return salary; }

	// GETTER, SETTER
	void setName(string s) { name = s; }
	void setDob(string s) { dob = s; }
	void setId(string s) { id = s; }
	void setSalary(double s) { salary = s; }

	// HELPER FUCNTION
	virtual double calculateSalary() = 0;
	static double totalSalary(const vector <NhanSu*>& list);
	static void clearMemory(vector <NhanSu*>& list);
	static void pushList(istream& inDev, vector <NhanSu*>& list, string& s);
	static void chuanHoa(string& s);

	// INPUT OUTPUT STREAM
	virtual void nhap(istream& in);
	virtual void xuat(ostream& out) const;

	friend istream& operator >> (istream& inDev, NhanSu& obj) {
		obj.nhap(inDev);
		return inDev;
	}
	friend ostream& operator << (ostream& outDev, const NhanSu& obj) {
		obj.xuat(outDev);
		return outDev;
	}

	friend istream& operator >> (istream& inDev, vector <NhanSu*>& list);
	friend ostream& operator << (ostream& outDev, const vector <NhanSu*>& list);
};