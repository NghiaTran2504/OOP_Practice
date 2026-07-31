#include "Fraction.hpp"

int main()
{
	Fraction ps1, ps2;
	
	while (1) {
		std::cout << "Nhap phan so 1 (dang a/b hoac a b): ";
		if (std::cin >> ps1) {
			if (ps1.getMau() != 0) {
				break;
			}
		}
	}
	
	while (1) {
		std::cout << "Nhap phan so 2 (dang a/b hoac a b): ";
		if (std::cin >> ps2) {
			if (ps2.getMau() != 0)
				break;
		}
	}
	
	std::cout << std::endl;
	std::cout << "Tong hai phan so: " << ps1 + ps2 << "\n";
	std::cout << "Hieu hai phan so: " << ps1 - ps2 << "\n";
	std::cout << "Tich hai phan so: " << ps1 * ps2 << "\n";
	std::cout << "Thuong hai phan so: " << ps1 / ps2 << "\n";

	std::cout << "\nPhan so 1: " << ps1 << "\nPhan so 2: " << ps2 << "\n";
	return 0;
}