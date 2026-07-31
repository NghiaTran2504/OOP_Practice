#include "Hero.h"
#include "Skill.h"

#include <iostream>

// ==== Constructor, Destructor ==== // 
Hero::Hero(std::string heroName, unsigned int heroHealth, unsigned int heroMana, unsigned int heroLevel, std::vector <Skill*>& skillList)
	: heroName(heroName), heroHealth (heroHealth), heroMana (heroMana), heroLevel(heroLevel) {
	
	assignSkillList(this->skillList, skillList);
}

Hero::Hero(const Hero& other) {
	this->heroName = other.get_heroName();
	this->heroHealth = other.get_heroHealth();
	this->heroMana = other.get_heroMana();
	this->heroLevel = other.get_heroLevel();
	assignSkillList(this->skillList, other.skillList);
}

Hero& Hero::operator= (const Hero& other) {
	this->heroName = other.get_heroName();
	this->heroHealth = other.get_heroHealth();
	this->heroMana = other.get_heroMana();
	this->heroLevel = other.get_heroLevel();
	assignSkillList(this->skillList, other.skillList);

	return *this;
}

Hero::~Hero() {
	for (auto x : this->skillList) {
		delete x;
		x = nullptr;
	}
	skillList.clear();
}

// ==== Getter, Setter ==== //
void Hero::set_heroName(std::string name) {
	this->heroName = name;
}

bool Hero::set_heroHealth(int health) {
	if (health < 0) return false;
	this->heroHealth = health;
	return true;
}

bool Hero::set_heroMana(int mana) {
	if (mana < 0) return false;
	this->heroMana = mana;
	return true;
}

bool Hero::set_heroLevel(int level) {
	if (level < 0) return false;
	this->heroLevel = level;
	return true;
}

// ==== Helper fucntion ==== //
void Hero::assignSkillList(std::vector<Skill*>& dest, const std::vector<Skill*>& src) {
	for (auto x : dest) {
		delete x;
		x = nullptr;
	}
	dest.clear();

	for (auto x : src) {
		if (x != nullptr) {
			dest.push_back(new Skill(*x));
		}
	}
}

// ==== Operator ==== //
std::istream& operator >> (std::istream& in, Hero& hero) {
	std::cout << "Nhap ten tuong: ";
	std::string name;
	if (std::getline(in >> std::ws, name)) {
		hero.set_heroName(name);
	}

	std::cout << "Nhap chi so mau: ";
	int health;
	if (in >> health) {
		while (!hero.set_heroHealth(health)) {
			std::cout << "\nLuong mau cua tuong phai >= 0. Vui long thu lai \n\n";
			std::cout << "Nhap chi so mau: ";
			in >> health;
		}
	}

	std::cout << "Nhap chi so nang luong: ";
	int mana;
	if (in >> mana) {
		while (!hero.set_heroMana(mana)) {
			std::cout << "\nNang luong cua tuong phai >= 0. Vui long thu lai \n\n";
			std::cout << "Nhap chi so nang luong: ";
			in >> mana;
		}
	}
	std::cout << "Nhap cap do cua tuong: ";
	int level;
	if (in >> level) {
		while (!hero.set_heroLevel(level)) {
			std::cout << "\nCap do cua tuong phai >= 0. Vui long thu lai \n\n";
			std::cout << "Nhap cap do cua tuong: ";
			in >> level;
		}
	}

	std::cout << "\nNhap so luong skill cua tuong: ";
	int skillNum = 0;
	if (in >> skillNum) {
		while (skillNum < 0) {
			std::cout << "\nSo luong skill phai >= 0. Vui long thu lai\n\n";
			std::cout << "Nhap so luong skill cua tuong: ";
			in >> skillNum;
		}

		for (int i = 0; i < skillNum; ++i) {
			Skill* skill = new Skill;
			in >> *skill;
			hero.skillList.push_back(skill);
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Hero& hero) {
	out << "\n==== THONG TIN CUA TUONG ====\n";
	out << "1. TEN TUONG: " << hero.get_heroName() << "\n";
	out << "2. CHI SO MAU: " << hero.get_heroHealth() << "\n";
	out << "3. CHI SO NANG LUONG: " << hero.get_heroMana() << "\n";
	out << "4. LEVEL: " << hero.get_heroLevel() << "\n";
	
	out << "\n====== DANH SACH KY NANG CAN CO ======\n";
	for (int i = 0; i < hero.skillList.size(); ++i) {
		out << *hero.skillList[i] << "\n";
	}

	std::vector <Skill*> presentSkill = hero.skillCanLearn();
	out << "\n====== DANH SACH KY NANG CO THE SU DUNG ====== \n";
	for (int i = 0; i < presentSkill.size(); ++i) {
		out << *presentSkill[i] << "\n";
	}
	return out;
}

std::vector <Skill*> Hero::skillCanLearn() const {
	std::vector <Skill*> listSkill = this->skillList;
	std::vector <Skill*> heroSkill;

	for (int i = 0; i < listSkill.size(); ++i) {
		Skill* skill = listSkill[i];
		if (this->heroLevel >= skill->get_skillLevel()) {
			heroSkill.push_back(skill);
		}
	}
	return heroSkill;
}

void Hero::deleteSkills(int n) {
	int size = this->skillList.size();
	if (n >= size) {
		for (auto x : this->skillList) {
			delete x;
			x = nullptr;
		}
		this->skillList.clear();
	}

	else {
		Skill* tmp;
		for (int i = 0; i < n; ++i) {
			tmp = this->skillList.back();
			this->skillList.pop_back();
			delete tmp;
			tmp = nullptr;
		}
	}
}

void Hero::printSkillList() const {
	std::cout << "\n==== DANH SACH KY NANG HIEN TAI ====\n";
	int size = this->skillList.size();
	for (int i = 0; i < size; ++i) {
		std::cout << *this->skillList[i] << "\n";
	}
}