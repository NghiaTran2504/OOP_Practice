#pragma once

#include <iostream>
using namespace std;

class Rectangle {
protected:
	double length = 0;
	double width = 0;
public:
	Rectangle() = default;
	virtual ~Rectangle() = default;

	Rectangle(double a, double b) {
		if (a < 0) a = 0;
		if (b < 0) b = 0;
		length = a;
		width = b;
	}

	double getLength() const { return length; }
	double getWidth() const { return width; }

	bool setLength(double p) {
		if (p < 0) {
			cout << "CHIEU DAI KHONG HOP LE\n";
			return false;
		}
		length = p;
		return true;
	}

	bool setWidth(double p) {
		if (p < 0 || p > length) {
			cout << "CHIEU RONG KHONG HOP LE\n";
			return false;
		}
		width = p;
		return true;
	}

	double getArea() const {
		return length * width;
	}

	double getPerimeter() const {
		return (length + width) * 2;
	}

	virtual void nhap(istream& inDev) {
		double temp;
		do {
			cout << "Nhap chieu dai: ";
			inDev >> temp;
		} while (!setLength(temp));

		do {
			cout << "Nhap chieu rong: ";
			inDev >> temp;
		} while (!setWidth(temp));
	}

	virtual void xuat(ostream& outDev) const {
		outDev << "Chieu dai: " << length << " | " << "Chieu rong: " << width << " | "
			   << "Chu vi: " << getPerimeter() << " | " << "Dien tich: " << getArea() << "\n";
	}

	friend istream& operator >> (istream& inDev, Rectangle& obj) {
		obj.nhap(inDev);
		return inDev;
	}

	friend ostream& operator << (ostream& outDev, const Rectangle& obj) {
		obj.xuat(outDev);
		return outDev;
	}
};