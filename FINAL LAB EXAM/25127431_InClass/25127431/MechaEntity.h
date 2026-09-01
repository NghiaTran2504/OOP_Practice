#pragma once

struct Position {
	float x, y;
	Position() { x = 0.0; y = 0.0; }
	Position(float _x, float _y) : x(_x), y(_y) {}
};

class MechaEntity {
protected:
	int id = 0;
	Position position;
public:
	MechaEntity() = default;
	MechaEntity(int _id) : id(_id) {};
	MechaEntity& operator = (const MechaEntity& obj) = default;
	virtual ~MechaEntity() {};

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual int getCombatRating() const { return 0; }
};