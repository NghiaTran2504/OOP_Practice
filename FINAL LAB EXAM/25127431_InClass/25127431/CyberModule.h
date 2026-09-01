#pragma once
#include <string>
using namespace std;

class CyberModule {
protected:
	int id = 0;
	string name;
public:
	CyberModule() = default;
	CyberModule(int _id);
	virtual ~CyberModule() {}

	virtual CyberModule* clone() const = 0;
	int getId() const { return id; }
	string getName() const { return name; }
	virtual int getPowerBonus() const = 0; // chi so thuong
};