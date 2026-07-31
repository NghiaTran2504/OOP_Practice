#pragma once

#include <string>
#include <iostream>

class NhanVien {
private:
	std::string fullName, nickName, chucDanh;
	double heSoLuong = 0;
	int dayWorking = 0;
public:
	std::string get_fullName() const { return fullName; }
	std::string get_nickName() const { return nickName; }
	std::string get_chucDanh() const { return chucDanh; }
	double get_heSoLuong() const { return heSoLuong; }
	int get_dayWorking() const { return dayWorking; }


	// ==== Constructor 1 ====
	NhanVien() = default;

	// ==== Constructor 2 =====
	NhanVien(std::string fn, std::string nn, std::string cd, double hsl, int dw)
		: fullName(fn), nickName(nn), chucDanh(cd), heSoLuong(hsl), dayWorking(dw) {}

	NhanVien(std::string fn, int dw);
	NhanVien(const NhanVien& nv);
	
	~NhanVien() {
		std::cout << "\nCLEARED ALL DATA!!!\n";
	}

	friend std::istream& operator >> (std::istream& in, NhanVien& nv);
	friend std::ostream& operator << (std::ostream& out, const NhanVien& nv) ;
};