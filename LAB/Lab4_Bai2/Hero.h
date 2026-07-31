#pragma once

#include <string>
#include <vector>

class Skill;

class Hero
{
private:
	std::string heroName = "";
	unsigned int heroHealth = 0;
	unsigned int heroMana = 0;
	unsigned int heroLevel = 0;
	std::vector <Skill*> skillList;

public:
	// ==== Constructor - Destructor ===== //
	Hero() = default;
	Hero(std::string heroName, unsigned int heroHealth, unsigned int heroMana, unsigned int heroLevel, std::vector <Skill*>& skillList);
	Hero(const Hero& other);
	Hero& operator = (const Hero&);
	~Hero();

	// ==== Getter, Setter ===== //
	std::string get_heroName() const { return this->heroName; }
	unsigned int get_heroHealth() const { return this->heroHealth; }
	unsigned int get_heroMana() const { return this->heroMana; }
	unsigned int get_heroLevel() const { return this->heroLevel; }
	std::vector <Skill*> get_skillList() const { return this->skillList; }

	void set_heroName(std::string name);
	bool set_heroHealth(int health);
	bool set_heroMana(int mana);
	bool set_heroLevel(int level);

	// ==== Helper Function ==== //
	void assignSkillList(std::vector<Skill*>& dest, const std::vector<Skill*>& src);

	// ==== Operator ==== //
	friend std::istream& operator >> (std::istream& in, Hero&);
	friend std::ostream& operator << (std::ostream& out, const Hero&);

	std::vector <Skill*> skillCanLearn() const ;	// Skill can learn based on hero level
	void deleteSkills(int n);	// Delete n skills
	void printSkillList() const;
};