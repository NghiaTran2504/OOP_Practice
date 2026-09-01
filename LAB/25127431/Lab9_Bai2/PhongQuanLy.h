#pragma once

#include "NhanSu.h"

class PhongQuanLy {
private:
	static PhongQuanLy* instance;
	vector <NhanSu*> dsNhanSu;

	PhongQuanLy() = default;
public:
	PhongQuanLy(const PhongQuanLy& temp) = delete;
	PhongQuanLy& operator = (const PhongQuanLy&) = delete;

	~PhongQuanLy() {
		for (auto it : dsNhanSu) {
			delete it;
		}
		dsNhanSu.clear();
	}

	static PhongQuanLy* GetInstance() {
		if (instance == nullptr) {
			instance = new PhongQuanLy();
		}
		return instance;
	}

	static void DeleteInstance() {
		if (instance == nullptr) return;
		delete instance;
		instance = nullptr;
	}

	void AddNhanSu(string chucVu);
	bool DeleteNhanSu(string _id);

	void XuatDanhSach() const;
};