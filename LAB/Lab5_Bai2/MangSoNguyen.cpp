#include "MangSoNguyen.h"

using namespace std;

// ===== CONSTRUCTOR ===== //
MangSoNguyen::MangSoNguyen(int size) {
	this->size = size;
	data = new int[size] {};
}

MangSoNguyen::~MangSoNguyen() {
	size = 0;
	delete[] data;
	data = nullptr;
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& other) {
	this->size = other.size;
	this->data = new int[size] {};
	for (int i = 0; i < this->size; ++i) {
		this->data[i] = other.data[i];
	}
}
//----------------------------------------//
// ===== OPERATOR ===== //
MangSoNguyen& MangSoNguyen::operator= (const MangSoNguyen& array) {
	if (this == &array) {
		return *this;
	}
	this->size = array.size;
	delete[] this->data;
	this->data = new int[this->size] {};

	for (int i = 0; i < this->size; ++i) {
		this->data[i] = array.data[i];
	}
	return *this;
}

MangSoNguyen MangSoNguyen::operator + (const MangSoNguyen& array) const {
	MangSoNguyen ans;
	ans.size = max(this->size, array.size);
	ans.data = new int[ans.size] {};
	
	for (int i = 0; i < ans.size; ++i) {
		if (i >= this->size) {
			ans.data[i] = array.data[i];
		}
		else if (i >= array.size) {
			ans.data[i] = this->data[i];
		}
		else {
			ans.data[i] = this->data[i] + array.data[i];
		}
	}

	return ans;
}

MangSoNguyen& MangSoNguyen::operator ++ () {
	for (int i = 0; i < this->size; ++i) {
		this->data[i]++;
	}

	return* this;
}

MangSoNguyen& MangSoNguyen::operator -- () {
	for (int i = 0; i < this->size; ++i) {
		this->data[i]--;
	}
	return *this;
}

MangSoNguyen MangSoNguyen::operator ++ (int dummy) {
	MangSoNguyen tmp = *this;
	++*this;
	return tmp;
}

MangSoNguyen MangSoNguyen::operator -- (int dummy) {
	MangSoNguyen tmp = *this;
	--*this;
	return tmp;
}

istream& operator >> (istream& inDev, MangSoNguyen& array) {
	int newSize;

	while (1) {
		cout << "Nhap kich thuoc mang (lon hon 0): ";
		if (!(inDev >> newSize) || newSize <= 0) {
			cout << "\n --> Kich thuoc khong hop le! Vui long thu lai.\n\n";
			inDev.clear();
			inDev.ignore(10000, '\n');
		}
		else
			break;
	}

	int* tmp = new int[newSize];
	for (int i = 0; i < newSize; ++i) {
		while (true) {
			cout << "Nhap phan tu " << i + 1 << ": ";
			if (!(inDev >> tmp[i])) {
				cout << "\n --> Gia tri nhap vao phai la so nguyen! Vui long thu lai.\n\n";
				inDev.clear();
				inDev.ignore(10000, '\n');
			}
			else 
				break;
		}
	}

	delete[] array.data;
	array.data = tmp;
	array.size= newSize;
	return inDev;
}

ostream& operator << (ostream& outDev, const MangSoNguyen& array) {
	for (int i = 0; i < array.size; ++i) {
		outDev << array.data[i] << " ";
	}
	return outDev;
}
//----------------------------------------------------------//