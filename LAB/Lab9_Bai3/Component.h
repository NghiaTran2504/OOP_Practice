#pragma once

#include <string>
#include <iostream>

using namespace std;
class DriveComponent {
protected:
	string name;
	
public:
	DriveComponent() = default;
	virtual ~DriveComponent() = default;
	DriveComponent& operator = (const DriveComponent& obj) = default;
	virtual DriveComponent* Clone() const = 0;

	virtual string GetName() const = 0;
	virtual double GetSize() const = 0;
	virtual bool AddComponent(DriveComponent* obj) { return false; };
	virtual bool RemoveComponent(string name) { return false; };

	virtual void Nhap(istream& inDev) {};
	virtual void Xuat(ostream& outDev, int level = 0) const {};

	friend istream& operator >> (istream& inDev, DriveComponent& obj) {
		obj.Nhap(inDev);
		return inDev;
	}

	friend ostream& operator << (ostream& outDev, const DriveComponent& obj) {
		obj.Xuat(outDev, 0);
		return outDev;
	}
};