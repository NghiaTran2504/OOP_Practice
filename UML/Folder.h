#pragma once
#include "Composite.h"

class Folder : public DriveComposite {
public:
	Folder() = default;
	DriveComponent* Clone() const override;

	
	void Nhap (istream& inDev) override;
	void Xuat(ostream& outDev, int level = 0) const override;
};