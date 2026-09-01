#include <iostream>
#include "ArenaEngine.h"
#include "Operator.h"
#include "AssaultBot.h"
#include "SniperBot.h"
#include "AssemblyPlant.h"
#include "BotSquad.h"
using namespace std;
int main() {
	// --- 1. Khoi tao ArenaEngine (kiem tra Singleton) ---
	cout << "--- Initializing Arena Engine ---\n";
	ArenaEngine* engine = ArenaEngine::getInstance();
	ArenaEngine* another = ArenaEngine::getInstance();
	cout << "Same instance: " << (engine == another ? "YES" : "NO") << "\n\n";

	// --- 2. Tao ky su va cac nguyen mau robot (kiem tra Prototype) ---
	cout << "--- Setting up Operator and Prototypes ---\n";
	Operator op1("Master Chief", 8000);
	AssaultBot assaultPrototype(900);
	SniperBot sniperPrototype(901);
	cout << op1 << "\n\n";

	// --- 3. Ky su xay nha may (Composition) ---
	cout << "--- Operator builds an Assembly Plant ---\n";
	AssemblyPlant* plant = new AssemblyPlant(10);
	plant->setPrototype(&assaultPrototype); // Aggregation: KHONG delete proto
	op1.addFacility(plant); // Composition: op1 so huu plant

	//--- 4. Nha may san xuat robot (Prototype + chi phi nang luong) ---
	cout << "\n--- Assembly Plant produces Battle Bots ---\n";
	BattleBot* bot1 = plant->assembleBot();
	BattleBot* bot2 = plant->assembleBot();
	if (bot1 && bot2) { op1.addBot(bot1); op1.addBot(bot2); }
	cout << "Power cores left: " << op1.getPowerCores() << "\n";

	// --- 5. Tap hop tieu doi (Aggregation) ---
	cout << "\n--- Organizing a Bot Squad ---\n";
	BotSquad squad1(1);
	squad1.addBot(op1.getBots()[0]);
	squad1.addBot(op1.getBots()[1]);

	// --- 6. Da hinh qua bo dieu khien trung tam ---
	engine->registerEntity(&squad1); // ArenaEngine chi quan sat
	engine->registerEntity(plant);
	cout << "\n--- Simulation cycle (polymorphism) ---\n";
	engine->runSimulationCycle(); // update() + draw() da hinh

	// --- 7. Kiem tra nap chong toan tu ---
	cout << "\n--- Testing Operator Overloading ---\n";
	cout << op1 << "\n";
	plant->setPrototype(&sniperPrototype);
	BattleBot* bot3 = plant->assembleBot();	
	op1.addBot(bot3);
	BotSquad squad2(2);
	squad2.addBot(bot3);
	BotSquad combined = squad1 + squad2;
	cout << "Combined squad:\n";
	combined.draw();

	// --- 8. Ket thuc: ~Operator() giai phong bots va facilities ---
	engine->unregisterEntity(&squad1);
	engine->unregisterEntity(plant);
	cout << "\n--- Exiting main(), Operator destructor will be called. ---\n";

	ArenaEngine::deleteInstance();
	return 0;
}