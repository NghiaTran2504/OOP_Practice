#include "Classroom.hpp"

// Cac phuong thuc cua Student
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

std::string Student::getName() {
	return this->fullName;
}

double Student::getAvgScore() {
	return this->avgScore;
}

// *******************************************************

// Cac phuong thuc cua Classroom

void Classroom::addStudent (){
	Student a;
	a.nhap();
	if (std::binary_search(studentList.begin(), studentList.end(), a.getName(), [](Student& tmp, const std::string& name) {
		return tmp.getName() < name;
		})) {
		std::cout << "Da co hoc sinh trong lop! \n";
	}

	else {
		studentList.push_back(a);
		std::cout << "Da them hoc sinh thanh cong!\n";
		std::sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
			return a.getName() < b.getName();
			});
	}
}

void Classroom::removeStudent() {
	std::string name;
	getline(std::cin, name);
	auto it = std::lower_bound(studentList.begin(), studentList.end(), name, [](Student& a, std::string& name) {
		return a.getName() < name;
		});
	if (it == studentList.end()) {
		std::cout << "Khong co hoc sinh trong lop\n";
	}
	else {
		int pos = it - studentList.begin();
		std::swap(studentList[pos], studentList[studentList.size() - 1]);
		studentList.pop_back();
		std::cout << "Da xoa hoc sinh thanh cong\n";
	}
}

void Classroom::sortScore() {
	std::sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
		return a.getAvgScore() > b.getAvgScore();
		});
}

void Classroom::printList() {
	for (int i = 0; i < studentList.size(); ++i) {
		studentList[i].xuat();
	}
}

void Classroom::readFile() {
	std::fstream myFile;
	myFile.open("LopHoc.txt", std::ios::in);

}
