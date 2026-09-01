#pragma once
#include "CyberModule.h"

class EnergyShield : public CyberModule {
public:
	EnergyShield() = default;
	EnergyShield(int _id) : CyberModule(_id) {}
	~EnergyShield() override = default;

	CyberModule* clone() const override { return new EnergyShield(*this); }

	int getPowerBonus() const override { return 40; }
};