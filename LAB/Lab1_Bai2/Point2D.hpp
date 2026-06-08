#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
#include <algorithm>

class Point {
private:
	double x, y;
public:
	void nhap();
	void in();
	friend void distance(Point& A, Point& B);
};

#endif 