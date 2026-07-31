#include "Hero.h"

#include <iostream>

int main() {
	Hero nghia;
	std::cin >> nghia;
	std::cout << nghia;

	int n;
	std::cout << "\nNhap so luong Skill muon cat o cuoi danh sach: ";
	std::cin >> n;
	nghia.deleteSkills(n);
	nghia.printSkillList();
	return 0;
}