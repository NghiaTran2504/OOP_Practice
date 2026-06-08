#include "Rectangle.hpp"

std::istream& operator >> (std::istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

std::ostream& operator << (std::ostream& out, const Point & p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

double distance(const Point& p1, const Point& p2) {
	double dist = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
	return dist;
}

bool Rectangle::isRectangle() {
	double dist1 = distance(p1, p2);
	double dist2 = distance(p2, p3);
	double dist3 = distance(p3, p4);
	double dist4 = distance(p4, p1);
	double diagonal = distance(p1, p3);

	if (dist1 == dist3 && dist2 == dist4 && dist1 + dist2 == diagonal) {
		if (dist1 >= dist2) {
			length = std::sqrt(dist1);
			width = std::sqrt(dist2);
		}
		else {
			length = std::sqrt(dist2);
			width = std::sqrt(dist1);
		}
		perimeter = (length + width) * 2;
		area = length * width;

		return true;
	}
	return false;
}


void Rectangle::printRecInfo() {
	std::cout << "\nTHONG TIN HINH CHU NHAT\n";
	std::cout << "Toa do 4 dinh hinh chu nhat\n";
	std::cout << "Dinh 1: " << p1;
	std::cout << "\nDinh 2: " << p2;
	std::cout << "\nDinh 3: " << p3;
	std::cout << "\nDinh 4: " << p4;
	std::cout << "\n\nChieu dai: " << length;
	std::cout << "\nChieu rong: " << width;
	std::cout << "\nChu vi HCN: " << perimeter;
	std::cout << "\nDien tich HCN: " << area;
}

void Rectangle::inputRecInfo() {
	std::cout << "Nhap toa do (x,y) cua 4 dinh: \n";
	std::cout << "Dinh 1: "; std::cin >> p1;
	std::cout << "Dinh 2: "; std::cin >> p2;
	std::cout << "Dinh 3: "; std::cin >> p3;
	std::cout << "Dinh 4: "; std::cin >> p4;
}