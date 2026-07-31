#include "myStringVIP.hpp"

// ==== Self built my_strlen (DAT TEN != std::strlen()) ====
int my_strlen(const char* c)
{
	int dem = 0;
	while (c[dem] != '\0') {
		dem++;
	}
	return dem;
}

MyStringVip::MyStringVip(const char* c) {
	int len_c = my_strlen(c);
	if (c == nullptr || len_c == 0) {
		string = nullptr;
		len = 0;
	}
	else {
		len = len_c;
		// LUU Y: DEEP COPY
		string = new unsigned char [len_c + 1];
		for (int i = 0; i < len_c; ++i)
			string[i] = c[i];
		string[len_c] = '\0';
	}
}

// ==== MEMCPY PRACTICE ==== 
MyStringVip::MyStringVip(const MyStringVip& other) {
	this->len = other.len;
	if (other.string != NULL) {
		this->string = new unsigned char[other.len + 1];
		std::memcpy(this->string, other.string, this->len + 1);
	}
	else
		this->string = NULL;
}
std::istream& operator >> (std::istream& in, MyStringVip& input) {
	char tmp[1000];
	in >> std::ws;
	in.getline(tmp, 1000);
	input.len = my_strlen(tmp);
	delete[] input.string;
	input.string = new unsigned char[input.len + 1];
	for (int i = 0; i < input.len; ++i) {
		input.string[i] = tmp[i];
	}
	input.string[input.len] = '\0';
	return in;
}

std::ostream& operator << (std::ostream& out, const MyStringVip& output) {
	if (output.string == NULL || output.len == 0)
		out << "";
	else out << output.string;
	return out;
}

//==== COPY & SWAP IDIOM ====
MyStringVip& MyStringVip::operator = (MyStringVip tmp) {
	std::swap(this->string, tmp.string);
	std::swap(this->len, tmp.len);
	return *this;
}
bool MyStringVip::operator < (const MyStringVip& tmp) const {
	int min_len = std::min(tmp.len, this->len);
	for (int i = 0; i < min_len; ++i) {
		if (this->string[i] == tmp.string[i]) continue;
		if (this->string[i] < tmp.string[i]) return true;
		else return false;
	}

	if (tmp.len == this->len || this->len != min_len) return false;
	return true;
}

bool MyStringVip::operator > (const MyStringVip& tmp) const {
	return !(*this < tmp || *this == tmp);
}

bool MyStringVip::operator == (const MyStringVip& tmp) const {
	if (this->len != tmp.len) return false;
	for (int i = 0; i < this->len; ++i) {
		if (this->string[i] != tmp.string[i]) return false;
	}
	return true;
}

bool MyStringVip::operator != (const MyStringVip& tmp) const {
	return !(*this == tmp);
}

bool MyStringVip::operator <= (const MyStringVip& tmp) const {
	return (*this < tmp || *this == tmp);
}

bool MyStringVip::operator >= (const MyStringVip& tmp) const {
	return (*this > tmp || *this == tmp);
}

bool MyStringVip::set(int _size) {
	if (_size < 0) return false;
	if (_size == 0) {
		this->len = 0;
		delete[] string;
		string = NULL;
	}

	else if (_size < this->len) {
		this->string[_size] = '\0';
		this->len = _size;
	}
	else {
		unsigned char* tmp = this->string;
		unsigned char* newString = new unsigned char[_size + 1];
		for (int i = 0; i < this->len; ++i) {
			newString[i] = this->string[i];
		}
		for (int i = this->len; i < _size; ++i) {
			newString[i] = 'Z';
		}
		newString[_size] = '\0';
		this->string = newString;
		this->len = _size;
		delete[] tmp;
		tmp = NULL;
	}

	return true;
}

bool MyStringVip::set(char* c) {
	MyStringVip newString(c);
	*this = newString;
	return true;
}

//=========================
//=== Normal operator + ===
//==========================

//MyStringVip MyStringVip::operator + (char* c) {
//	int len_c = my_strlen(c);
//	char* newString = new char[this->len + len_c + 1];
//	for (int i = 0; i < this->len; ++i) {
//		newString[i] = this->string[i];
//	}
//
//	for (int i = 0; i < len_c; ++i) {
//		newString[i + this->len] = c[i];
//	}
//	newString[this->len + len_c] = '\0';
//	MyStringVip result(newString);
//	delete[] newString;
//	return result;
//}
//
//MyStringVip MyStringVip::operator + (const char* c) {
//	int len_c = my_strlen(c);
//	char* newString = new char[this->len + len_c + 1];
//	for (int i = 0; i < this->len; ++i) {
//		newString[i] = this->string[i];
//	}
//	for (int i = 0; i < len_c; ++i) {
//		newString[i + this->len] = c[i];
//	}
//	newString[this->len + len_c] = '\0';
//	MyStringVip result(newString);
//	delete[] newString;
//	return result;
//}
//
//MyStringVip MyStringVip::operator + (const MyStringVip& tmp) {
//	char* newString = new char[this->len + tmp.len + 1];
//	for (int i = 0; i < this->len; ++i) {
//		newString[i] = this->string[i];
//	}
//
//	for (int i = 0; i < tmp.len; ++i) {
//		newString[this->len + i] = tmp.string[i];
//	}
//
//	newString[this->len + tmp.len] = '\0';
//	MyStringVip result(newString);
//	delete[] newString;
//	return result;
//}
//
//MyStringVip operator + (const char* c, const MyStringVip& tmp) {
//	int len_c = my_strlen(c);
//	char* newString = new char[len_c + tmp.len + 1];
//
//	// Memcpy practice
//	if (len_c > 0)
//		std::memcpy(newString, c, len_c);
//
//	// Memcpy practice
//	if (tmp.len > 0) {
//		std::memcpy(newString + len_c, tmp.string, tmp.len);
//	}
//
//	newString[len_c + tmp.len] = '\0';
//	MyStringVip result(newString);
//	delete[] newString;
//	return result;
//}

MyStringVip operator + (const MyStringVip& str1, const MyStringVip& str2) {
	MyStringVip result;
	result.len = str1.len + str2.len;

	if (result.len > 0) {
		// Cap phat 1 lan 
		result.string = new unsigned char[result.len + 1];

		if (str1.len > 0) {
			std::memcpy(result.string, str1.string, str1.len);
		}
		if (str2.len > 0) {
			std::memcpy(result.string + str1.len, str2.string, str2.len);
		}
		result.string[result.len] = '\0';
	}
	return result;
}