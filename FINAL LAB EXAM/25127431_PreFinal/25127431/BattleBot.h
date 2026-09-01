#pragma once

#include "MechaEntity.h"

class Operator;
class BattleBot : public MechaEntity {
protected:
	int armor = 0;
	int energy = 0;
	Operator* owner = nullptr;
public:
	BattleBot() = default;
	BattleBot(int _id) : MechaEntity(_id) {};
	virtual ~BattleBot();

	virtual BattleBot* clone() const = 0;
	void move(Position newPos);
	void setOwner(Operator* op);
	int getCombatRating() const override;
};