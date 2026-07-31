#pragma once

#include <string>

class Skill
{
private:
	std::string skillName = "";
	unsigned int skillLevel = 0;

public:

	// ==== Constructor, Destructor ===== //
	Skill() = default;
	Skill(std::string skillName, unsigned int skillLevel);
	Skill(const Skill& other);
	~Skill() = default;

	// ===== Getter, Setter ===== //
	std::string get_skillName() const { return this->skillName; }
	unsigned int get_skillLevel() const { return this->skillLevel; }
	void set_skillName(std::string newSkillName);
	bool set_skillLevel(int newSkillLevel);

	// ==== Operator ==== //
	friend std::istream& operator >> (std::istream& in, Skill&);
	friend std::ostream& operator << (std::ostream& out, const Skill&);
};