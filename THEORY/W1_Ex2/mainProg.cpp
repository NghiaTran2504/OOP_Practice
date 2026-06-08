#include "Complex.hpp"

int main() {
	Complex c1, c2;
	std::cout << "Nhap so thuc thu nhat: "; std::cin >> c1;
	std::cout << "Nhap so thuc thu hai : "; std::cin >> c2;
	std::cout << "Hai so thuc hien tai: "; std::cout << c1 << " va " << c2 << "\n";

	std::cout << "\nTong hai so thuc: " << c1 + c2 << "\n";
	std::cout << "Hieu hai so thuc: " << c1 - c2 << "\n";
	std::cout << "Tich hai so thuc: " << c1 * c2 << "\n";
	std::cout << "Thuong hai so thuc: " << c1 / c2 << "\n";
	std::cout << "Module so thuc thu nhat: " << c1.modulus() << "\n";
	std::cout << "Module so thuc thu hai: " << c2.modulus() << "\n";
	return 0;
}