#include "NhanSu.h"

vector <NhanSu*> NhanSu::DoiTuongMau;

void NhanSu::ThemDoiTuongMau(NhanSu* ns) {
	if (ns == nullptr) return;

	for (NhanSu* it : DoiTuongMau) {
		if (it->LayTenDoiTuong() == ns->LayTenDoiTuong()) {
			return;
		}
	}

	DoiTuongMau.push_back(ns);
}

NhanSu* NhanSu::TaoDoiTuongTheoTen(string ten) {
	for (NhanSu* it : DoiTuongMau) {
		if (it->LayTenDoiTuong() == ten) {
			return it->Clone();
		}
	}
	return nullptr;
}

void NhanSu::XoaDoiTuongMau() {
	for (int i = 0; i < DoiTuongMau.size(); ++i) {
		delete DoiTuongMau[i];
	}
	DoiTuongMau.clear();
}

void NhanSu::Nhap(istream& inDev) {
	cout << "Nhap ten: ";
	getline(inDev >> ws, name);

	cout << "Nhap ngay sinh (dd/mm/yyyy): ";
	getline(inDev >> ws, dob);

	cout << "Nhap ma so nhan su: ";
	inDev >> id;
}

void NhanSu::Xuat(ostream& outDev) const {
	outDev << "Ten: " << name << " | Ngay sinh:" << dob << " | Ma nhan su:" << id << "\n";

}