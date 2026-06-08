#include "Student.hpp"

void Student::nhap() {
	while (1) {
		std::cout << "Nhap ho ten hoc sinh: "; getline(std::cin, fullName);
		if (!checkValidInfo("fullname")) {
			std::cout << "Ho ten hoc sinh khong hop le! Vui long nhap lai\n\n";
		}
		else break;
	}

	while (1) {
		std::cout << "Nhap so dien thoai (9 so - 11 so) : "; getline(std::cin, phoneNum);
		if (!checkValidInfo("phonenum")) {
			std::cout << "So dien thoai khong hop le! Vui long nhap lai\n\n";
		}
		else break;
	}

	while (1) {
		std::cout << "Nhap diem trung binh (0 diem - 10 diem): "; std::cin >> avgScore;
		if (!checkValidInfo("avgscore")) {
			std::cout << "Diem trung binh vua nhap khong hop le! Vui long nhap lai\n\n";
		}
		else break;
	}
}

void Student::xuat() {
	std::cout << "\n------- THONG TIN HOC SINH --------\n";
	std::cout << "Ho ten hoc sinh: " << fullName << "\n";
	std::cout << "So dien thoai: " << phoneNum << "\n";
	std::cout << "Diem trung binh: " << avgScore << "\n";
}

bool Student::checkValidInfo(const std::string& s) {
	if (s == "fullname") {
		if (fullName.size() > 20) return false;
		else {
			for (int i = 0; i < fullName.size(); ++i) {
				char c = tolower(fullName[i]);
				if (c != ' ' && (c - 'a' >= 24 || c - 'a' < 0)) return false;
			}
		}

		return true;
	}

	if (s == "phonenum") {
		if (phoneNum.size() < 9 || phoneNum.size() > 11) return false;
		else {
			for (int i = 0; i < phoneNum.size(); ++i) {
				if (phoneNum[i] - '0' > 9) return false;
			}
		}

		return true;
	}

	if (s == "avgscore") {
		if (avgScore < 0 || avgScore > 10) return false;
		return true;
	}

	return true;
}