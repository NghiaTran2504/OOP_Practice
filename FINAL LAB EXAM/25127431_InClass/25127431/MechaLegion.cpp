#include "MechaLegion.h"

MechaLegion::~MechaLegion() {
	legion.clear();
}

void MechaLegion::update() {
	for (auto& it : legion) {
		it->update();
	}
}

void MechaLegion::draw() {
	for (auto& it : legion) {
		it->draw();
	}
}

int MechaLegion::getCombatRating() const {
	long long totalCombatRating = 0;
	for (auto& it : legion) {
		totalCombatRating += it->getCombatRating();
	}
	return totalCombatRating;
}

void MechaLegion::addLegion(MechaEntity* e) {
	if (this == e) return;
	if (e) {
		legion.push_back(e);
	}
}