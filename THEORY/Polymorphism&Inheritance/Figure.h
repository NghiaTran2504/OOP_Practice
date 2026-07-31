#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Figure {
private:
	static vector <Figure*> toolbar;
protected:
	static Figure* add(Figure*);
public:
	static Figure* createObj(string nameObj);
	static const vector <Figure*>& getSampleList() { return toolbar; }
	virtual string getClass() = 0;
	virtual Figure* Clone() = 0;
	virtual double Area(double x, double y) = 0;

	virtual ~Figure();
};