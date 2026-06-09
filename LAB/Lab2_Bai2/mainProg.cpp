#include "Classroom.hpp"

int main() {
	Classroom LopHoc;
	int n;
	std::cout << "1. Nhap so luong hoc sinh: "; 
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		LopHoc.addStudent();
	}

	std::cout << "###DANH SACH HOC SINH HIEN TAI:\n";
	LopHoc.printList();

	std::cout << "\n2. Nhap ten hoc sinh muon xoa: ";
	LopHoc.removeStudent();
	std::cout << "\n###DANH SACH HOC SINH SAU KHI XOA\n";
	LopHoc.printList();

	std::cout << "\n3. Sap xep danh sach hoc sinh theo diem: \n";
	LopHoc.sortScore();
	LopHoc.printList(); 

	std::cout << "\n4. DOC FILE: \n";
	LopHoc.readFile();
	LopHoc.printList();
	return 0;
}