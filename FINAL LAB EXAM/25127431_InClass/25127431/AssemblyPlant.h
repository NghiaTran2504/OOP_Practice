#pragma once
#include "MechaFacility.h"

class AssemblyPlant : public MechaFacility {
private:
	BattleBot* botPrototype = nullptr;
public:
	AssemblyPlant() = default;
	AssemblyPlant(int _id, int dura = 100) : MechaFacility(_id, dura) {}
	~AssemblyPlant(); // Khong duoc delete botPrototype

	void draw() override;
	void update() override;

	BattleBot* assembleBot() override;
	void setPrototype(BattleBot* proto); // thiet lap robot mau
};