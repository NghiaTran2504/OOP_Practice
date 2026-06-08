#include "Point2D.hpp"

void Point::nhap() {
	std::cin >> x >> y;
}

void Point::in() {
	std::cout << "(" << x << ", " << y << ")";
}

void distance(Point& A, Point& B) {
	double dist = std::pow((A.x - B.x), 2) + std::pow((A.y - B.y), 2);
	dist = std::sqrt(dist);
	std::cout << "Khoang cach giua hai diem ";
	A.in(); 
	std::cout << " va "; B.in();
	std::cout << " la: " << dist << "\n";
}