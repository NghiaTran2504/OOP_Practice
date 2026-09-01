#pragma once
#include <vector>

using namespace std;

class MechaEntity;
class ArenaEngine {
private:
	static ArenaEngine* instance;
	vector<MechaEntity*> allEntities;
	ArenaEngine() = default;

public:
	ArenaEngine(const ArenaEngine& obj) = delete;
	ArenaEngine& operator = (const ArenaEngine& obj) = delete;
	~ArenaEngine() {}

	static ArenaEngine* getInstance();
	static void deleteInstance();

	void registerEntity(MechaEntity* e);
	void unregisterEntity(MechaEntity* e);
	void runSimulationCycle();
};