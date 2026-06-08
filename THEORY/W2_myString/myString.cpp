#include "myString.hpp"

int strlen(unsigned char* c) {
	int dem = 0;
	while (c[dem] != '\0') {
		dem++;
	}
	return dem;
}

std::istream& operator >> (std::istream& in, myString& str) {
	char tmp[1000];
	in.getline(tmp, 1000);
	int dem = 0;
	while (tmp[dem] != '\0') {
		dem++;
	}
	str.SIZE = dem;
	str.S = new unsigned char[str.SIZE + 5];
	for (int i = 0; i < str.SIZE; ++i) {
		str.S[i] = tmp[i];
	}
	str.S[str.SIZE] = '\0';
	return in;
}

std::ostream& operator << (std::ostream& out, const myString& str) {
	out << str.S;
	return out;
}

myString& myString::operator + (const char* c) {
	int dem = strlen(c);

	int idx = 0;
	myString newString;
	newString.S = new unsigned char[this->SIZE + dem + 5];
	for (int i = 0; i < this->SIZE; ++i) {
		newString.S[idx++] = this->S[i];
	}

	for (int i = 0; i < dem; ++i) {
		newString.S[idx++] = c[i];
	}
	newString.S[idx] = '\0';
	newString.SIZE = idx;
	return newString;
}

unsigned char* myString::operator + (const myString& c) {
	unsigned char* newString = new unsigned char[this->SIZE + c.SIZE + 5];
	int idx = 0;
	for (int i = 0; i < this->SIZE; ++i) {
		newString[idx++] = this->S[i];
	}
	for (int i = 0; i < c.SIZE; ++i) {
		newString[idx++] = c.S[i];
	}

	newString[idx] = '\0';
	return newString;
}

unsigned char* myString::subString(int pos, int len) {
	unsigned char* newString = new unsigned char[len + 5];
	int idx = 0;
	for (int i = pos; i < pos + len; ++i) {
		newString[idx++] = this->S[i];
	}
	newString[idx] = '\0';
	return newString;
}

bool myString::insert(int pos, unsigned char* c) {
	if (pos < 0 || pos > this->SIZE) return false;
	int len_c = strlen(c);
	unsigned char* newString = new unsigned char[this->SIZE + len_c + 1];
	int idx = 0;

	for (int i = 0; i < pos; ++i) {
		newString[idx++] = this->S[i];
	}
	for (int i = 0; i < len_c; ++i) {
		newString[idx++] = c[i];
	}
	for (int i = pos; i < this->SIZE; ++i) {
		newString[idx++] = this->S[i];
	}
	newString[idx] = '\0';
	unsigned char* tmp = this->S;
	this->S = newString;
	this->SIZE = idx;
	delete[] tmp;
	tmp = NULL;
	return true;
}

bool myString::erase(int pos, int len){
	if (pos < 0 || pos >= this->SIZE || pos + len > this->SIZE) return false;
	unsigned char* newString = new unsigned char[this->SIZE + 1];
	int idx = 0;
	for (int i = 0; i < pos; ++i) {
		newString[idx++] = this->S[i];
	}
	for (int i = pos + len; i < this->SIZE; ++i) {
		newString[idx++] = this->S[i];
	}

	newString[idx] = '\0';
	unsigned char* tmp = this->S;
	this->S = newString;
	this->SIZE = idx;
	delete[] tmp;
	tmp = NULL;
	return true;
}

bool myString::replace(int pos, int len, unsigned char* c) {
	if (pos < 0 || pos >= this->SIZE || len < 0 || pos + len > this->SIZE) return false;
	int len_c = strlen(c);
	unsigned char* newString = new unsigned char[this->SIZE + len_c];
	int idx = 0;
	for (int i = 0; i < pos; ++i) {
		newString[idx++] = this->S[i];
	}
	for (int i = 0; i < len_c; ++i) {
		newString[idx++] = c[i];
	}
	for (int i = pos + len; i < this->SIZE; ++i) {
		newString[idx++] = this->S[i];
	}

	newString[idx] = '\0';
	unsigned char* tmp = this->S;
	this->S = newString;
	this->SIZE = idx;
	delete[] tmp;
	tmp = NULL;
	return true;
}

int myString::find(int pos, unsigned char* c) {
	int len_c = strlen(c);
	for (int i = pos; i <= this->SIZE - len_c; ++i) {
		if (this->S[i] == c[0]) {
			int count = 1;
			for (int j = 1; j < len_c; ++j) {
				if (this->S[i + j] == c[j])
					count++;
				else break;
			}
			if (count == len_c) return i;
		}
	}
	return -1;
}