#include "NhanSu.h"

int main() {
	vector <NhanSu*> listNhanSu;
	cin >> listNhanSu;
	cout << listNhanSu << "\n";

	cout << "==== NHAN SU CO LUONG CAO NHAT ====\n";
	cout << *NhanSu::getHighestSalary(listNhanSu) << "\n";
	NhanSu::clearMemory(listNhanSu);
}