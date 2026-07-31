#pragma once
#include "Figure.h"

class Rectangle : public Figure {
protected:
	double height = 0;
	double width = 0;
public:
	Rectangle() = default;
	~Rectangle() = default;
	Rectangle(double h, double w) : height(h), width(w) {}

	string getClass();

};