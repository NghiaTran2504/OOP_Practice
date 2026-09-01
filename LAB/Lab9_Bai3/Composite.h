#pragma once

#include "Component.h"
#include <vector>

class DriveComposite : public DriveComponent {
protected:
	vector <DriveComponent*> compositeContent;
public:
	DriveComposite() = default;
	virtual ~DriveComposite();
	virtual DriveComponent* Clone() const= 0;

	DriveComposite(const DriveComposite& obj);
	DriveComposite& operator = (const DriveComposite& obj);

	string GetName() const override { return name; }
	double GetSize() const override;
	bool AddComponent(DriveComponent* obj) override;
	bool RemoveComponent(string name) override;

	void Nhap(istream& inDev) override {};
	void Xuat(ostream& outDev, int level = 0) const override {};


};