#pragma once

#include <iostream>

class MangSoNguyen {
private:
	int* data = nullptr;
	int size = 0;

public:
	// ===== CONSTRUCTOR ===== //
	MangSoNguyen() = default;
	MangSoNguyen(int size);
	MangSoNguyen(const MangSoNguyen& other);
	~MangSoNguyen();

	// ===== OPERATOR ===== //
	MangSoNguyen& operator = (const MangSoNguyen& array);
	MangSoNguyen operator + (const MangSoNguyen& array) const;
	MangSoNguyen& operator ++ ();
	MangSoNguyen& operator -- ();
	MangSoNguyen operator ++ (int);
	MangSoNguyen operator -- (int);

	friend std::istream& operator >> (std::istream& inDev, MangSoNguyen&);
	friend std::ostream& operator << (std::ostream& outDev, const MangSoNguyen&);
};