#include "AssemblyPlant.h"
#include "Operator.h"
#include "BattleBot.h"
#include <iostream>
using namespace std;
AssemblyPlant::~AssemblyPlant() {
	botPrototype = nullptr;
}

void AssemblyPlant::draw() {
	cout << "[AssemblyPlant] ID: " << id
		<< " | Durability: " << durability
		<< " | Has Prototype: " << (botPrototype ? "YES" : "NO") << "\n";
}

void AssemblyPlant::update() {

}

BattleBot* AssemblyPlant::assembleBot() {
	if (botPrototype == nullptr || owner == nullptr || owner->consumePowerCores(500) == false ) {
		return nullptr;
	}
	return botPrototype->clone();
}

void AssemblyPlant::setPrototype(BattleBot* proto) {
	botPrototype = proto;
}