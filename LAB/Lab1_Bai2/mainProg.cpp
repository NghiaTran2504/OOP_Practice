#include "Point2D.hpp"

int main() {
	Point a, b;
	std::cout << "Nhap toa do (x,y) cua hai diem: \n";
	std::cout << "Diem 1: "; a.nhap();
	std::cout << "Diem 2: "; b.nhap();

	std::cout << "\nToa do hai diem hien tai: \n";
	std::cout << "Diem A: ";
	a.in();
	std::cout << "\nDiem B: "; 
	b.in(); std::cout << "\n";

	distance(a, b);
	return 0;
}