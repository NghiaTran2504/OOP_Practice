#include "NhanVien.hpp"
#include <iomanip>

// ==== Constructor 3 ====
NhanVien::NhanVien(std::string fn, int dw) : fullName(fn), dayWorking(dw) {
	// ==== Find name only ====
	int pos = fullName.rfind(' ');
	std::string nameOnly = (pos == std::string::npos) ? fullName : fullName.substr(pos + 1);

	if (dayWorking <= 365) {
		chucDanh = "Nhan vien";
		heSoLuong = 1.0;
		nickName = chucDanh + " " + nameOnly;
	}

	else if (dayWorking <= 730) {
		chucDanh = "Quan ly";
		heSoLuong = 1.5;
		nickName = chucDanh + " " + nameOnly;
	}
	else if (dayWorking <= 1460) {
		chucDanh = "Truong phong";
		heSoLuong = 2.25;
		nickName = chucDanh + " " + nameOnly;
	}
	else {
		chucDanh = "Truong ban quan ly";
		heSoLuong = 4.0;
		nickName = chucDanh + " " + nameOnly;
	}
}

// ==== Constructor 4 =====
NhanVien::NhanVien(const NhanVien& nv) {
	chucDanh = nv.get_chucDanh();
	heSoLuong = nv.get_heSoLuong();
	dayWorking = nv.get_dayWorking();
}

std::istream& operator >> (std::istream & in, NhanVien & nv) {
	std::string name_tmp;
	int dayWorking_tmp;
	std::cout << "Nhap ho ten: ";
	getline(in >> std::ws, name_tmp);

	while (1) {
		std::cout << "Nhap so ngay lam viec: ";
		in >> dayWorking_tmp;
		if (dayWorking_tmp < 0) std::cout << " ==> So ngay lam viec phai tu 0 tro len!\n\n";
		else break;
	}

	nv = NhanVien(name_tmp,dayWorking_tmp); // Default assignment operator (shallow copy)
	return in;
}

std::ostream& operator << (std::ostream& out, const NhanVien& nv) {
	std::cout << "Ho va ten: " << nv.fullName << "\n";
	std::cout << "So ngay lam da lam viec: " << nv.dayWorking << "\n";
	std::cout << "Chuc danh: " << nv.chucDanh << "\n";
	std::cout << "Ten goi cua nhan vien: " << nv.nickName << "\n";
	std::cout << "He so luong cua nhan vien: " << std::fixed << std::setprecision(2) << nv.heSoLuong << "\n";
	return out;
}