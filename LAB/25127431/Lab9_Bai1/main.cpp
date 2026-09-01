#include "NhanSu.h"
#include "GiangVien.h"
#include "TroGiang.h"
#include "NghienCuuVien.h"
#include "ThucTapSinh.h"
#include "ChuyenVien.h"
#include "PhongQuanLy.h"

int main() {
	NhanSu::ThemDoiTuongMau(new GiangVien());
	NhanSu::ThemDoiTuongMau(new TroGiang());
	NhanSu::ThemDoiTuongMau(new NghienCuuVien());
	NhanSu::ThemDoiTuongMau(new ChuyenVien());
	NhanSu::ThemDoiTuongMau(new ThucTapSinh());

	PhongQuanLy GiaoVu;

	while (1) {
		int n;
		cout << "\n[1]. Them nhan su: \n";
		cout << "[2]. Xoa bot nhan su: \n";
		cout << "[3]. Xuat thong tin toan bo nhan su: \n";
		cout << "[4]. QUIT: \n\n";

		cout << "Nhap lenh: "; cin >> n;
		switch (n) {
		case 1: {
			string s;
			cout << "Nhap chuc vu (GiangVien, TroGiang, ChuyenVien, NghienCuuVien, ThucTapSinh): ";
			getline(cin >> ws, s);
			GiaoVu.AddNhanSu(s);
			break;
		}
		case 2: {
			string s;
			cout << "Nhap ma so nhan su: ";
			getline(cin >> ws, s);
			if (!GiaoVu.DeleteNhanSu(s)) {
				cout << "Khong tim thay ma so nhan su.\n";
			}
			else {
				cout << "Da xoa thanh cong.\n";
			}
			break;
		}
		case 3: {
			cout << "\n ==== THONG TIN TOAN BO NHAN SU ===== \n";
			GiaoVu.XuatDanhSach();
			break;
		}
		case 4: {
			
			NhanSu::XoaDoiTuongMau();
			return 0;
		}
		}
	}
	return 0;
}