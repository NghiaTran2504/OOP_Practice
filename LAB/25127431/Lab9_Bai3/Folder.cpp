#include "Folder.h"
#include <iostream>

DriveComponent* Folder::Clone() const{
	return new Folder(*this);
}

void Folder::Nhap(istream& inDev) {
	cout << "Nhap ten folder: ";
	getline(inDev >> ws, name);
}

void Folder::Xuat(ostream& outDev, int level) const {
	for (int i = 0; i < level; ++i) cout << "\t";
	outDev << "[Folder]: " << name << " |  Kich thuoc folder: " << GetSize() << "B\n";
	for (auto& it : compositeContent) {
		if (it) {
			it->Xuat(outDev, level + 1);
		}
	}
}