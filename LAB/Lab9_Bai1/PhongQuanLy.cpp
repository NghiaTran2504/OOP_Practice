#include "PhongQuanLy.h"


void PhongQuanLy::AddNhanSu(string chucVu) {
	NhanSu* it = NhanSu::TaoDoiTuongTheoTen(chucVu);
	if (it == nullptr) {
		cout << "Chua co doi tuong mau de them vao danh sach nhan su.\n";
		return;
	}

	cin >> *it;
	dsNhanSu.push_back(it);
}

bool PhongQuanLy::DeleteNhanSu(string _id) {
	for (int i = 0; i < dsNhanSu.size(); ++i) {
		if (dsNhanSu[i]->getID() == _id) {
			NhanSu* res = dsNhanSu[i];
			dsNhanSu.erase(dsNhanSu.begin() + i);
			delete res;
			return true;
		}
	}
	return false;
}

void PhongQuanLy::XuatDanhSach() const {
	for (int i = 0; i < dsNhanSu.size(); ++i) {
		cout << "NHAN SU " << i + 1 << ": \n";
		cout << *dsNhanSu[i] << "\n";
	}
}