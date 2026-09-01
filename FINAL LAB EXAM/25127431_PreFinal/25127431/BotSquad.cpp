#include "BotSquad.h"
#include "BattleBot.h"
#include <iostream>

void BotSquad::addBot(BattleBot* b) {
	if (b) {
		members.push_back(b);
	}
}

void BotSquad::removeBot(BattleBot* b) {
	if (b) {
		for (int i = 0; i < members.size(); ++i) {
			if (members[i] == b) {
				members.erase(members.begin() + i);
				break;
			}
		}
	}
}

void BotSquad::draw() {
	cout << "\n==== SQUAD ID: " << id << " | Members: " << members.size() << " =====\n";
	for (auto& it : members) {
		it->draw();
	}
	cout << "====================\n";
}

void BotSquad::update() {
	for (auto& it : members) {
		it->update();
	}
}

BotSquad operator+ (const BotSquad& squadA, const BotSquad& squadB) {
	BotSquad bs(0);
	bs.members = squadA.members;
	bs.members.insert(bs.members.end(), squadB.members.begin(), squadB.members.end());

	return bs;
}