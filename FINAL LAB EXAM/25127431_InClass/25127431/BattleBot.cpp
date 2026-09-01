#include "BattleBot.h"
#include "Operator.h"
#include "CyberModule.h"

BattleBot::~BattleBot() {
	owner = nullptr;
	delete modun;
}

void BattleBot::move(Position newPos) {
	position = newPos;
}

void BattleBot::setOwner(Operator* op) {
	owner = op;
}

int BattleBot::getCombatRating() const {
	if (modun) return armor + energy + modun->getPowerBonus();
	return armor + energy;
}
void BattleBot::installModule(CyberModule* _m) {
	if (!_m) return;
	if (modun) {
		delete modun;
		modun = nullptr;
	}
	modun = _m;
}
