#pragma once

#include <iostream>
#include <string>

class Student {
private:
	std::string fullName, phoneNum;
	double avgScore;
public:
	void nhap();
	void xuat();
	bool checkValidInfo(const std::string& s);
};