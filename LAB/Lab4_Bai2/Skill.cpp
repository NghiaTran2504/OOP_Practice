#include "Skill.h"

#include <iostream>

Skill::Skill(std::string skillName, unsigned int skillLevel)
	: skillName(skillName), skillLevel(skillLevel) {}


Skill::Skill(const Skill& other) {
	this->skillName = other.get_skillName();
	this->skillLevel = other.get_skillLevel();
}

void Skill::set_skillName(std::string newSkillName) {
	this->skillName = newSkillName;
}

bool Skill::set_skillLevel(int newSkillLevel) {
	if (newSkillLevel < 0) return false;
	this->skillLevel = newSkillLevel;
	return true;
}

std::istream& operator >> (std::istream& in, Skill& skill) {
	std::cout << "Nhap ten Skill: ";
	std::string name;
	std::getline(in >> std::ws, name);
	skill.set_skillName(name);

	std::cout << "Nhap Level cua Skill: ";
	int tmp;
	in >> tmp;
	while (!skill.set_skillLevel(tmp)) {
		std::cout << "\nSkill Level phai lon hon 0. Vui long nhap lai\n\n";
		std::cout << "Nhap Level cua Skill: ";
		in >> tmp;
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Skill& skill) {
	out << "SKILL: " << skill.get_skillName() << " - level " << skill.get_skillLevel();
	return out;
}