#pragma once

#include "Component.h"
#include <iostream>
using namespace std;

class File : public DriveComponent{
private: 
	double size = 0;
public:
	File() = default;
	~File() = default;

	DriveComponent* Clone() const override {
		return new File(*this);
	}

	string GetName() const override { return name; }
	double GetSize() const override { return size; }

	void Nhap(istream& inDev) override {
		cout << "Nhap ten file: ";
		getline(inDev >> ws, name);
		cout << "Nhap kich thuoc file: ";
		inDev >> size;
	}

	void Xuat(ostream& outDev, int level = 0) const override {
		for (int i = 0; i < level; ++i) outDev << "\t";
		outDev << "[File] " << name << " | Kich thuoc: " << size << "B\n";
	}
};