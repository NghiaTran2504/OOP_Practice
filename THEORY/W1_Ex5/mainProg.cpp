#include "myArr.h"

int main() {
	myArray a;
	std::cout << "Nhap so luong phan tu cua mang: ";
	int n; std::cin >> n;
	a.setArray(n);
	std::cout << "Nhap cac gia tri cua mang (" << n << " phan tu): ";
	for (int i = 0; i < n; ++i) std::cin >> a;

	std::cout << "Mang hien tai: " << a << "\n";
	std::cout << "Size cua mang hien tai: " << a.getSize() << "\n";
	std::cout << "Nhap gia tri muon tim kiem: ";
	int num; std::cin >> num;	
	if (a.find(num) != -1) {
		std::cout << "Tim thay gia tri o vi tri: " << a.find(num) << "\n";
	}
	else {
		std::cout << "Khong tim thay gia tri trong mang!\n";
	}

	int index;
	while (1) {
		std::cout << "Nhap vi tri muon truy cap (vi tri: 0 - " << a.getSize() << "): ";
		std::cin >> index;
		if (a.validIndex(index)) {
			std::cout << "Gia tri truy cap: " << a[index] << "\n";
			break;
		}
		else {
			std::cout << "Vi tri truy cap khong hop le! Hay thu lai. \n";
		}
	}

	a.ascending();
	std::cout << "Mang sap xep tang dan: " << a << "\n";
	a.descending();
	std::cout << "Mang sap xep giam dan: " << a << "\n";
	return 0;
}