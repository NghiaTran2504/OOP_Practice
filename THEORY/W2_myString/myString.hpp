#pragma once
#include <iostream>

class myString {
private:
	unsigned char* S;
	int SIZE;
public:
	int length() {
		return this->SIZE;
	}
	unsigned char* subString(int, int);
	unsigned char* operator + (const myString&);
	myString& operator + (const char*);
	friend std::istream& operator >> (std::istream& in, myString&);
	friend std::ostream& operator << (std::ostream& out, const myString&);
	bool insert(int, unsigned char*);
	bool erase(int, int);
	bool replace(int, int, unsigned char*);
	int find(int, unsigned char*);
};