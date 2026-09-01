#pragma once

#include "MechaEntity.h"
#include <vector>
using namespace std;

class MechaLegion : public MechaEntity {
private:
	vector <MechaEntity*> legion;
public:
	MechaLegion() = default;
	MechaLegion(int _id) : MechaEntity(_id) {}
	~MechaLegion() override;

	void update() override;
	void draw() override;
	void addLegion(MechaEntity* e);
	int getCombatRating() const override;
};