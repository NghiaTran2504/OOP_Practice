#include "HardDisk.h"

DriveComponent* HardDisk::Clone() const {
	return new HardDisk(*this);
}
void HardDisk::Nhap(istream& inDev) {
	cout << "Nhap ten o dia: ";
	getline(inDev >> ws, name);
}

void HardDisk::Xuat(ostream& outDev, int level) const {
	for (int i = 0; i < level; ++i) cout << "\t";
	outDev << "[Disk]: " << name << " | Kich thuoc o dia: " << GetSize() << "B\n";
	outDev << "\n==== DANH SACH NOI DUNG BEN TRONG ====\n";
	
	for (auto& it : compositeContent) {
		if (it) {
			it->Xuat(outDev, level + 1);
		}
	}
}