#pragma once

#include "BattleBot.h"

class AssaultBot : public BattleBot {
public:
	AssaultBot(int id = 0) : BattleBot(id){
		armor = 60;
		energy = 40;
	}
	~AssaultBot() = default;

	void update() override;
	void draw() override;

	BattleBot* clone() const override { return new AssaultBot(*this); }
};