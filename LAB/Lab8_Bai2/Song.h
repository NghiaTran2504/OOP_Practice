#pragma once

#include <iostream>
#include <string>

using namespace std;

class Song {
protected:
	string name, lyric, singer, genre;
	int yearPublish = 1, currStream = 0;

public:
	Song() = default;
	Song(string _name, string _lyric, string _singer, string _genre, int _year, int _stream) : name(_name), lyric (_lyric), singer(_singer), genre(_genre), yearPublish(_year), currStream(_stream) {}
	virtual ~Song() = default;

	virtual double getPrice() const { return 0; }
	string getName() const { return name; }
	int getStream() const { return currStream; }
	string getGenre() const { return genre; }

	virtual void read(istream& in);
	virtual void print(ostream& out) const;

	friend istream& operator >> (istream& in, Song& s) {
		s.read(in);
		return in;
	}
	friend ostream& operator << (ostream& out, const Song& s) {
		s.print(out);
		return out;
	}
};