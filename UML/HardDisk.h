#pragma once

#include "Composite.h"
using namespace std;

class HardDisk : public DriveComposite {
public:
	HardDisk() = default;
	DriveComponent* Clone() const override;

	void Nhap (istream& inDev) override;
	void Xuat (ostream & outDev, int level = 0) const override;
};