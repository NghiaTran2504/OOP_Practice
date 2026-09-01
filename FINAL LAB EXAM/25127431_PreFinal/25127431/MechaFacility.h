#pragma once

#include "MechaEntity.h"

class Operator;
class BattleBot;
class MechaFacility : public MechaEntity {
protected:
	int durability = 100;
	Operator* owner = nullptr;

public:
	MechaFacility() = default;
	MechaFacility(int id = 0, int dura = 100) : MechaEntity(id), durability(dura) {};
	virtual ~MechaFacility();

	void setOwner(Operator* op);
	virtual BattleBot* assembleBot() = 0; // che tao, lap rap robot
};