#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BattleBot;
class MechaFacility;

class Operator {
private:
	string name;
	int powerCores = 0;
	vector <BattleBot*> bots;
	vector <MechaFacility*> facilities;
public:
	Operator() = default;
	Operator(string _name, int _power) : name(_name), powerCores(_power) {};
	~Operator();
	Operator(const Operator&) = delete;
	Operator& operator=(const Operator&) = delete;

	void addBot(BattleBot* b);
	void addFacility(MechaFacility* f);

	const vector<BattleBot*>& getBots() const { return bots; }
	const vector<MechaFacility*>& getFacilities() const { return facilities; }
	int getPowerCores() const { return powerCores; }

	bool consumePowerCores(int amount);
	BattleBot* releaseBot(BattleBot* b);

	friend ostream& operator << (ostream& outDev, const Operator&);

};