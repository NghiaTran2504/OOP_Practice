#include "Operator.h"
#include "BattleBot.h"
#include "MechaFacility.h"

Operator::~Operator() {
	for (auto& it : bots) {
		delete it;
	}

	for (auto& it : facilities) {
		delete it;
	}
}

void Operator::addBot(BattleBot* b) {
	if (!b) return;
	bots.push_back(b);
	b->setOwner(this);
}

void Operator::addFacility(MechaFacility* f) {
	if (!f) return;
	facilities.push_back(f);
	f->setOwner(this);
}

bool Operator::consumePowerCores(int amount) {
	if (amount > powerCores) return false;
	powerCores -= amount;
	return true;
}

BattleBot* Operator::releaseBot(BattleBot* b) {
	for (int i = 0; i < bots.size(); ++i) {
		if (bots[i] == b) {
			bots.erase(bots.begin() + i);
			break;
		}
	}
	b->setOwner(nullptr);
	return b;
}

ostream& operator << (ostream& outDev, const Operator& op) {
	outDev << "[OPERATOR]: " << op.name << "\n";
	outDev << "Power cores: " << op.powerCores << "\n";
	outDev << "Num robots: " << op.bots.size() << "\n";
	outDev << "Num facilities: " << op.facilities.size() << "\n";
	outDev << "==============\n";
	return outDev;
}