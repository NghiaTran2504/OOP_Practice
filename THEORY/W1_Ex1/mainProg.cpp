#include "Fraction.hpp"

int main() {
	Fraction a, b;
	std::cout << "Moi cau chu nhap hai phan so!\n";
	std::cin >> a >> b;
	a.resetDem();

	std::cout << "Hai phan so hien tai: " << a << " " << b << "\n";
	std::cout << "Tong hai phan so: " << a + b << "\n";
	std::cout << "Hieu hai phan so: " << a - b << "\n";

	std::cout << "Tich hai phan so: " << a * b << "\n";
	std::cout << "Thuong hai phan so: " << a / b << "\n";
	std::cout << "Nghich dao 2 phan so: " << a.inversion() << " " << b.inversion();
	std::cout << "\nNhap gia tri tu so " << a.getDem() << ":"; a.setNumerator();
	std::cout << "Nhap gia tri mau so " << a.getDem() << ":"; a.setDemominator();
	a.updateDem();

	std::cout << "Hai phan so hien tai: " << a << " " << b << "\n";
}