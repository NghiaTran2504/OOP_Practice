#pragma once
#include "CyberModule.h"

class OverClock : public CyberModule {
public:
	OverClock() = default;
	OverClock(int _id) : CyberModule(_id) {}
	~OverClock() override = default;

	CyberModule* clone() const override { return new OverClock(*this); }

	int getPowerBonus() const override { return 25; }
};