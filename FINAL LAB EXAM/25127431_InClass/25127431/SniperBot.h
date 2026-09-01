#pragma once

#include "BattleBot.h"

class SniperBot : public BattleBot {
public:
	SniperBot(int id = 0) : BattleBot(id) {
		armor = 30;
		energy = 50;
	}
	~SniperBot() override = default;

	void update() override;
	void draw() override;
	BattleBot* clone() const override { return new SniperBot(*this); }
};