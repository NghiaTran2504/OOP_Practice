#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <algorithm>

class Point {
private:
	double x, y;
public:
	friend double distance(const Point& p1, const Point& p2);	
	friend std::istream& operator >> (std::istream& in, Point& p);
	friend std::ostream& operator << (std::ostream& out, const Point& p);	
};

class Rectangle {
private:
	Point p1, p2, p3, p4;
	double length;
	double width;
	double area;
	double perimeter;
public:
	bool isRectangle();
	void inputRecInfo();
	void printRecInfo();
};
#endif