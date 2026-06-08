#include "Ps.hpp"


int main() {
	PhanSo ps1, ps2;
	while (1) {
		std::cout << "Nhap 2 phan so (4 so nguyen tuy y): ";
		std::cin >> ps1 >> ps2;
		if (ps1.getDenominator() == 0) {
			std::cout << "Phan so thu nhat khong hop le! Vui long thu lai. \n";
		}
		else if (ps2.getDenominator() == 0) {
			std::cout << "Phan so thu hai khong hop le! Vui long thu lai. \n";
		}
		else {
			break;
		}
	}
	std::cout << "Hai phan so hien tai: \n";
	std::cout << "Phan so 1: " << ps1 << '\n';
	std::cout << "Phan so 2: " << ps2 << "\n";

	std::cout << "Tong hai phan so: " << ps1 + ps2 << "\n";
	std::cout << "Hieu hai phan so: " << ps1 - ps2 << "\n";
	std::cout << "Tich hai phan so: " << ps1 * ps2 << "\n";
	std::cout << "Thuong hai phan so: " << ps1 / ps2 << "\n\n";

	int tmp;
	std::cout << "Sua tu so cua phan so 1: ";
	std::cin >> tmp;
	ps1.setNumerator(tmp);

	while (1) {
		std::cout << "Sua mau so cua phan so 1: ";
		std::cin >> tmp;
		if (tmp == 0) {
			std::cout << "Mau so khong hop le! Vui long thu lai\n";
		}
		else {
			ps1.setDenominator(tmp);
			break;
		}
	}

	std::cout << "\nSua tu so cua phan so 2: ";
	std::cin >> tmp;
	ps2.setNumerator(tmp);
	while (1) {
		std::cout << "Sua mau so cua phan so 2: ";
		std::cin >> tmp;
		if (tmp == 0) {
			std::cout << "Mau so khong hop le! Vui long thu lai\n";
		}
		else {
			ps2.setDenominator(tmp);
			break;
		}
	}

	std::cout << "\nHai phan so hien tai: \n";
	std::cout << "Phan so 1: " << ps1 << '\n';
	std::cout << "Phan so 2: " << ps2 << "\n";
	return 0;
}