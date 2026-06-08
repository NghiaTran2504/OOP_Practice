#include "myString.hpp"

int main() {
	myString s, t;
	std::cout << "String 1: "; std::cin >> s;
	std::cout << "String 2: "; std::cin >> t;
	std::cout << "Length of string 1: " << s.length() << "\n";
	std::cout << "Length of string 2: " << t.length() << "\n";
	std::cout << "Sum of two strings: " << s + " " + t << "\n";

	int pos, len;
	std::cout << "\nSubstring (input 2 integers - position & length of substring):"; std::cin >> pos >> len;
	std::cout << "\n\tYour substring: " << s.subString(pos, len) << "\n\n";

	unsigned char* c = new unsigned char[1000];
	std::cout << "Insertion (input 2 values - position & the string you want to insert): ";
	std::cin >> pos >> c;

	if (s.insert(pos, c)) {
		std::cout << "\n\tAfter insertion: " << s << "\n\n";
	}
	else {
		std::cout << "\n\tInvalid input!\n\n";
	};

	std::cout << "String erase (input 2 integers - position & number of characters you want to erase):"; std::cin >> pos >> len;
	if (s.erase(pos, len)) {
		std::cout << "\n\t After erase: " << s << "\n\n";
	}
	else {
		std::cout << "\n\tInvalid input!\n\n";
	}

	std::cout << "String replacing (input 3 values - position, number of characters you want to replace & string you want to replace): ";
	std::cin >> pos >> len >> c;
	if (s.replace(pos, len, c)) {
		std::cout << "\n\t After replacing: " << s << "\n\n";
	}
	else {
		std::cout << "\n\tInvalid input \n\n";
	}

	std::cout << "Searching in string (input 2 values - position & the string you want to find): ";
	std::cin >> pos >> c;
	std::cout << s.find(pos, c) << "\n";
	return 0;
}