#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Student {
private:
	std::string fullName, phoneNum;
	double avgScore;
public:
	std::string getName();
	double getAvgScore();
	void nhap();
	void xuat();
	bool checkValidInfo(const std::string& s);
};

class Classroom {
private:
	std::vector <Student> studentList;
public:
	void addStudent();
	void removeStudent();
	void sortScore();
	void printList();
	void readFile();
};