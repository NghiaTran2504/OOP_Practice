#pragma once

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string author;
	string name;
	string id;
	string datePublish;
	double price = 0;

public:
	Book() = default;
	Book(string _author, string _name, string _id, string _datePublish, double p = 0) : author(_author), name(_name), id(_id), datePublish(_datePublish), price(p) {}
	~Book() = default;

	string getAuthor() const { return author; }
	string getName() const { return name; }
	string getId() const { return id; }
	string getDatePublish() const { return datePublish; }
	double getPrice() const { return price; }

	bool setPrice(double p) {
		if (p < 0) {
			cout << "INVALID\n";
			return false;
		}
		price = p;
		return true;
	}

	friend istream& operator >> (istream& inDev, Book& obj) {
		cout << "Author: "; 
		getline(inDev >> ws, obj.author);
		cout << "Book name: ";
		getline(inDev >> ws, obj.name);
		cout << "ID: "; 
		inDev >> obj.id;

		double temp;
		do {
			cout << "Price: ";
			inDev >> temp;
		} while (!obj.setPrice(temp));

		return inDev;
	}

	friend ostream& operator << (ostream& outDev, const Book& obj) {
		outDev << "Author: " << obj.author << " | Book name: " << obj.name << " | ID: " << obj.id << " | Price: " << obj.price << "\n";
		return outDev;
	}
};