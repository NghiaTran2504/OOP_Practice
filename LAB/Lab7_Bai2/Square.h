#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square() = default;
	Square(double a) : Rectangle(a, a) {}
	~Square() = default;

	bool setEdge(double a) {
		if (a < 0) {
			cout << "CANH KHONG KHONG HOP LE\n";
			return false;
		}
		length = width = a;
		return true;
	}
	void nhap(istream& inDev) override {
		double tmp;
		do {
			cout << "Nhap canh hinh vuong: ";
			inDev >> tmp;
		} while (!setEdge(tmp));
	}

	void xuat(ostream& outDev) const override {
		outDev << "Canh hinh vuong: " << length << " | " << "Chu vi: " << getPerimeter() << " | " << "Dien tich: " << getArea() << "\n";
	}
};