#include "Classroom.hpp"

// Cac phuong thuc cua Student
void Student::nhap() {
	while (1) {
		std::cout << "Nhap ho ten hoc sinh: "; getline(std::cin >> std::ws, this->fullName);
		if (!checkValidInfo("fullname")) {
			std::cout << "Ho ten hoc sinh khong hop le! Vui long nhap lai\n\n";
		}
		else break;
	}

	while (1) {
		std::cout << "Nhap so dien thoai (9 so - 11 so) : "; getline(std::cin >> std::ws, this->phoneNum);
		if (!checkValidInfo("phonenum")) {
			std::cout << "So dien thoai khong hop le! Vui long nhap lai\n\n";
		}
		else break;
	}

	while (1) {
		std::cout << "Nhap diem trung binh (0 diem - 10 diem): "; std::cin >> this->avgScore;
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
				if (c != ' ' && (c - 'a' >= 26 || c - 'a' < 0)) return false;
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



// *******************************************************

// Cac phuong thuc cua Classroom

void Classroom::addStudent() {
	Student hs;
	hs.nhap();
	auto it = std::lower_bound(this->studentList.begin(), this->studentList.end(), hs, [](auto& a, auto& b) {
		return a.getName() < b.getName();
		});
	
	//Hs da ton tai trong lop
	if (it != this->studentList.end() && (*it).getName() == hs.getName()) {
		std::cout << "Da co hoc sinh trong lop\n\n";
	}
	//Hs chua ton tai trong lop
	else {
		this->studentList.insert(it, hs);
		std::cout << "Da them hoc sinh thanh cong!\n\n";
	}
}

void Classroom::removeStudent() {
	std::string name;
	getline(std::cin >> std::ws, name);
	auto it = std::lower_bound(this->studentList.begin(), this->studentList.end(), name, [](auto& a, auto& b) {
		return a.getName() < b;
		});
	//Hs chua ton tai trong lop
	if (it == this->studentList.end() || (*it).getName() != name) {
		std::cout << "Khong co hoc sinh trong lop\n";
	}
	//Hs co ton tai trong lop
	else {
		this->studentList.erase(it);
		std::cout << "Da xoa hoc sinh thanh cong\n";
	}
}

void Classroom::sortScore() {
	std::sort(studentList.begin(), studentList.end(), [](const auto& a, const auto& b) {
		return a.getScore() > b.getScore();
		});
}

void Classroom::printList() {
	if (this->studentList.size() == 0) {
		std::cout << "Khong co hoc sinh nao trong lop!\n";
		return;
	}
	for (int i = 0; i < studentList.size(); ++i) {
		std::cout << "--------HOC SINH " << i + 1 << "-------\n";
		studentList[i].xuat();
		std::cout << '\n';
	}
}

void Classroom::readFile() {
	std::fstream fin;
	fin.open("LopHoc.txt", std::ios::in);
	if (fin) {
		int n;
		fin >> n;
		this->studentList.resize(n);
		for (int i = 0; i < n; ++i) {
			std::string name, phone;
			double score;
			fin >> std::ws;
			getline(fin, name);
			getline(fin, phone);
			fin >> score;
			this->studentList[i].setName(name);
			this->studentList[i].setPhone(phone);
			this->studentList[i].setScore(score);
		}

		fin.close();
	}
	else {
		std::cout << "ERROR!\n";
	}
}
