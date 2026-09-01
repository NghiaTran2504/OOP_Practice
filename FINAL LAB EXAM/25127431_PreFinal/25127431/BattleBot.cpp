#include "BattleBot.h"
#include "Operator.h"

BattleBot::~BattleBot() {
	owner = nullptr;
}

void BattleBot::move(Position newPos) {
	position = newPos;
}

void BattleBot::setOwner(Operator* op) {
	owner = op;
}

int BattleBot::getCombatRating() const {
	return armor + energy;
}
