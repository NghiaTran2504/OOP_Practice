#include "ArenaEngine.h"
#include "MechaEntity.h"
#include <iostream>

ArenaEngine* ArenaEngine::instance = nullptr;

ArenaEngine* ArenaEngine::getInstance() {
	if (instance == nullptr) {
		instance = new ArenaEngine;
	}
	return instance;
}

void ArenaEngine::deleteInstance() {
	if (instance == nullptr) return;
	delete instance;
	instance = nullptr;
}

void ArenaEngine::registerEntity(MechaEntity* e) {
	if (e) {
		allEntities.push_back(e);
	}
}

void ArenaEngine::unregisterEntity(MechaEntity* e) {
	for (int i = 0; i < allEntities.size(); ++i) { 
		if (allEntities[i] == e) {
			allEntities.erase(allEntities.begin() + i);
			break;
		}
	}
}

void ArenaEngine::runSimulationCycle() {
	for (auto* entity : allEntities) {
		if (entity) {
			entity->update();
			entity->draw();
		}
	}
}
