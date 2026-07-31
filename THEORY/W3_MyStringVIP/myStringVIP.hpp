#pragma once

#include <iostream>


// Hardcore: Sử dụng memcpy và gom hết operator + thành 1 hàm cân tất
class MyStringVip {
private:
	unsigned char* string = nullptr;
	int len = 0;
public:
	MyStringVip(const char* c = "");
	MyStringVip(const MyStringVip&);
	~MyStringVip() {
		delete[] string;
	}

	friend std::istream& operator >> (std::istream& in, MyStringVip&);
	friend std::ostream& operator << (std::ostream& out, const MyStringVip&);
	MyStringVip& operator = (MyStringVip);
	bool operator < (const MyStringVip&) const;
	bool operator > (const MyStringVip&) const;
	bool operator <= (const MyStringVip&) const;
	bool operator >= (const MyStringVip&) const;
	bool operator == (const MyStringVip&) const;
	bool operator != (const MyStringVip&) const;

	bool set(int);
	bool set(char*);

	// Gom hết toàn bộ operator +:
	// literal string + MyStringVip
	// MyStringVip + MyStringVip
	// MyStringVip + literal string
	// char* + MyStringVip
	// MyStringVip + char*

	friend MyStringVip operator + (const MyStringVip&, const MyStringVip&);
	//========================
	//=== Lý do dùng được: Default constructor & IMPLICITY CONVERSION ===
	// Khi cho các kiểu trên cộng với nhau, nếu là MyStringVip thì nothing happens
	// Nếu 1 trong 2, hoặc cả 2 kiểu là literal string/char*
	// thì khi truyền vào hàm tương ứng hai tham chiếu, thì nó sẽ thực hiện IMPLICITY CONVERSION
	// biến kiểu literal string/char* thành MyStringVip để thực hiện phép cộng
};