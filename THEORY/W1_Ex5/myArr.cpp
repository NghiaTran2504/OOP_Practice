#include "myArr.h"

int myArray::getSize() {
	return this->size;
}

void myArray::ascending() {
	std::sort(this->arr, this->arr + this->size);
}

void myArray::descending() {
	std::sort(this->arr, this->arr + this->size, std::greater<int>());
}

void myArray::setArray(int cap) {
	this->capacity = cap;
	this->size = 0;
	arr = new int[cap];
	for (int i = 0; i < cap; ++i) {
		arr[i] = 0;
	}
}

int myArray::find(int num) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == num) {
			return i;
		}
	}
	return -1;
}

bool myArray::validIndex(int index) {
	return (index < size && index >= 0);
}