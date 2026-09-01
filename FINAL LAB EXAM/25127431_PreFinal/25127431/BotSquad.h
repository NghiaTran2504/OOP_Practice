#pragma once
#include <vector>
#include "MechaEntity.h"
using namespace std;

class BattleBot;
class BotSquad : public MechaEntity {
private:
	vector <BattleBot*> members;
public:
	BotSquad() = default;
	BotSquad(int id = 0) : MechaEntity(id) {};
	~BotSquad() override = default; // Khong duoc delete members
	
	void addBot(BattleBot* b);
	void removeBot(BattleBot* b);
	
	const vector <BattleBot*>& getMembers() const{ return members; }

	void draw() override;
	void update() override;

	friend BotSquad operator+ (const BotSquad& squadA, const BotSquad& squadB);
};