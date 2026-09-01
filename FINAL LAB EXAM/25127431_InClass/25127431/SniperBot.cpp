#include "SniperBot.h"
#include "CyberModule.h"
#include <iostream>
using namespace std;

void SniperBot::draw() {
	cout << "[SniperBot] ID: " << id
		<< " | Armor: " << armor
		<< " | Energy: " << energy
		<< " | Combat rating: " << getCombatRating() << "\n";
}

void SniperBot::update() {
	
}