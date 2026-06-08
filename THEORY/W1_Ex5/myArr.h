#ifndef myArr_H
#define myArr_H

#include <iostream>
#include <algorithm>

class myArray {
private:
	int size, capacity;
	int* arr;
public:
	int getSize();
	void setArray(int cap);
	friend std::istream& operator >> (std::istream& in, myArray& a);
	friend std::ostream& operator << (std::ostream& out, const myArray& a);
	int operator [] (int index);
	bool validIndex(int index);
	void ascending();
	void descending();
	int find(int num);
};

#endif