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
	std::string getName() const { return this->fullName; }
	std::string getPhone() const { return this->phoneNum; }
	double getScore() const { return this->avgScore; }

	void setName(const std::string& s) { this->fullName = s; }
	void setPhone(const std::string& s) { this->phoneNum = s; }
	void setScore(double score) { this->avgScore = score; }

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