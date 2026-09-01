#include "AssaultBot.h"
#include "CyberModule.h"
#include <iostream>
using namespace std;
void AssaultBot::update() {

}

void AssaultBot::draw() {
	cout << "[AssaultBot] ID: " << id
		<< " | Armor: " << armor
		<< " | Energy: " << energy
		<< " | Combat rating: " << getCombatRating() << "\n";
}
