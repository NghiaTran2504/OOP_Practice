#include "Rectangle.hpp"

int main() {
	Rectangle hcn;
	hcn.inputRecInfo();
	if (hcn.isRectangle()) {
		std::cout << "4 dinh tren co the tao thanh mot hinh chu nhat\n";
		hcn.printRecInfo();
	}
	else {
		std::cout << "4 dinh tren khong tao thanh mot hinh chu nhat!\n";
	}
	return 0;

}