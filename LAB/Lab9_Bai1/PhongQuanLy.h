#pragma once

#include "NhanSu.h"

class PhongQuanLy {
private:
	vector <NhanSu*> dsNhanSu;
public:
	PhongQuanLy() = default;
	PhongQuanLy(const PhongQuanLy& temp) = delete;
	PhongQuanLy& operator = (const PhongQuanLy&) = delete;

	~PhongQuanLy() {
		for (auto it : dsNhanSu) {
			delete it;
		}
		dsNhanSu.clear();
	}

	void AddNhanSu(string chucVu);
	bool DeleteNhanSu(string _id);

	void XuatDanhSach() const;
};