#include "myArr.h"

std::istream& operator >> (std::istream& in, myArray& a) {
	int n; in >> n;
	if (a.size < a.capacity) a.arr[a.size++] = n;
	return in;
}

std::ostream& operator << (std::ostream & out, const myArray & a) {
	for (int i = 0; i < a.size; i++) {
		out << a.arr[i] << " ";
	}
	return out;
}

int myArray::operator[] (int index) {
	return arr[index];
}